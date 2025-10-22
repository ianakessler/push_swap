/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:56:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/22 15:15:49 by iaratang         ###   ########.fr       */
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
int	validate_single_arg(char **splited);

//stack_manipulation
void	fill_stack(int argc, char	**argv, t_stack **stack, int s);
void	free_stack(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_b, t_stack **stack_a);


//stack_utils
t_stack	*return_last_node(t_stack *stack);
int	stack_size(t_stack *stack);

//caller_functions
void	call_rotate(t_stack *stack, char *op);
void	call_swap(t_stack *stack, char *op);

#endif
