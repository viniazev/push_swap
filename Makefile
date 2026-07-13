NAME = push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = -Iincs -Ilibft -Ift_printf

LIBFT = libft/libft.a

FT_PRINTF = printf/libftprintf.a

SRCS = 	benchmark/print_bench.c disorder/compute_disorder.c indexing/assign_indexes.c \
		operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c \
		parsing/ft_atol_ps.c parsing/parse_args.c parsing/parse_flags.c parsing/validation.c \
		sorting/adaptive_sort.c sorting/complex_sort.c sorting/medium_sort.c sorting/small_sort.c \
		sorting/sort_utils.c stack/node.c stack/stack_add.c stack/stack_clear.c stack/stack_pop.c \
		utils/error.c utils/free.c main.c 

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(FT_PRINTF):
	$(MAKE) -C printf/

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C printf/ clean
	rm -fr $(OBJS)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(MAKE) -C printf/ fclean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re