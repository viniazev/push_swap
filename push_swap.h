/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:48:35 by vinicius          #+#    #+#             */
/*   Updated: 2026/08/14 02:26:19 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ENUM STRATEGY
typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

// NODES & STACKS
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// ROTATION
typedef enum e_rotation
{
	ROTATE,
	REVERSE_ROTATE
}					t_rotation_type;

typedef struct s_rotation
{
	int				position;
	int				cost;
	t_rotation_type	direction;
}					t_rotation;

typedef struct s_move
{
	t_node			*node;
	t_rotation		a;
	t_rotation		b;
	int				total_cost;
}					t_move;

// BENCHMARK
typedef struct s_bench
{
	long			total;

	long			sa;
	long			sb;
	long			ss;

	long			pa;
	long			pb;

	long			ra;
	long			rb;
	long			rr;

	long			rra;
	long			rrb;
	long			rrr;

	float			disorder;
}					t_bench;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_op;
// STRUCT CHUNK
typedef struct s_chunk
{
	int				start;
	int				end;
	int				size;
}					t_chunk;

// PROGRAM CONTEXT
typedef struct s_ps
{
	t_stack			a;
	t_stack			b;

	t_strategy		strategy;
	int				bench_mode;

	t_bench			bench;
}					t_ps;

// PARSING
int					parse_args(int argc, char **argv, t_ps *ps);
int					is_valid_int(const char *str);
int					has_duplicates(t_stack *a);
long				ft_atol_ps(const char *str);
int					parse_flags(int argc, char **argv, t_ps *ps);
// STACK MANAGEMENT

t_node				*node_new(int value);
void				stack_add_bottom(t_stack *stack, t_node *node);
void				stack_add_top(t_stack *stack, t_node *node);
t_node				*stack_pop_top(t_stack *stack);
t_node				*stack_pop_bottom(t_stack *stack);
void				stack_clear(t_stack *stack);
int					stack_is_sorted(t_stack *stack);
void				swap_top_two(t_stack *stack);
void				bring_index_to_top(t_ps *ps, t_stack *stack,
						int target_index);
void				stack_init(t_ps *ps);
// INDEXING
void				assign_indices(t_stack *a);

// DISORDER
float				compute_disorder(t_stack *a);

// OPERATIONS
// SWAP
void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);
// PUSH
void				pa(t_ps *ps);
void				pb(t_ps *ps);
// ROTATE
void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);
void				rotate_stack(t_ps *ps, t_stack *stack);
// REVERSE ROTATE
void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);
void				reverse_rotate_stack(t_ps *ps, t_stack *stack);

// STRATEGIES
void				small_sort(t_ps *ps);
void				simple_sort(t_ps *ps);
void				medium_sort(t_ps *ps);
void				complex_sort(t_ps *ps);
void				adaptative_sort(t_ps *ps);

// SMALL SORT
void				sort_five(t_ps *ps);
void				sort_four(t_ps *ps);
void				sort_three(t_ps *ps);
void				sort_two(t_ps *ps);
// SIMPLE STRATEGY
int					find_insert_position(t_stack *stack, int target);
int					find_position(t_stack *stack, int index);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
t_move				find_cheapest_node(t_ps *ps);
t_move				move_cost(t_ps *ps, t_node *node);
t_rotation			get_rotation_cost(t_stack *stack, int position);
void				execute_rotation(t_ps *ps, t_move move);
void				rotate_or_reverse(t_ps *ps, t_move move);
void				rotate_to_position(t_ps *ps, t_stack *stack, int position);
// MEDIUM STRATEGY
void				chunk_sort(t_ps *ps, t_chunk *chunk);
int					ft_sqrt(int nb);
t_move				find_cheapest_in_chunk(t_ps *ps, t_chunk chunk);
int					ft_max_number(int a, int b);
t_move				chunk_move_cost(t_ps *ps, t_node *node, t_chunk chunk);
void				execute_rotation_a(t_ps *ps, t_stack *stack,
						t_rotation rotation);
int					find_max_in_chunk(t_stack *stack, int start, int end);
// COMPLEX STRATEGY
void				radix_sort(t_ps *ps);

// BENCH MODE

void				print_bench(t_ps *ps);
void				update_bench(t_ps *ps, t_op op);
// ERRORS
int					error_exit(t_ps *ps);

// CLEANUP
void				free_all(t_ps *ps);
void				print_stack(t_ps *ps, t_stack stack);
#endif
