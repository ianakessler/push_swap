/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/04 20:21:45 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_stack **stack);
int	validate_single_arg(char **splited);
int	validate_mult_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**splited;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		splited = ft_split(argv[1], 32);
		i = validate_single_arg(splited);
		if (i == 0)
			return (0);
		fill_stack(i, splited, &stack_a, 0);
		free_stack(&stack_a);
	}
	else
	{
		i = validate_mult_args(argc, argv);
		if (i == 0)
			return (0);
		fill_stack(argc, argv, &stack_a, 1);
		init_index(stack_a);
		radix_sort(&stack_a, &stack_b, 0, 0);
		free_stack(&stack_a);
	}
}



int	validate_single_arg(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		i++;
	if (!is_all_num(i, splited, 0) || !check_doubles(i, splited, 0)
		|| !check_int_max(i, splited, 0))
		return (0);
	if (is_ordenated(i, splited, 0))
		return (0);
	return (i);
}

int	validate_mult_args(int argc, char **argv)
{
	if (!is_all_num(argc, argv, 1) || !check_doubles(argc, argv, 1)
		|| !check_int_max(argc, argv, 1))
		return (0);

	if (is_ordenated(argc, argv, 1))
		return (0);
	return (1);
}

void	display_list(t_stack **stack)
{
	int i = 0;
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		printf("Nó %d:\n", i);
		printf("\tEndereço do nó: %p\n", (void *)tmp);
		printf("\tValor (value):  %i\n", tmp->value);
		printf("\tIndex: %i\n", tmp->index);
		printf("\tAponta para (next): %p\n", (void *)tmp->next);
		printf("\tAponta para (prev): %p\n", (void *)tmp->prev);
		printf("--------------------------\n");
		i++;
		tmp = tmp->next;
	}
}
