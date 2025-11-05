/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:31 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/30 19:36:22 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*return_last_node(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	stack_size(t_stack *stack)
{
	int		i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_max_value(t_stack *stack)
{
	int			max;
	t_stack		*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	max_node = stack;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min_value(t_stack *stack)
{
	int			min;
	t_stack		*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	min_node = stack;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
