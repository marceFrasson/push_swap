/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:41:57 by mfrasson          #+#    #+#             */
/*   Updated: 2021/10/23 15:20:03 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_repeated(t_stack *stack_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i <= stack_a->n)
	{
		temp = stack_a->array[i];
		j = i + 1;
		while (j <= stack_a->n)
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
	while (i < stack_a->n)
	{
		if (stack_a->array[i - 1] > stack_a->array[i])
			return (0); // not sorted
		i++;
	}
	return (1); // sorted
}

static void	replace_numbs(t_stack *a, t_stack *b)
{
	int	cont;
	int	i;
	int	j;

	i = -1;
	while (++i < a->n)
	{
		j = -1;
		cont = 0;
		while (++j < a->n)
			if (a->array[i] > a->array[j])
				cont++;
		b->array[i] = cont + 1;
	}
	i = -1;
	while (++i < a->n)
		a->array[i] = b->array[i];
}

void	sort_index(t_stack *stack_a)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->n)
	{
		j = 0;
		count = 0;
		while (j < stack_a->n)
		{
			if (stack_a->array[i] > stack_a->array[j])
				count++;
			j++;
		}
		printf("antes: index %i, count: %i, i: %i\n", stack_a->index[i], count, i);
		stack_a->index[i] = count + 1;
		printf("depois: index %i, count: %i, i: %i\n", stack_a->index[i], count, i);
		i++;
	}
	i = 0;
	while (i < stack_a->n)
	{
		printf("index: _ %i _\n", stack_a->index[i]);
		i++;
	}
}



void	choose_head(t_stack *stack_a)
{
	int	temp;
	int	count;
	int	i;
	int	j;

	i = 0;
	temp = 0;
	while (i < stack_a->n)
	{
		j = i;
		count = 0;
		while (j < stack_a->n - 1)
		{
			if (stack_a->array[i] > stack_a->array[j])
				count++;
			j++;
		}
		if (count > temp)
		{
			stack_a->markup_head = stack_a->index[i];
			temp = count;
		}
		i++;
	}
}
