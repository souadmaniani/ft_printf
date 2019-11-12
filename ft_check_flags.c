/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 07:41:27 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 11:02:26 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*format_zero(const char *fr,
t_printf *my_struct, va_list ap)
{
	if (*fr == '0')
	{
		my_struct->zero = 1;
		fr++;
		if (*fr == '*')
			my_struct->zero_nb = va_arg(ap, int);
		else
			my_struct->zero_nb = ft_atoi(fr);
		if (my_struct->zero_nb > 0)
			fr = (*fr == '*') ? fr + 1 : fr + index_format(fr);
	}
	return (fr);
}

const char			*format_minus(const char *fr,
t_printf *my_struct, va_list ap)
{
	if (*fr == '-')
	{
		while (*fr == '-')
			fr++;
		my_struct->minus = 1;
		if (*fr == '*')
			my_struct->minus_wdt = va_arg(ap, int);
		else
			my_struct->minus_wdt = ft_atoi(fr);
	}
	if (my_struct->minus_wdt > 0)
		fr = (*fr == '*') ? fr + 1 : fr + index_format(fr);
	return (fr);
}

const char			*format_prc(const char *fr,
t_printf *my_struct, va_list ap)
{
	if (*fr == '.')
	{
		my_struct->prc = 1;
		fr++;
		if (*fr == '*')
			my_struct->prc_nb = va_arg(ap, int);
		else
			my_struct->prc_nb = ft_atoi(fr);
		if (my_struct->prc_nb > 0)
			fr = (*fr == '*') ? fr + 1 : fr + index_format(fr);
		else if (my_struct->prc_nb == 0 && *fr == '0')
			fr = fr + 1;
	}
	return (fr);
}

void				check_cas(const char **fr, t_printf *my_struct, va_list ap,
int *k)
{
	int				argm;

	*fr = depass_spaces(*fr, my_struct, k);
	if (**fr == '0')
		*fr = format_zero(*fr, my_struct, ap);
	if (**fr == '-')
		*fr = format_minus(*fr, my_struct, ap);
	if (**fr == '*' && (argm = va_arg(ap, int)) < 0)
	{
		my_struct->minus = 1;
		my_struct->minus_wdt = -argm;
		*fr = *fr + 1;
	}
	if (**fr == '.')
		*fr = format_prc(*fr, my_struct, ap);
	else
	{
		my_struct->wdt = (**fr == '*') ? argm : ft_atoi(*fr);
		if (my_struct->wdt > 0)
		{
			*k = 1;
			*fr = (**fr != '*') ? *fr + (index_format(*fr)) : *fr + 1;
		}
	}
}

t_printf			ft_check_flags(const char *fr, va_list ap)
{
	t_printf		my_struct;
	int				k;

	k = 0;
	my_struct = initialser_struct(&my_struct);
	while (*fr)
	{
		if (*fr == '%' || k || *fr == '*')
		{
			check_cas(&fr, &my_struct, ap, &k);
			if (ft_strchr("%cspdiuxX", *fr))
				break ;
		}
		else
			fr++;
	}
	return (my_struct);
}
