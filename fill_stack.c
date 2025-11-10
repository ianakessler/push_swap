/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:29:56 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/06 18:28:51 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int number);
static void	add_node_front(t_stack *node, t_stack **stack);

void	fill_mult_args_stack(int i, char **args, t_stack **stack)
{
	t_stack	*node;
	int		current_value;
	int		k;

	k = i - 1;
	while (k >= 1)
	{
		current_value = ft_atoi(args[k]);
		node = create_node(current_value);
		add_node_front(node, stack);
		k--;
	}
}

void	fill_single_arg_stack(int i, char **args, t_stack **stack)
{
	t_stack	*node;
	int		curren_value;
	int		k;

	k = i - 1;
	while (k >= 0)
	{
		curren_value = ft_atoi(args[k]);
		node = create_node(curren_value);
		add_node_front(node, stack);
		k--;
	}
}

static t_stack	*create_node(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = number;
	node->next = NULL;
	node->prev = NULL;
	node->index = -1;
	return (node);
}

static void	add_node_front(t_stack *node, t_stack **stack)
{
	if (!node || !stack)
		return ;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}
