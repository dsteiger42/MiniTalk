#ifndef MINITALK_H
# define MINITALK_H
# define BUFFER_SIZE 1024

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_atob(unsigned char c, int pid);
void	print_error_and_exit(char *message);
void	ft_btoa(int sig);

#endif
