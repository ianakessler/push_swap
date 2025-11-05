/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:25:02 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/30 20:23:01 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	t_stack	*last_node;
	t_stack	*first_node;

	last_node = return_last_node(*stack);
	first_node = *stack;
	*stack = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	first_node->prev = last_node;
	(*stack)->prev = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
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

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

void	call_rotate(t_stack **stack, char *op)
{
	if (!ft_strncmp(op, "rra", 4))
	{
		reverse_rotate(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else if (!ft_strncmp(op, "ra", 3))
	{
		rotate(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else if (!ft_strncmp(op, "rrb", 4))
	{
		reverse_rotate(stack);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (!ft_strncmp(op, "rb", 3))
	{
		rotate(stack);
		ft_putstr_fd("rb\n", 1);
	}
}
