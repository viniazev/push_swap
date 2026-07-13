MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables
# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCFLAG = -I.
AR = ar -rcs
# Files
NAME = libft.a
MAIN = atoi\
	bzero\
	calloc\
	strlen\
	itoa\
	strdup\
	strchr\
	strrchr\
	isalpha\
	isdigit\
	isalnum\
	isascii\
	isprint\
	memset\
	memcpy\
	memmove\
	strlcpy\
	strlcat\
	toupper\
	tolower\
	strncmp\
	memchr\
	memcmp\
	strnstr\
	substr\
	strjoin\
	split\
	strmapi\
	strtrim\
	putchar_fd\
	striteri\
	putstr_fd\
	putendl_fd\
	putnbr_fd
BONUS = lstnew\
	lstadd_front\
	lstsize\
	lstlast\
	lstadd_back\
	lstdelone\
	lstclear\
	lstiter\
	lstmap
# Name fixing
MAINNAMES = $(addprefix ft_,$(addsuffix .c, $(MAIN)))
BNAMES = $(addprefix ft_,$(addsuffix .c, $(BONUS)))
OBJ = $(MAINNAMES:.c=.o)
BOBJ = $(BNAMES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(AR) $@ $^

bonus: $(NAME) $(BOBJ)
	$(AR) $(NAME) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@  

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all

.PHONY: all clean fclean bonus re