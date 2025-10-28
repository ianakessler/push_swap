/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/28 16:10:15 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    display_list(t_stack **stack);
void	teste(t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		char	**splited;
		int i;

		splited = ft_split(argv[1], 32);
		i = validate_single_arg(splited);
		if (i == 0)
			return (0);
		fill_stack(i, splited, &stack_a, 0);
		free_stack(&stack_a);
	}
	else
	{
		fill_stack(argc, argv, &stack_a, 1);
		display_list(&stack_a);
		printf("-----------------------\n");
		teste(stack_a, stack_b);
		free_stack(&stack_a);
	}
}

void	teste(t_stack *stack_a, t_stack *stack_b)
{
	push_b(&stack_b, &stack_a);
	push_b(&stack_b, &stack_a);
	// call_swap(&stack_b, "sb");
	is_stack_sorted(stack_b);
	display_list(&stack_b);
}


int	validate_single_arg(char **splited)
{
	int	i;
	i = 0;
	while (splited[i])
		i++;
	if (!is_all_num(i, splited, 0) || !check_doubles(i, splited, 0) || !check_int_max(i, splited, 0))
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

void    display_list(t_stack **stack)
{
	int i = 0;
	t_stack	*tmp;

	tmp = (*stack);
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
