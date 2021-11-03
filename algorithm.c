/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:43:40 by mfrasson          #+#    #+#             */
/*   Updated: 2021/10/26 11:38:12 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_b_smallest_number(t_stack *stack_b)
// {
// 	int i;
// 	int temp;

// 	i = 0;
// 	while (i < stack_b->n)
// 	{
// 		if
// 	}
// }

void	first_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int	i;

	i = 0;
	stack_a->step_list = steps;
	while (i < stack_a->n)
	{
		if (stack_a->array[i] < stack_a->markup_head)
			p(stack_a, stack_b, steps, 'b');
		if (stack_a->array[i] >= stack_a->markup_head)
			r(stack_a, steps, 'a');
		i++;
	}
}

// void	second_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
// {
// 	int	i;
// 	int	x;
// 	int	next_number;

// 	i = 0;
// 	x = stack_b->n / 2;
// 	next_number = stack_b_smallest_number(stack_b);
// 	while (stack_b->index[i] != next_number)
// 	{
// 		printf("dentro da second move\n");
// 		if (next_number < x)
// 			r(stack_b, steps, 'b');
// 		else
// 			rr_(stack_b, steps, 'b');
// 		i++;
// 	}
// 	p(stack_b, stack_a, steps, 'a');
// }
