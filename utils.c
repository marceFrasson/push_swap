/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:26:49 by mfrasson          #+#    #+#             */
/*   Updated: 2021/11/24 19:32:00 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (TRUE);
	else
		return (FALSE);
}

double	ft_atod(const char *nptr)
{
	int		i;
	double	j;
	double	num[3];

	i = 0;
	j = 10;
	*(num) = 0;
	*(num + 1) = 0;
	*(num + 2) = 1;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		if (*(nptr + i++) == '-')
			*(num + 2) *= -1;
	while (ft_isdigit(*(nptr + i)))
		*(num) = (*(num) * 10) + (*(nptr + i++) - '0');
	if (*(nptr + i) == '.')
	{
		while (ft_isdigit(*(nptr + ++i)))
		{
			*(num + 1) += (*(nptr + i) - '0') / j;
			j *= 10;
		}
	}
	return ((*(num) + *(num + 1)) * *(num + 2));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigits(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *string1, const char *string2, size_t size)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)string1;
	str2 = (unsigned char *)string2;
	while (i < size && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (FALSE);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;

	if (!(s))
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	temp = malloc((len + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	if (len == 0 || start >= (unsigned int)ft_strlen(s))
	{
		*temp = '\0';
		return (temp);
	}
	ft_strlcpy(temp, (const char *)(s + start), len + 1);
	return (temp);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	double			num;
	int				sinal;

	i = 0;
	num = 0;
	sinal = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (sinal * num);
}

char	*ft_strdup(const char *str)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(ft_strlen(str) + 1);
	if (!dst)
		return (NULL);
	while (str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return ((char *)dst);
}

static char	*sep_clear(char const *s, char c)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	temp = ft_strdup(s);
	if (!(s))
		return (NULL);
	if (ft_strlen(s) == 0)
		return (temp);
	if (*(char *)(s) != c && *(char *)(s) != '\0')
		*(temp + j++) = *(char *)s;
	while (*(char *)(s + i) != '\0')
	{
		if (*(char *)(s + i) == c && *(char *)(s + i - 1) != c)
			*(temp + j++) = c;
		else if (*(char *)(s + i) != c)
			*(temp + j++) = *(char *)(s + i);
		i++;
	}
	*(temp + j) = '\0';
	return (temp);
}

static char	**make_strs(char **s_temp, char *temp, char c)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (*(temp + j) != '\0')
	{
		i = 0;
		while (*(temp + j + i) != c && *(temp + j + i) != '\0')
			i++;
		if (i != 0)
		{
			*(s_temp + k) = ft_substr((char const *)(temp + j), 0, i);
			if (!(*(s_temp + k)))
				return (NULL);
			j += i;
			k++;
		}
		else
			j++;
	}
	return (s_temp);
}

static int	len_s_temp(char *temp, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(temp) == 0)
		return (j);
	while (*(temp + i) != '\0')
		if (*(temp + i++) == c)
			j++;
	if (*(temp + i - 1) != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**s_temp;
	size_t	j;

	if (!(s))
		return (NULL);
	temp = sep_clear(s, c);
	if (!(temp))
		return (NULL);
	j = len_s_temp(temp, c);
	s_temp = malloc((j + 1) * sizeof(char *));
	if (!(s_temp))
		return (NULL);
	*(s_temp + j) = NULL;
	if (j != 0)
	{
		s_temp = make_strs(s_temp, temp, c);
		if (!(s_temp))
			return (NULL);
	}
	free(temp);
	return (s_temp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (FALSE);
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	ft_bzero(void *str, size_t size)
{
	unsigned char		*s;
	unsigned long int	i;

	i = 0;
	s = str;
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
}

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!(lst))
// 		return ;
// 	del(lst->vol);
// 	free(lst);
// 	lst = NULL;
// }

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*temp1;
// 	t_list	*temp2;

// 	if (!(*lst))
// 		return ;
// 	temp1 = *lst;
// 	while (temp1)
// 	{
// 		temp2 = temp1->next;
// 		ft_lstdelone(temp1, del);
// 		temp1 = temp2;
// 	}
// 	*lst = NULL;
// }
