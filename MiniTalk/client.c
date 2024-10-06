#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

void ft_atob(int pid, char c)
{
    int bit;

    bit = 0;
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

int main(int argc, char **argv)
{
    int i;
    int pid;

    i = 0;
    if (argc == 3)
    {
            pid = atoi(argv[1]);
            while (argv[2][i])
                ft_atob(pid, argv[2][i]);
                i++;
    }
    else
    {
        ft_printf("Error\n");
        return(1);
    }
    return (0);
}
