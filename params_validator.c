/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:58 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/10 17:24:04 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_all_num(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!ft_isdigit(argv[i][0]))
        {
            write(1, "Error\n", 6);
            return (0);
        }
        i++;
    }
    write(1, "All params validated\n", 22);
    return (1);
}

