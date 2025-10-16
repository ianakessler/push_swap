/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:56:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/16 19:20:42 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int				value;
    struct  s_stack	*next;
    struct s_stack	*prev;

}   t_stack;

//parse_params
int is_all_num(int argc, char **argv, int s);
int check_doubles(int argc, char **argv,int s);
int check_int_max(int argc, char **argv, int s);
int	is_ordenated(int argc, char **argv, int s);

//stack_manipulation
t_stack	*create_node(int value);
void	add_node_front(t_stack *node, t_stack **stack);
void	fill_stack(int argc, char	**argv, t_stack **stack, int s);
void	free_stack(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

//stack_utils
t_stack	*return_last_node(t_stack *stack);
int	stack_size(t_stack *stack);

#endif
