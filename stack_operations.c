/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:25:02 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/16 18:38:54 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack)
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

void	reverse_rotate_a(t_stack **stack)
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
