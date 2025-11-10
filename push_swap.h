/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:56:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/10 16:43:57 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int						value;
	int						index;
    struct s_stack			*next;
    struct s_stack			*prev;

}	t_stack;

//parse_params
int			is_all_num(int argc, char **argv, int s);
int			check_doubles(int argc, char **argv,int s);
int			check_int_max(int argc, char **argv, int s);
int			is_empty(char *argv);


//stack_manipulation
void		free_stack(t_stack **stack);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_b, t_stack **stack_a);

//stack_utils
t_stack		*return_last_node(t_stack *stack);
int			stack_size(t_stack *stack);
bool		stack_sorted(t_stack *stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	fill_single_arg_stack(int i, char **args, t_stack **stack);
void	fill_mult_args_stack(int i, char **args, t_stack **stack);


//algorithm_utils
void	init_index(t_stack *a);
void	radix_sort(t_stack **a, t_stack **b, int i, int j);

//caller_functions
void		call_rotate(t_stack **stack, char *op);
void		call_swap(t_stack **stack, char *op);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
