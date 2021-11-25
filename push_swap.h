/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:37:35 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/24 19:31:34 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define FALSE 0
# define TRUE 1

typedef struct s_steps
{
	char			*command;
	struct s_steps	*next;
}				t_steps;

typedef struct s_stack
{
    int size;
    int *array;
    int *index;
    int largest_number;
	t_steps			*step_list;
	t_steps			*last_step;
}              t_stack;

void    first_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps);
void    second_move(t_stack *stack_a, t_stack *stack_b, t_steps *steps);

int     check_repeated(t_stack *stack_a);
int     check_if_sorted(t_stack *stack_a);
void    sort_index(t_stack *stack_a);
void    sort_stack(t_stack *stack_a, t_stack *stack_b, t_steps *steps);
int	choose_head(t_stack *stack_a);

void    s(t_stack *stack, t_steps *steps, char c);
void    r(t_stack *stack, t_steps *steps, char c);
void    p(t_stack *stack_a, t_stack *stack_b, t_steps *steps, char c);
void    ss(t_stack *stack_a, t_stack *stack_b, t_steps *steps);
void    rr(t_stack *stack_a, t_stack *stack_b, t_steps *steps);
void    rr_(t_stack *stack, t_steps *steps, char c);
void    rrr(t_stack *stack_a, t_stack *stack_b, t_steps *steps);

void	radix_sort(t_stack *stack_a, t_stack *stack_b, t_steps *steps);

void    extend_stack(t_stack *stack);
void    reduce_stack(t_stack *stack);

void    refactor_steps(t_steps *steps);
void    substitute_command(t_steps *steps, char *command);

int	    ft_isdigits(char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *string1, const char *string2, size_t size);
double	ft_atod(const char *nptr);
int	ft_isdigit(int c);
int	ft_strncmp(const char *string1, const char *string2, size_t size);
char	*ft_strdup(const char *str);
void	ft_bzero(void *str, size_t size);

void    error_message(int error);

#endif