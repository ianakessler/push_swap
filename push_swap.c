/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/16 19:22:32 by iaratang         ###   ########.fr       */
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
		if(!argv[1][0])
		{
			ft_putstr_fd("Error", 2);
			return (0);
		}
		char	**splited;
		splited = ft_split(argv[1], 32);
		int i = 0;
		while (splited[i])
			i++;
		if (!is_all_num(i, splited, 0) || !check_doubles(i, splited, 0) || !check_int_max(i, splited, 0))
			return (0);
		ft_putstr_fd("All params ok\n", 1);
		if (is_ordenated(i, splited, 0))
			return (0);
		fill_stack(i, splited, &stack_a, 0);
		printf("Display before rotate\n");
		display_list(stack_a);
		reverse_rotate(&stack_a);
		printf("display after rotate\n");
		display_list(stack_a);
		free_stack(&stack_a);
		free(splited);
	}
	else
	{
		if (!is_all_num(argc, argv, 1) || !check_doubles(argc, argv, 1)
			|| !check_int_max(argc, argv, 1))
			return (0);
		ft_putstr_fd("All params ok\n", 1);
		if (is_ordenated(argc, argv, 1))
			return (0);

		fill_stack(argc, argv, &stack_a, 1);
		display_list(stack_a);
		rotate(&stack_a);
		display_list(stack_a);
		free_stack(&stack_a);
	}
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
		printf("\tValor (value):  %i\n", tmp->value);
		printf("\tAponta para (next): %p\n", (void *)tmp->next);
		printf("\tAponta para (prev): %p\n", (void *)tmp->prev);
		printf("--------------------------\n");
		i++;
		tmp = tmp->next;
	}
}
