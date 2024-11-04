#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <stdlib.h>

typedef struct s_buffer
{
    unsigned char	*buffer;	// Pointer to the data buffer
    size_t size;				// Current size of the buffer (number of bytes used)
	size_t capacity;			// total capacity of the buffer
    int bit;					// Current bit position
    int byte;					// Current byte value
}					t_buffer;

void	print_error_and_exit(char *message);
void	ft_atob(unsigned char c, int pid);
void	print_error_and_exit2(char *message);
void	ft_btoa(int sig, siginfo_t *siginfo, void *context);

#endif
