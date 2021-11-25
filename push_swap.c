/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:39:58 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/24 21:41:54 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	init_stacks(int n, t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = n;
	stack_a->array = malloc(n * sizeof(int) + 1);
	stack_a->index = malloc(n * sizeof(int) + 1);
	if (!(stack_a->array))
		return (FALSE);
	if (!(stack_a->index))
		return (FALSE);
	stack_b->size = 0;
	stack_b->index = malloc(n * sizeof(int) + 1);
	if (!(stack_b->index))
	{
		free(stack_b->index);
		return (FALSE);
	}
	ft_bzero(stack_b->index, stack_a->size);
	return (TRUE);
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
			return (FALSE);
	}
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
		{
			error_message(2); // error: not digit
			exit(FALSE);
		}
		j++;
	}
	number = ft_atoi(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
		return (FALSE);
	stack_a->array[i] = (int)number;
	return (TRUE);
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
		exit(FALSE);
	}
	if (check_if_sorted(stack_a))
	{
		error_message(3);
		exit(FALSE);
	}
}

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a->index);
	free(stack_b->index);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a = {0};
	t_stack	stack_b = {0};
	t_steps	steps = {0};

	if (argc == 1)
	{
		error_message(1);
		exit(2);
	}
	init_stacks(argc - 1, &stack_a, &stack_b);
	argv = &argv[1];
	argc--;
	check_args(argc, argv, &stack_a);
	sort_index(&stack_a);
	printf("middle\n");
	sort_stack(&stack_a, &stack_b, &steps);
	printf("%i <- value of stack_a->size\n", stack_a.size);
	int i = -1;
	while (++i < 7)
		printf("%i	%i\n", stack_a.index[i], stack_b.index[i]);
	free_stacks(&stack_a, &stack_b);
	printf("last\n");
}
