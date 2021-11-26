/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:49:10 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/25 23:25:08 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int		temp;
	t_steps	*new_step = {0};

	temp = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = temp;
	temp = stack_b->index[0];
	stack_b->index[0] = stack_b->index[1];
	stack_b->index[1] = temp;
	steps->next = new_step;
	ft_strlcpy(steps->command, "ss", 2);
	steps = steps->next;
	printf("i\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int		temp;
	int		i;
	t_steps	*new_step = {0};

	i = 0;
	temp = stack_a->index[0];

	while (i < stack_a->size)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[0];
	while (i < stack_b->size)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	steps->command = ft_strdup("rr");
	steps->next = new_step;
	steps = steps->next;
	printf("i\n");
}

void	rr_(t_stack *stack, t_steps *steps, char c)
{
	int		temp;
	int		i;
	t_steps	*new_step = {0};

	i = stack->size;
	temp = stack->index[stack->size - 1];
	while (--i > 0)
		stack->index[i] = stack->index[i - 1];
	stack->index[i] = temp;
	if (c == 'a')
		steps->command = ft_strdup("rra");
	else
		steps->command = ft_strdup("rrb");
	steps->next = new_step;
	steps = steps->next;
	printf("i\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int		temp;
	int		i;
	t_steps	*new_step = {0};

	i = 0;
	temp = stack_a->index[stack_a->size];
	while (i < stack_a->size)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[stack_b->size];
	while (i < stack_b->size)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	steps->command = ft_strdup("rrr");
	steps->next = new_step;
	steps = steps->next;
	printf("i\n");
}
