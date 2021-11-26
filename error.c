/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:25:22 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/26 00:02:17 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_message(int error)
{
    if (error == 1)
        printf("too few arguments\n");
    if (error == 2)
        printf("array must contain only integers\n");
    if (error == 3)
        printf("stack already sorted\n");
    if (error == 4)
        printf("repeated number\n");
}