/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:42:24 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/30 18:48:39 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	sort_three(t_stack **stack);

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_b(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_cheap(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both_cheap(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*a)->target_node, 'a');
	push_a(a, b);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min_value(*a)->value)
	{
		if (find_min_value(*a)->above_median)
		{
			call_rotate(a, "ra");
		}
		else
			call_rotate(a, "rra");
	}
}

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
