/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:56:49 by iaratang          #+#    #+#             */
/*   Updated: 2025/10/13 14:42:51 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int value;
    struct  s_stack *next;
    struct s_stack  *prev;
    
}   t_stack;

int is_all_num(int argc, char **argv);
int check_doubles(int argc, char **argv);
int check_int_max(int argc, char **argv);

#endif