/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:29:56 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/14 18:22:07 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int argc, char	**argv, t_stack **stack)
{
	int		i;
	int		current_value;
	t_stack	*node;

	i = 1;
	while (i < argc)
	{
		current_value = ft_atoi(argv[i]);
		node = create_node(current_value);
		add_node_front(node, stack);
		i++;
	}
}
