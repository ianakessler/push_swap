/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:18:46 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/20 18:50:56 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_b;


	if(!stack_b || (*stack_b))
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	*stack_a = first_b;
	first_b->next = *stack_a;
	if (second_b)
		second_b->prev = NULL;

}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	b->prev = a;
	*stack_a = a->next;
	(*stack_a)->prev = NULL;
}

