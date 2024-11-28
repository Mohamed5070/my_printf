SRCS	= ft_printf.c helper_functions.c ft_print_hexa.c ft_put_unsigned_nbr.c ft_putchar.c ft_putnbr.c ft_putstr.c
BONUS_SRCS = ft_printf_bonus.c helper_functions.c ft_print_hexa.c ft_put_unsigned_nbr.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

all: $(NAME)

%.o: %.c ft_printf.h ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean