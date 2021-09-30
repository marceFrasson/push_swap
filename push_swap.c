/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:53:03 by marce             #+#    #+#             */
/*   Updated: 2021/09/28 11:52:16 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

sorting algorithm

movements
    sa
    sb
    ss
    pa
    pb
    ra
    rb
    rr
    rra
    rrb
    rrr

input sequence

sort

sorted sequence

first check if first and last values are bigger or smallest

pass them to stack b

check if first half...




given two stacks, one with random numbers and another empty

first thing -> receive input ./push_swap "8 4 0 1 5 9 10"

int main(int argc, char **argv)
{
    check_args
    check_string

}

first sort with bouble sort
assign index to every number
chose head to stay at a stack
move smaller numbers to stack b
in stack b check first and last numbers
if first or last number is the smaller number move it to stack b
if not smaller number rotate list till find it
move smaller number to stack a and rotate stack
check if first number of stack a is the next index of the last number of stack and if it is rotate stack


first read argc argv
deal with string and numbers
put numbers on stack a
have a stack b
sort stack a with bouble sort
assign index to every number
look for the best head
chose the head
move numbers to stack b until reach head
rotate stack a so head goes to bottom
move smaller then head numbers to stack b while moving larger numbers to bottom
when all smaller numbers are at stack b look the first and second half os numbers looking for the smaller index number
if it is in the first half rotate stack until it goes to the first place
if it is in the second half reverse rotate stack until it goes to the fisrt place
move smaller index number to stack a and rotate to bottom
repeat last two steps until all numbers move back again to stack a
rotate stack a until smaller index number is in the first position and the list is sorted



3
5
main

print stack a and b in the terminal
if (argv[i] == '-v')
{
    while (stack_a->next || stack_b->next)
    {
        ft_printf("%d\t%d", stack.a.number, stack_b.number);
        stack_a++;
        stack_b++;
    }
    ft_printf("_\t_\na\tb");
}
_______________________________________________________________________________

static int  read_args(int *argc, char **argv)
{
    while (argv[i])
    {
        if (ft_isdigit(argv[i]))
        {
            stack_a->next = argv[i];
            stack_a++;
		    i++;
            argc--;
        }
        else
            return (0);
    }
}

static int  check_string(char *string)
{
    while (*string)
    {
        if (ft_isdigit(*string))
            string++;
        else
            return (0);
    }
    return (1);
}

static char	**check_string(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argv[0][0]))
		exit(0);
	argv = ft_split(argv[0], ' ');
	while (argv[i])
    {
        if (ft_isdigit(argv[i]))
		    i++;
        else
            return (NULL);
    }
	*argc = i;
	return (argv);
}

int main(int argc, char **argv)
{
    if (argc == 1)
		return (0);
	argv = &argv[1];
	argc--;
	if (argc == 1)
		argv = check_string(&argc, argv);
    else
        read_args(&argc, argv);
}


_______________________________________________________________________________

bouble sort

n = number of elements

while (i < n)
{
    scanf("%d", &array[i]);
    i++;
}

while (i < n - 1)
{
    while (d < n - i - 1)
    {
        if (array[d] > array[d+1]) // For decreasing order use '<' instead of '>'
        {
            temp       = array[d];
            array[d]   = array[d+1];
            array[d+1] = temp;
        }
        d++;
    }
    i++;
}
