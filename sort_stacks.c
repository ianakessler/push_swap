/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:42:24 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/04 17:56:48 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		call_swap(stack, "sa");
	if (first > second && second < third && first > third)
		call_rotate(stack, "ra");
	if (first < second && second > third && first < third)
	{
		call_swap(stack, "sa");
		call_rotate(stack, "ra");
	}
	if (first < second && second > third && first > third)
		call_rotate(stack, "rra");
	if (first > second && second > third)
	{
		call_swap(stack, "sa");
		call_rotate(stack, "rra");
	}

}
