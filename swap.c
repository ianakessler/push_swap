/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:27:07 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/21 18:12:26 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack || !(*stack)->next || !stack)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	*stack = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
	third->prev = first;
}

void	call_swap(t_stack *stack, char *op)
{
	if (!ft_strncmp("sa", op, 2))
	{
		swap(&stack);
		ft_putstr_fd("sa\n", 1);
	}
	if (!ft_strncmp("sb", op, 2))
	{
		swap(&stack);
		ft_putstr_fd("sb\n", 1);
	}
}
