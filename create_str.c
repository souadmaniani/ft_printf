/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:49:05 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/12 12:31:40 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				arriv_convers(const char **fr)
{
	while (!ft_strchr("%cdixXusp", **fr))
		(*fr)++;
}

char				*create_str(const char *fr, va_list ap)
{
	char			*str;
	char			*ptr;

	str = ft_calloc(2, 1);
	ptr = str;
	arriv_convers(&fr);
	if (*fr == 'd' || *fr == 'i')
		str = ft_putnbr_base_dix((int)va_arg(ap, int));
	else if (*fr == 'x')
		str = ft_putnbr_base_hex((int)va_arg(ap, int));
	else if (*fr == 'X')
		str = ft_putnbr_base_hex_captl((int)va_arg(ap, int));
	else if (*fr == 'u')
		str = ft_itoa(ft_putnbr_unsi(va_arg(ap, int)));
	else if (*fr == 's')
	{
		if (!(str = (char*)va_arg(ap, char*)))
			str = "(null)";
	}
	else if (*fr == 'p')
		str = ft_print_adress((void *)va_arg(ap, char*));
	else if (*fr == 'c' || *fr == '%')
		str[0] = (*fr == 'c') ? (char)va_arg(ap, int) : '%';
	(!(*fr == 'c' || *fr == '%')) ? free(ptr) : ptr;
	return (str);
}

char				*buf(unsigned int n)
{
	unsigned int	i;
	char			*str;
	unsigned int	m;

	i = 0;
	m = n;
	while (m)
	{
		m = m / 16;
		i++;
	}
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	if (!n)
	{
		str = (char*)malloc(2);
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

void				ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*tab;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}

void				*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				len;

	len = count * size;
	if (!(ptr = (unsigned char*)malloc(size * count)))
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
