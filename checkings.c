/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:41:57 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/05 11:37:36 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeated(t_stack *stack_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i <= stack_a->size)
	{
		temp = stack_a->array[i];
		j = i + 1;
		while (j <= stack_a->size)
		{
			if (temp == stack_a->array[j])
				return (0); // error: repeated number
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_sorted(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->array[i - 1] > stack_a->array[i])
			return (0); // not sorted
		i++;
	}
	return (1); // sorted
}

void	sort_index(t_stack *stack_a)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		count = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[i] > stack_a->array[j])
				count++;
			j++;
		}
		stack_a->index[i] = count + 1;
		i++;
	}
}
