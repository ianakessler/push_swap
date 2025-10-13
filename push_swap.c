/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 20:54:23 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    display_list(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 2) //TODO: tratar single argument direito;
	{
		argv = ft_split(argv[1], 32);
	}

	if (!is_all_num(argc, argv) || !check_doubles(argc, argv)
		|| !check_int_max(argc, argv))
		return (0);
	write(1, "All params ok\n", 15);
	if (is_ordenated(argc, argv))
	{
		ft_putstr_fd("Sorted", 2);
		return (0);
	}
	fill_stack(argc, argv, &stack_a);
	display_list(stack_a);
}

void    display_list(t_stack *stack)
{
	int i = 0;
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("Nó %d:\n", i);
		printf("\tEndereço do nó: %p\n", (void *)tmp);
		printf("\tValor (value):  %d\n", tmp->value);
		printf("\tAponta para (next): %p\n", (void *)tmp->next);
		printf("\tAponta para (prev): %p\n", (void *)tmp->prev);
		printf("--------------------------\n");
		tmp = tmp->next;
	}
}
