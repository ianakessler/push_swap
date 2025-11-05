/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:33:27 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/04 19:40:53 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min_node(t_stack *a);
static t_stack	*find_no_index_node(t_stack *a);

void	init_index(t_stack *a)
{
	int		size;
	int		current_index;
	t_stack	*node_to_index;

	if (!a)
		return ;
	size = stack_size(a);
	current_index = 0;
	while (current_index < size)
	{
		node_to_index = find_min_node(a);
		if (node_to_index)
			node_to_index->index = current_index;
		current_index++;
	}
}

static t_stack	*find_min_node(t_stack *a)
{
	t_stack *min_node;
	t_stack *current;

	min_node = find_no_index_node(a);
	if (!min_node)
		return (NULL);
	current = a;
	while (current)
	{
		if (current->index == -1 && current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

static t_stack	*find_no_index_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->index == -1)
			return (a);
		a = a->next;
	}
	return (NULL);
}
