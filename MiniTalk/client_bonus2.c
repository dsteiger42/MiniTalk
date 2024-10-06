#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// cast argv to unsigned char talvez funcione para o bonus

// Function to convert a string to integer (same as in the original ft_atoi)
static int	ft_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	unsigned long int result = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// Signal handler for acknowledgment from server
void	acknowledgment_handler(int sig)
{
	(void)sig;
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client_bonus <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, acknowledgment_handler);  // Wait for acknowledgment from server
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_atob(pid, argv[2][i]);
		pause();  // Wait for acknowledgment after each byte
		i++;
	}
	return (0);
}
