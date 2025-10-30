/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:56:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/30 18:30:15 by iaratang         ###   ########.fr       */
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
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack			*target_node;
    struct s_stack			*next;
    struct s_stack			*prev;

}	t_stack;

//parse_params
int			is_all_num(int argc, char **argv, int s);
int			check_doubles(int argc, char **argv,int s);
int			check_int_max(int argc, char **argv, int s);
int			is_ordenated(int argc, char **argv, int s);

//stack_manipulation
void		fill_stack(int argc, char	**argv, t_stack **stack, int s);
void		free_stack(t_stack **stack);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_b, t_stack **stack_a);

//stack_utils
t_stack		*return_last_node(t_stack *stack);
int			stack_size(t_stack *stack);
bool		stack_sorted(t_stack *stack);
t_stack		*find_max_value(t_stack *stack);
t_stack		*find_min_value(t_stack *stack);
t_stack		*get_cheapest(t_stack *stack);
void		rotate_both_cheap(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		reverse_rotate_both_cheap(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void		init_nodes_a(t_stack *a, t_stack *b);
void		init_nodes_b(t_stack *a, t_stack *b);
void		sort_three(t_stack **stack);



//algorithm_utils
void		current_index(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);


//caller_functions
void		call_rotate(t_stack **stack, char *op);
void		call_swap(t_stack **stack, char *op);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);

//sorting
void		sort_short_stack(t_stack **stack, int size);

#endif
