#include "minitalk.h"

static void	print_message(unsigned char *buffer, size_t size)
{
	buffer[size] = '\0';
	ft_printf("Received message: %s\n", buffer);
	free(buffer);
	buffer = NULL; // reset buffer pointer
}

void	print_error_and_exit2(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}


void	ft_btoa(int sig, siginfo_t *siginfo, void *context)
{
	static t_buffer	buf = {NULL, 0, 8, 0, 0}; // Start with an initial capacity of 8
	size_t			new_capacity;
	unsigned char	*new_buffer;
	size_t			i;

	(void)siginfo;
	(void)context;

	// Allocate initial buffer if it doesn't exist
	if (buf.buffer == NULL)
	{
		buf.buffer = (unsigned char *)malloc(buf.capacity);
		if (!buf.buffer)
			return ;
	}

	if (sig == SIGUSR1)
		buf.byte |= (0x01 << buf.bit);
	buf.bit++;
	
	if (buf.bit == 8) // When we've received a full byte
	{
		if (buf.byte == '\0') // End of message
		{
			print_message(buf.buffer, buf.size);
			free(buf.buffer); // Free buffer after printing
			buf.buffer = NULL; // Reset buffer to allow new allocation on next message
			buf.size = 0;
			buf.capacity = 8; // Reset capacity for the next message
		}
		else
		{
			// Resize buffer if necessary
			if (buf.size == buf.capacity)
			{
				new_capacity = buf.capacity * 2;
				new_buffer = (unsigned char *)malloc(new_capacity);
				if (!new_buffer)
				{
					free(buf.buffer);
					buf.buffer = NULL;
					return ;
				}
				for (i = 0; i < buf.size; i++) // Copy old data
					new_buffer[i] = buf.buffer[i];
				free(buf.buffer);
				buf.buffer = new_buffer;
				buf.capacity = new_capacity;
			}
			// Add byte to buffer
			buf.buffer[buf.size++] = buf.byte;
		}
		// Reset bit and byte for the next character
		buf.bit = 0;
		buf.byte = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = ft_btoa;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error_and_exit2("Error setting SIGUSR1 handler");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error_and_exit2("Error setting SIGUSR2 handler");
	while (1)
		pause();
	return (0);
}
