/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:39:58 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/05 21:51:58 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	init_stacks(int n, t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = n;
	stack_a->array = malloc(n * sizeof(int));
	stack_a->index = malloc(n * sizeof(int));
	if (!(stack_a->array))
		return (0);
	if (!(stack_a->index))
		return (0);
	stack_b->size = 0;
	stack_b->index = malloc(n * sizeof(int));
	if (!(stack_b->index))
	{
		free(stack_b->index);
		return (0);
	}
	stack_a->to_keep_in_a = malloc(n * sizeof(int));
	if (!(stack_a->to_keep_in_a))
		return (0);
	return (1);
	ft_bzero(stack_b->index, stack_a->size);
}

static int	check_int(char **argv, int i, t_stack *stack_a)
{
	int		j;
	double	number;

	j = 0;
	if (argv[i][j] == '-')
	{
		j++;
		if (!argv[i][j])
			return (0);
	}
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
		{
			error_message(2); // error: not digit
			exit(0);
		}
		j++;
	}
	number = ft_atoi(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	stack_a->array[i] = (int)number;
	return (1);
}

static void	check_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		check_int(argv, i, stack_a);
		i++;
	}
	if (!check_repeated(stack_a))
	{
		error_message(4);
		exit(0);
	}
	if (check_if_sorted(stack_a))
	{
		error_message(3);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a = {0};
	t_stack	stack_b = {0};
	t_steps	steps = {0};
	int i;

	printf("first\n");
	if (argc == 1)
	{
		error_message(1);
		exit(2);
	}
	init_stacks(argc - 1, &stack_a, &stack_b);
	printf("stack_a->size : %i\n", stack_a.size);
	argv = &argv[1];
	argc--;
	check_args(argc, argv, &stack_a);
	sort_index(&stack_a);
	choose_head(&stack_a);
	printf("middle\n");
	printf("markup head: %i\n", stack_a.markup_head);
	first_move(&stack_a, &stack_b, &steps);
	printf("stack_a->size : %i\n", stack_a.size);
	i = 0;
	while (i <= stack_a.size)
	{
		printf("stack_a: %i | stack_b: %i\n", stack_a.index[i], stack_b.index[i]);
		i++;
	}
	//rearange_stack_a(&stack_a);
	//second_move(&stack_a, &stack_b, &steps);
	free(stack_a.array);
	free(stack_a.index);
	free(stack_b.index);
	printf("last\n");
}
