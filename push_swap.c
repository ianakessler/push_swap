/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/10 16:51:25 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_stack **stack);
static int	validate_mult_arg(int	argc,char	**argv, t_stack **stack);
static int	validate_single_arg(char **argv, t_stack **stack);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (!argv[1] || is_empty(argv[1]))
		return (0);
	if (argc == 2)
	{
		i = validate_single_arg(argv, &stack_a);
		if (!i)
			return (0);
		sort_stack(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
	if (argc > 2)
	{
		i = validate_mult_arg(argc, argv, &stack_a);
		if (!i)
			return (0);
		sort_stack(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
}

static int	validate_single_arg(char **argv, t_stack **stack)
{
	char	**splited;
	int		i;

	i = 0;
	splited = ft_split(argv[1], 32);
	while (splited[i])
		i++;
	if (!is_all_num(i, splited, 0) || !check_doubles(i, splited, 0)
		|| !check_int_max(i, splited, 0) || is_empty(argv[1]))
		return (0);
	fill_single_arg_stack(i, splited, stack);
	i = 0;
	while(splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (1);
}

static int	validate_mult_arg(int	argc,char	**argv, t_stack **stack)
{
	if (!is_all_num(argc, argv, 1) || !check_doubles(argc, argv, 1)
		|| !check_int_max(argc, argv, 1))
		return (0);
	fill_mult_args_stack(argc, argv, stack);
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
