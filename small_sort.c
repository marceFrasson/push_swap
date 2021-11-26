/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:07:49 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/25 23:42:30 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	if (check_if_sorted(stack_a))
        return ;
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
	int little_numbe;

	little_numbe = 1;
	while (stack_a->size > 3)
	{
		i = 0;
		while (stack_a->index[i] != little_numbe)
			i++;
		if (i != 0)
		{
			if (i > stack_a->size)
				while (stack_a->index[0] != little_numbe)
					rr_(stack_a, steps, 'a');
			else
				while (stack_a->index[0] != little_numbe)
					r(stack_a, steps, 'a');
		}
		p(stack_a, stack_b, steps, 'b');
		little_numbe++;
	}
	while (stack_b->size > 0)
		p(stack_b, stack_a, steps, 'a');
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