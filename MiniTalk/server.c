#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	ft_btoa(int sig)
{
	static int	bit;
	static int	byte;

    byte = 0;
    bit = 0;
	if (sig == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		bit = 0;    // reseted for the next character/byte
		byte = 0;
	}
}

int main(int argc, char **argv)
{
    int pid;
    
    (void)argv;
    if (argc != 1)
    {
        ft_printf("Error\n");
        return (1);
    }
    pid = getpid();
    ft_printf("%d\n", pid);
    while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause ();
	}
	return (0);
}