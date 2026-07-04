CC = cc
CFLAGS = -Wall -Wextra -Werror
INCFLAG = -I .
AR = ar
ARFLAGS = -rcs
RM = rm -f

NAME = libftprintf.a

FILES = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_puthex.c \
		ft_putptr.c \
		ft_putunsigned.c \
		handlers.c \
		parser.c

OBJ = $(FILES:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ): $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re