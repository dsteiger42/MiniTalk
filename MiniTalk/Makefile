NAMEC = client
NAMES = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_client = client.c
SRCS_server = server.c

COMPRESS = ar rcs

RM = rm -f

OBJS_client = $(SRCS_client:.c=.o)
OBJS_server = $(SRCS_server:.c=.o)

FT_PRINTFDIR = ./ft_printf
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAMEC) $(NAMES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAMEC): $(OBJS_client) $(FT_PRINTF) $(LIBFT)
	@$(CC) $(OBJS_client) $(FT_PRINTF) $(LIBFT) -o $(NAMEC)

$(NAMES): $(OBJS_server) $(FT_PRINTF)
	@$(CC) $(OBJS_server) $(FT_PRINTF) $(LIBFT) -o $(NAMES)

$(FT_PRINTF):
	@make -C $(FT_PRINTFDIR)

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	@$(RM) $(OBJS_client) $(OBJS_server)

fclean: clean
	@$(RM) $(NAMEC) $(NAMES) $(FT_PRINTF) $(LIBFT)
	@make -C $(FT_PRINTFDIR) fclean
	@make -C $(LIBFTDIR) fclean

re: fclean all
