/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:39:58 by mfrasson          #+#    #+#             */
/*   Updated: 2022/02/27 22:02:04 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_stacks(int n, t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = n;
	stack_a->array = malloc((n + 1) * sizeof(int));
	if (!(stack_a->array))
		return (FALSE);
	stack_a->index = malloc((n + 1) * sizeof(int));
	if (!(stack_a->index))
	{
		free(stack_a->array);
		return (FALSE);
	}
	stack_b->size = 0;
	stack_b->index = malloc((n + 1) * sizeof(int));
	if (!(stack_b->index))
	{
		free(stack_a->array);
		free(stack_a->index);
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
			write(1, "Error\n", 6);
			exit(FALSE);
		}
		j++;
	}
	number = ft_atod(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
		return (FALSE);
	stack_a->array[i] = (int)number;
	return (TRUE);
}

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a->index);
	free(stack_b->index);
}

static void	check_args(int argc, char **argv,
	t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_int(argv, i, stack_a))
			i++;
		else
		{
			write(1, "Error\n", 6);
			free_stacks(stack_a, stack_b);
			exit(FALSE);
		}
	}
	if (!check_repeated(stack_a))
	{
		write(1, "Error\n", 6);
		free_stacks(stack_a, stack_b);
		exit(FALSE);
	}
	if (check_array_sorted(stack_a))
		exit(FALSE);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		exit(FALSE);
	init_stacks(argc - 1, &stack_a, &stack_b);
	check_args(argc - 1, argv + 1, &stack_a, &stack_b);
	sort_index(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
