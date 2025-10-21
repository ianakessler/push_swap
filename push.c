/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:18:46 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/21 18:09:50 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b, char *op)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if(!stack_b || (*stack_b))
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	second_b = first_b->next;
	*stack_a = first_b;
	first_b->next = first_a;
	first_b->prev = NULL;
	first_a->prev = first_b;
	*stack_b = second_b;
	if (second_b)
		second_b->prev = NULL;
	ft_putstr_fd(op, 1);
}



