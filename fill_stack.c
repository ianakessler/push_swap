/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:29:56 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/22 14:17:44 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_front(t_stack *node, t_stack **stack);
t_stack	*create_node(int number);

void	fill_stack(int argc, char	**argv, t_stack **stack, int s)
{
	int		i;
	int		current_value;
	t_stack	*node;

	if (s == 0)
	{
		i = argc -1;
	}
	if (s == 1)
	{
		i = argc -1;
		s--;
	}
	while (i > s)
	{
		current_value = ft_atoi(argv[i]);
		node = create_node(current_value);
		add_node_front(node, stack);
		i--;
	}

}

t_stack	*create_node(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = number;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node_front(t_stack *node, t_stack **stack)
{
	if (!node || !stack)
		return ;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}
