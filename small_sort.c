/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:07:49 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/26 01:25:30 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (check_if_sorted(stack_a))
        return ;
	if (stack_a->index[0] < stack_a->index[1])
	{
		rr_(stack_a, 'a');
		if (stack_a->index[0] > stack_a->index[1])
			s(stack_a, 'a');
	}
	else
	{
		if (stack_a->index[0] < stack_a->index[2])
			s(stack_a, 'a');
		else
		{
			r(stack_a, 'a');
			if (stack_a->index[0] > stack_a->index[1])
				s(stack_a, 'a');
		}
	}
}

void    five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int smalles_number;

	smalles_number = 1;
	while (stack_a->size > 3)
	{
		i = 0;
		while (stack_a->index[i] != smalles_number)
			i++;
		if (i != 0)
		{
			if (i > stack_a->size / 2)
				while (stack_a->index[0] != smalles_number)
					rr_(stack_a, 'a');
			else
				while (stack_a->index[0] != smalles_number)
					r(stack_a, 'a');
		}
		p(stack_a, stack_b, 'b');
		smalles_number++;
	}
	three_sort(stack_a, stack_b);
	while (stack_b->size > 0)
		p(stack_b, stack_a, 'a');
}

void    sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		s(stack_a, 'a');
	if (stack_a->size > 3 && stack_a->size < 6)
		five_sort(stack_a, stack_b);
	else
		three_sort(stack_a, stack_b);
}