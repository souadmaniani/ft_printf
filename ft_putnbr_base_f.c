/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:19:00 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 11:26:17 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_putnbr_base_hex(unsigned int nbr)
{
	size_t			i;
	char			*str;
	unsigned int	m;
	char			tmp;
	size_t			len;

	str = buf(nbr);
	i = 0;
	m = nbr;
	while (m)
	{
		str[i] = ((m % 16) >= 10) ? (m % 16) + 87 : m % 16 + '0';
		m = m / 16;
		i++;
	}
	len = ft_strlen(str);
	i = -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return (str);
}

unsigned int		ft_putnbr_unsi(int b)
{
	unsigned int	nb;

	nb = 4294967295;
	if (b < 0)
		return ((unsigned int)(nb + b + 1));
	else
		return ((unsigned int)b);
}

char				*ft_putnbr_base_hex_captl(unsigned int nbr)
{
	size_t			i;
	char			*str;
	unsigned int	m;
	size_t			len;
	char			tmp;

	str = buf(nbr);
	i = 0;
	m = nbr;
	while (m)
	{
		str[i] = ((m % 16) >= 10) ? (m % 16) + 55 : m % 16 + '0';
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

char				*ft_putnbr_base_dix(int nbr)
{
	size_t			i;
	char			*str;
	long			m;
	size_t			len;
	char			tmp;

	str = buf_itoa((long)nbr);
	i = 0;
	m = nbr;
	m = (nbr < 0) ? -m : (nbr);
	i = (nbr < 0) ? (i + 1) : (i);
	while (m)
	{
		str[i++] = m % 10 + '0';
		m = m / 10;
	}
	len = (nbr < 0) ? ft_strlen(str) + 1 : ft_strlen(str);
	i = (nbr < 0) ? 0 : -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return (str);
}
