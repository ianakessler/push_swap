/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:59:09 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 20:24:57 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_front(t_stack *node, t_stack **stack)
{
	if (!node || !stack)
		return ;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}
