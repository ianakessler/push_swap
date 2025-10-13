/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:29:56 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 20:53:11 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int argc, char	**argv, t_stack **stack)
{
	int		i;
	t_stack	*node;

	i = 1;
	while (i < argc)
	{
		node = create_node(ft_atoi(argv[i]));
		add_node_front(node, stack);
		i++;
		free(node);
	}
}
