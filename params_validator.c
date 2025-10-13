/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 12:41:10 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_all_num(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
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
    write(1, "All params validated\n", 22);
    return (1);
}



