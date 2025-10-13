/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:59:03 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 14:44:40 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if (!is_all_num(argc, argv) || !check_doubles(argc, argv) || !check_int_max(argc, argv))
        return (0);
    write(1, "All params ok\n", 15);
}