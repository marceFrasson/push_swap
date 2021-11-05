/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:43:40 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/05 15:11:50 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_b_smallest_number(t_stack *stack_b)
// {
// 	int i;
// 	int temp;

// 	i = 0;
// 	while (i < stack_b->size)
// 	{
// 		if
// 	}
// }

/*void	first_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int	i;

	i = 0;
	stack_a->step_list = steps;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] < stack_a->markup_head)
			p(stack_a, stack_b, steps, 'b');
		if (stack_a->index[i] >= stack_a->markup_head)
			r(stack_a, steps, 'a');
		i++;
	}
}*/

void	first_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int i;
	int j;
	int flag;

	i = 0;
	stack_a->step_list = steps;
	while (i < stack_a->size)
	{
		flag = 0;
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->index[i] == stack_a->to_keep_in_a[j])
			{
				r(stack_a, steps, 'a');
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			p(stack_a, stack_b, steps, 'b');
		i++;
	}
}


// void	second_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
// {
// 	int	i;
// 	int	x;
// 	int	next_number;

// 	i = 0;
// 	x = stack_b->size / 2;
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
