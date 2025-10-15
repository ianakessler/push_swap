/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:31 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/15 18:26:47 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*return_last_node(t_stack *stack)
{
	t_stack	*tmp;
	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp)
		tmp = tmp->next;
	return (tmp);
}
