/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:42:18 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/10 14:52:18 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index);

void	radix_sort(t_stack **a, t_stack **b, int i, int j)
{
	int		size;
	int		max_index;
	int		max_bits;
	t_stack	*top_node;

	size = stack_size(*a);
	max_index = size - 1;
	max_bits = get_max_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			top_node = *a;
			if (((top_node->index >> i) & 1) == 0)
				push_b(b, a);
			else
				call_rotate(a, "ra");
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
