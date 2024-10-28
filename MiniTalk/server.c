#include "minitalk.h"

void	ft_btoa(int sig)
{
	static unsigned char	buffer[BUFFER_SIZE];
	static size_t			size = 0;
	static int				bit = 0;
	static int				byte = 0;

	if (sig == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\0')
		{
			buffer[size] = '\0';
			ft_printf("Received message: %s\n", buffer);
			size = 0;
		}
		else
		{
			if (size < BUFFER_SIZE - 1) // reserve space for the '\0'
			{
				buffer[size] = byte; // store the byte in the buffer
				(size)++;
			}
		}
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);
	while (1)
		pause();
	return (0);
}
