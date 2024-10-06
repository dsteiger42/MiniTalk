#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_btoa(int sig)
{
	static int	bit = 0;
	static int	byte = 0;

	if (sig == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)  // Full byte received
	{
		ft_printf("%c", byte);
		bit = 0;
		byte = 0;
	}
}

void	send_acknowledgment(int client_pid)
{
	kill(client_pid, SIGUSR1);  // Acknowledge that byte has been received
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);

	while (1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();  // Wait for signal

		// After receiving the byte, send acknowledgment
		send_acknowledgment(pid);
	}
	return (0);
}
