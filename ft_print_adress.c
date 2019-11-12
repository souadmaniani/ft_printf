/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:24:57 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 11:42:23 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char							*buf_adress(unsigned long long int n)
{
	unsigned long long int		i;
	char						*str;
	unsigned long long int		m;

	i = 0;
	m = n;
	while (m)
	{
		m = m / 16;
		i++;
	}
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	return (str);
}

char							*ft_putnbr_base(unsigned long long int nbr)
{
	size_t						i;
	char						*str;
	unsigned long long int		m;
	size_t						len;
	char						tmp;

	str = buf_adress(nbr);
	i = 0;
	m = nbr;
	while (m)
	{
		str[i] = ((m % 16) >= 10) ? (m % 16) + 87 : m % 16 + '0';
		m = m / 16;
		i++;
	}
	i = -1;
	len = ft_strlen(str);
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return (str);
}

char							*ft_strjoin(char const *s1, char const *s2)
{
	size_t						len_s1;
	char						*res;
	int							i;

	if (!(s1 && s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	res = (char*)malloc(len_s1 + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	else
	{
		while (*s1)
		{
			res[i] = *s1++;
			i++;
		}
		while (*s2)
			res[len_s1++] = *s2++;
		res[len_s1] = '\0';
	}
	return (res);
}

char							*ft_print_adress(void *ptr)
{
	char						*str;
	char						*tmp;

	tmp = ft_putnbr_base((unsigned long long int)&(*ptr));
	if (!*tmp)
		tmp = "0";
	str = ft_strjoin("0x", tmp);
	return (str);
}
