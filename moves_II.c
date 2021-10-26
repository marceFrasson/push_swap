/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:49:10 by mfrasson          #+#    #+#             */
/*   Updated: 2021/10/18 00:36:09 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int		temp;
	t_steps	*new_step;

	temp = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = temp;
	temp = stack_b->index[0];
	stack_b->index[0] = stack_b->index[1];
	stack_b->index[1] = temp;
	steps->next = new_step;
	ft_strlcpy(steps->command, "ss", 2);
	steps = steps->next;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_steps *steps)
{
	int		temp;
	int		i;
	t_steps	*new_step;

	i = 0;
	temp = stack_a->index[0];
	while (i < stack_a->n)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[0];
	while (i < stack_b->n)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	steps->command = ft_strdup("rr");
	steps->next = new_step;
	steps = steps->next;
}

void	rr_(t_stack *stack, t_steps *steps, char c)
{
	int		temp;
	int		i;
	t_steps	*new_step;

	i = 0;
	temp = stack->index[stack->n];
	while (i < stack->n)
	{
		stack->index[stack->n - i] = stack->index[stack->n - i - 1];
		i++;
	}
	stack->index[i] = temp;
	if (c == 'a')
		steps->command = ft_strdup("rra");
	else
		steps->command = ft_strdup("rrb");
	steps->next = new_step;
	steps = steps->next;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_steps *steps, char c)
{
	int		temp;
	int		i;
	t_steps	*new_step;

	i = 0;
	temp = stack_a->index[stack_a->n];
	while (i < stack_a->n)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[stack_b->n];
	while (i < stack_b->n)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	steps->command = ft_strdup("rrr");
	steps->next = new_step;
	steps = steps->next;
}
