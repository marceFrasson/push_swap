/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:54:01 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/05 19:52:35 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *source, int *destiny, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		destiny[i] = source[i];
		i++;
	}
	// i = 0;
	// while (i < size)
	// {
	// 	printf("dest : %i | src : %i\n", destiny[i], source[i]);
	// 	i++;
	// }
}

static int	nodes_to_keep_a(t_stack *stack_a, int i, int *array)
{
	int j;
	int previous;
	int keep_in_a_count;

	j = 1;
	keep_in_a_count = 1;
	previous = stack_a->index[i];
	array[0] = previous;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] > previous)
		{
			previous = stack_a->index[i];
			keep_in_a_count++;
			array[j] = previous;
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < keep_in_a_count)
	// {
	// 	printf("to keep array %i : %i\n", i, array[i]);
	// 	i++;
	// }
	return (keep_in_a_count);
}

int	choose_head(t_stack *stack_a)
{
	int i;
	int j;
	int keep_in_a_count;
	int temp_keep_in_a;
	int temp_head;
	int *array;			// <- array

	i = 0;
	array = malloc(stack_a->size * sizeof(int));
	if (!(array))
		return (0);
	ft_bzero(array, stack_a->size);
	keep_in_a_count = 0;
	temp_keep_in_a = 0;
	temp_head = 0;
	while (i < stack_a->size)
	{
		temp_keep_in_a = nodes_to_keep_a(stack_a, i, array);		// <- funcao q modifica o array
		j = 0;
		while (i < temp_keep_in_a)
		{
			printf("to keep array %i : %i\n", i, array[i]);
			i++;
		}
		if (temp_keep_in_a > keep_in_a_count)
		{
			temp_head = i;
			keep_in_a_count = temp_keep_in_a;
			copy_array(stack_a->to_keep_in_a, array, keep_in_a_count);
		}
		i++;
	}
	stack_a->markup_head = stack_a->index[temp_head];
	stack_a->keep_in_a_count = keep_in_a_count;
	i = 0;
	while (i < keep_in_a_count)
	{
		printf("to keep array _ %i : %i\n", i, stack_a->to_keep_in_a[i]);
		i++;
	}
	return (1);
}
