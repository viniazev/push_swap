/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:48:35 by vinicius          #+#    #+#             */
/*   Updated: 2026/06/27 23:59:17 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// ENUMS

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

	double			disorder;
}					t_bench;

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
int					parse_args(t_ps *ps, int argc, char **argv);
int					is_valid_int(const char *str);
int					has_duplicates(t_stack *a);
long				ft_atol_ps(const char *str);
int					parse_flags(int argc, char **argv, t_ps *ps);
// STACK MANAGEMENT

t_node				*node_new(int value);
void				stack_add_bottom(t_stack *stack, t_node *node);
void				stack_add_top(t_stack *stack, t_node *node);
t_node				*stack_pop_top(t_stack *stack);
void				stack_clear(t_stack *stack);
int					stack_sorted(t_stack *stack);
void				swap_top_two(t_stack *stack);
// INDEXING
void				assign_indices(t_stack *a);

// DISORDER
double				compute_disorder(t_stack *a);

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
// REVERSE ROTATE
void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);

// STRATEGIES
void				simple_sort(t_ps *ps);
void				medium_sort(t_ps *ps);
void				complex_sort(t_ps *ps);
void				adaptative_sort(t_ps *ps);

// SIMPLE STRATEGY
int					find_min_pos(t_stack *a);

// MEDIUM STRATEGY
void				chunk_sort(t_ps *ps);

// COMPLEX STRATEGY
void				radix_sort(t_ps *ps);

// BENCH MODE

void				print_bench(t_ps *ps);

// ERRORS
void				error_exit(t_ps *ps);

// CLEANUP
void				free_all(t_ps *ps);

#endif
