/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:25:02 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/21 16:44:51 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*tmp;

	last_node = return_last_node(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*tmp;

	last_node = return_last_node(*stack);
	tmp = last_node->prev;
	tmp->next = NULL;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	last_node->next = *stack;
	*stack = last_node;
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(&stack_a);
	rotate(&stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(&stack_a);
	reverse_rotate(&stack_b);
	ft_putstr_fd("rrr", 1);
}

void	call_rotate(t_stack *stack, char *op)
{
	if (!ft_strncmp("ra", op, 2))
	{
		rotate(&stack);
		ft_putstr_fd("ra\n", 1);
	}
	if (!ft_strncmp("rra", op, 2))
	{
		reverse_rotate(&stack);
		ft_putstr_fd("rra\n", 1);
	}
}
