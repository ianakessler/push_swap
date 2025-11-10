/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:42:24 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/10 17:44:36 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_three(t_stack **stack);
static int		find_min_pos(t_stack *a);
static void		sort_short_stack(t_stack **a, t_stack **b);

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (stack_sorted(*stack_a))
		return ;
	if (size == 2)
		call_swap(stack_a, "sa");
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_short_stack(stack_a, stack_b);
	else
	{
		init_index(*stack_a);
		radix_sort(stack_a, stack_b, 0, 0);
	}
}

static void	sort_three(t_stack **stack)
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

static void	sort_short_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos <= size / 2)
			while (min_pos--)
				call_rotate(a, "ra");
		else
		{
			min_pos = size - min_pos;
			while (min_pos--)
				call_rotate(a, "rra");
		}
		push_b(b, a);
		size--;
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}

static int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	int		min_val;

	tmp = a;
	min_val = tmp->value;
	min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}
