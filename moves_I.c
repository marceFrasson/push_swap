/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:47:14 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/24 21:46:40 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    s(t_stack *stack, t_steps *steps, char c)
{
	int     temp;
	t_steps *new_step = {0};

	temp = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = temp;
	if (c == 'a')
		steps->command = ft_strdup("sa");
	else
		steps->command = ft_strdup("sb");
	steps->next = new_step;
	steps = steps->next;
}

void    r(t_stack *stack, t_steps *steps, char c)
{
	int     temp;
	int     i;
	t_steps *new_step = {0};

	printf("inside rotate\n");
	i = 0;
	printf("stack->index[0] 1 : %i\n", stack->index[0]);
	temp = stack->index[0];
	while (i < stack->size)
	{
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->index[i] = temp;
	if (c == 'a')
		steps->command = ft_strdup("ra");
	else
		steps->command = ft_strdup("rb");
	printf("stack->index[0] 1 : %i\n", stack->index[0]);
	steps->next = new_step;
	steps = steps->next;
}

void    p(t_stack *stack_a, t_stack *stack_b, t_steps *steps, char c)
{
	t_steps *new_step = {0};
	
	printf("inside push\n");
	extend_stack(stack_b);
	printf("stack_a->index[0] 1 : %i\n", stack_a->index[0]);
	stack_b->index[0] = stack_a->index[0];
	reduce_stack(stack_a);
	printf("stack_a->index[0] 2 : %i\n", stack_a->index[0]);
	stack_b->size++;
	stack_a->size--;
	if (c == 'a')
		steps->command = ft_strdup("pa");
	else
		steps->command = ft_strdup("pb");
	steps->next = new_step;
	steps = steps->next;
}
