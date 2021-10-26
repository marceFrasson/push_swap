/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:50:29 by mfrasson          #+#    #+#             */
/*   Updated: 2021/10/13 17:51:05 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extend_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->n > i)
	{
		stack->index[stack->n - i + 1] =  stack->index[stack->n - i];
		i++;
	}
}

void	reduce_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->n)
	{
		stack->index[i] = stack->index[i + 1];
		i++;
	}
}

void	refactor_steps(t_steps *steps)
{
	char	*temp;
	t_steps	*stemp;

	stemp = steps;
	steps = steps->next;
	ft_strlcpy(temp, steps->command, 3);
	steps = stemp;
	if ((ft_strncmp(temp, "sa", 2) && ft_strncmp(steps->command, "sb", 2)) ||
		(ft_strncmp(temp, "sb", 2) && ft_strncmp(steps->command, "sa", 2)))
		substitute_command(steps, "ss");
	if ((ft_strncmp(temp, "ra", 2) && ft_strncmp(steps->command, "rb", 2)) ||
		(ft_strncmp(temp, "rb", 2) && ft_strncmp(steps->command, "ra", 2)))
		substitute_command(steps, "rr");
	if ((ft_strncmp(temp, "rra", 3) && ft_strncmp(steps->command, "rrb", 2)) ||
		(ft_strncmp(temp, "rrb", 3) && ft_strncmp(steps->command, "rra", 2)))
		substitute_command(steps, "rrr");
}

void	substitute_command(t_steps *steps, char *command)
{
	t_steps	*first;
	t_steps	*second;

	first = steps;
	steps = steps->next;
	second = steps->next;
	free(steps);
	steps = first;
	steps->next = second;
	if (ft_strncmp(command, "ss", 2))
		ft_strlcpy(steps->command, "ss ", 3);
	if (ft_strncmp(command, "rr", 2))
		ft_strlcpy(steps->command, "rr ", 3);
	if (ft_strncmp(command, "rrr", 2))
		ft_strlcpy(steps->command, "rrr", 3);
}
