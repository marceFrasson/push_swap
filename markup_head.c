/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:54:01 by mfrasson          #+#    #+#             */
/*   Updated: 2021/10/26 10:54:11 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_to_keep_in_a(t_stack *stack_a, int *to_keep, int count)
{
	int i;

	i = 0;
	ft_bzero(stack_a->to_keep_in_a);
	while (i < count)
		stack_a->to_keep_in_a[i] = to_keep[i];
}

void	choose_head(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int i;
	int j;
	int previous;
	int temp_head;
	int temp_head_count;
	int *to_keep_in_a;

	i = 0;
	j = 0;
	temp_head_count = 0;
	while (i++ < stack_a->n)
	{
		while (j++ < stack_a->n)
		{
			if (stack_a->index[i + j] > previous)
			{
				previous = stack_a->index[i + j];
				stack_a->keep_in_a_count++;
				to_keep_in_a[j] = stack_a->index[i + j];
			}
		}
		if (temp_head_count < stack_a->keep_in_a_count)
		{
			temp_head_count = stack_a->keep_in_a_count;
			temp_head = stack_a->index[i];
			copy_to_keep_in_a(stack_a, to_keep_in_a, stack_a->keep_in_a_count);
		}
		stack_a->keep_in_a_count = 0;
		ft_bzero(to_keep_in_a);
	}
	stack_a->markup_head = temp_head;
}
