/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 14:44:32 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_all_num(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    write(1, "is all numbers:\t", 17);
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]))
                j++;
            else if (argv[i][j] == '-')
                j++;
            else 
            {
                write(1, "Error\n", 7);
                return (0);
            }
        }
        i++;
    }
    write(1, "All params are numbers\n", 24);
    return (1);
}

int check_doubles(int argc, char **argv)
{
    int i; 
    int j;
    
    i = 1;
    write(1, "check doubles:\t", 16);
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                write(1, "Error\n", 7);
                return (0);
            }
            j++;
        }
        i++;
    }
    write(1, "No duplicates\n", 15);
    return (1);
}

int check_int_max(int argc, char **argv)
{
    int i;
    
    i = 1;
    write(1, "Check values:\t", 15);
    while (i < argc)
    {
        if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
        {
            write(1, "Error\n", 7);
            return (0);
        }
        i++;
    }
    write(1, "All values ok\n", 15);
    return (1);
}
