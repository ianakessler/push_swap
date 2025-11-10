/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/11/10 16:48:56 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_digit(char	*arg);

int	is_all_num(int argc, char **argv, int s)
{
	int	i;
	int	current_value;

	i = s;
	while (i < argc)
	{
		current_value = ft_atoi(argv[i]);
		if (current_value == 0 && !is_all_digit(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (current_value != 0 && !is_all_digit(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_doubles(int argc, char **argv, int s)
{
	int	i;
	int	j;

	i = s;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_max(int argc, char **argv, int s)
{
	int	i;

	i = s;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_all_digit(char	*arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		if (arg[i + 1] == '\0')
			return (0);
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != 32)
			return (0);
		i++;
	}
	ft_putstr_fd("Error\n", 2);
	return (1);
}
