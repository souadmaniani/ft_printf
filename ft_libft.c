/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:34:05 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 11:09:05 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *s)
{
	size_t			n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

char				*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char*)s);
	return (0);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	const char		*ptr;
	int				i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(sub = (char*)malloc(1)))
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	ptr = s + start;
	len = (len > ft_strlen(s) - start) ? ft_strlen(s) - start : len;
	i = 0;
	if (!(sub = (char*)malloc(len + 1)))
		return (NULL);
	while (*ptr && len--)
	{
		sub[i] = ptr[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int					ft_atoi(const char *str)
{
	long			integer;
	int				i;
	int				sign;

	integer = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		integer = integer * 10 + str[i] - '0';
		if (integer > 4294967296 && sign == 1)
			return (-1);
		if (integer > 4294967296 && sign == -1)
			return (0);
		i++;
	}
	return (integer * sign);
}
