#include "minitalk.h"

void	print_error_and_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	ft_atob(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	if (pid < 1 || kill(pid, 0) == -1)
		print_error_and_exit("wrong pid\n");
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int				pid;
	unsigned char	*message;
	int				i;

	i = 0;
	if (argc != 3)
	{
		print_error_and_exit("Error: Need a PID and a message\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = (unsigned char *)argv[2];
	while (message[i])
	{
		ft_atob(message[i], pid);
		i++;
	}
	ft_atob('\n', pid);
	ft_atob(0x00, pid);
	return (0);
}

