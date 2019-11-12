/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:35:12 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/12 12:27:39 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*depass_spaces(const char *fr, t_printf *my_struct, int *k)
{
	if (!ft_strchr(". -0", *fr))
		(fr)++;
	if (*fr == ' ')
	{
		while (*fr == ' ')
			(fr)++;
		my_struct->space = 1;
		*k = 1;
	}
	return (fr);
}

char				*buf_itoa(long n)
{
	int				i;
	char			*str;
	long			m;

	i = 0;
	m = n;
	while (m)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
	{
		if (!(str = (char*)malloc(i + 2)))
			return (NULL);
		if (n == 0)
			str[0] = '0';
		if (n)
			str[0] = '-';
		str[i + 1] = '\0';
	}
	else
		str = (char*)malloc(i + 1);
	return (str);
}

char				*ft_itoa(long n)
{
	int				i;
	char			*str;
	long			m;

	m = n;
	str = NULL;
	i = 0;
	while (m)
	{
		m = m / 10;
		i++;
	}
	m = n;
	str = buf_itoa(n);
	if (!str)
		return (NULL);
	((n > 0) ? (i--) : (m = -m));
	str[i + 1] = '\0';
	while (m)
	{
		str[i--] = m % 10 + 48;
		m = m / 10;
	}
	return (str);
}

t_printf			initialser_struct(t_printf *my_struct)
{
	my_struct->zero = 0;
	my_struct->zero_nb = 0;
	my_struct->wdt = 0;
	my_struct->minus = 0;
	my_struct->minus_wdt = 0;
	my_struct->prc = 0;
	my_struct->prc_nb = -1;
	my_struct->space = 0;
	my_struct->modulo = 0;
	return (*my_struct);
}
