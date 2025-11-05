/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:18:46 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/30 19:56:27 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Pega o primeiro elemento no topo de b e o coloca no topo de a.
// Não faz nada se b estiver vazia
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*old_first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (!stack_b || !(*stack_b))
		return ;
	first_b = *stack_b;
	second_b = first_b->next;
	*stack_b = second_b;
	if (second_b)
		second_b->prev = NULL;
	old_first_a = *stack_a;
	first_b->next = *stack_a;
	*stack_a = first_b;
	if(old_first_a)
		old_first_a->prev = first_b;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*old_first_b;
	t_stack	*first_a;
	t_stack	*second_a;

	if (!stack_a || !(*stack_a))
		return ;
	first_a = *stack_a;
	second_a = first_a->next;
	*stack_a = second_a;
	if (second_a)
		second_a->prev = NULL;
	old_first_b = *stack_b;
	first_a->next = *stack_b;
	*stack_b = first_a;
	if (old_first_b)
		old_first_b->prev = first_a;
	ft_putstr_fd("pb\n", 1);
}
