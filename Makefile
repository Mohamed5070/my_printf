SRCS	= ft_printf.c helper_functions.c ft_print_hexa.c ft_put_unsigned_nbr.c count_functions.c ft_putnbr.c ft_putstr_putchar.c
BONUS_SRCS = ft_printf_bonus.c first_flags_bonus.c first_flags_functions_bonus.c second_flags_bonus.c helper_functions.c ft_print_hexa.c ft_put_unsigned_nbr.c count_functions.c ft_putnbr.c ft_putstr_putchar.c
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: _bonus

_bonus:	$(BONUS_OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)
	touch _bonus

clean:
	rm -f $(OBJS) $(BONUS_OBJS) _bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
