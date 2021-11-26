/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:07:49 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/25 22:27:30 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
    if (stack_a->index[0] < stack_a->index[1])
    {
        rr(stack_a, stack_b, steps);
        if (stack_a->index[0] > stack_a->index[1])
            s(stack_a, steps, 'a');
    }
    else
    {
        if (stack_a->index[0] < stack_a->index[2])
            s(stack_a, steps, 'a');
        else
        {
            r(stack_a, steps, 'a');
            if (stack_a->index[0] > stack_a->index[1])
                s(stack_a, steps, 'a');
        }
    }
}

void    five_sort(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
    int		i;

	while (stack_a->size > 2)
	{
		i = 0;
		while (stack_a->index[i] != stack_a->size)
			i++;
		if (i == 0)
			p(stack_a, stack_b, steps, 'b');
		else if (i > stack_a->size / 2)
			rr(stack_a, stack_b, steps);
		else
			r(stack_a, steps, 'a');
	}
	three_sort(stack_a, stack_b, steps);
	while (stack_b->size >= 0)
	{
		p(stack_b, stack_a, steps, 'a');
		r(stack_a, steps, 'a');
	}
}

void    sort_small_stack(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
    if (stack_a->size == 2)
        s(stack_a, steps, 'a');
    if (stack_a->size > 3 && stack_a->size < 6)
        five_sort(stack_a, stack_b, steps);
    else
        three_sort(stack_a, stack_b, steps);
}