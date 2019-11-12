/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reception_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:42:57 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/12 12:25:06 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						index_format(const char *fr)
{
	int					i;

	i = 0;
	while (((*fr != '+' && (*fr >= 9 && *fr <= 13)) || *fr == 32) && *fr)
	{
		fr++;
		i++;
	}
	while (*fr >= 48 && *fr <= 57 && *fr)
	{
		fr++;
		i++;
	}
	return (i);
}

int						test_cas(const char *fr, t_variabl *var, va_list ap)
{
	char				*str;

	str = create_str(fr, ap);
	if (*str == '\0' && ft_strlen(str) == 0 && *fr == 'c')
	{
		write(1, "\0", 1);
		var->j = var->j + 1;
	}
	else
	{
		write(1, str, ft_strlen(str));
		var->j = var->j + ft_strlen(str);
	}
	if (*fr != 's')
	{
		free(str);
		str = NULL;
	}
	return (var->j);
}

int						print_str(char *str, t_variabl *var)
{
	write(1, str, ft_strlen(str));
	var->j = var->j + ft_strlen(str);
	return (var->j);
}

void					my_funct(t_variabl *var, t_printf my_struct,
		va_list ap, const char *fr)
{
	if (ft_strchr("%cdixXusp", fr[var->i]))
		var->j = test_cas(fr + var->i, var, ap);
	else if (my_struct.zero)
	{
		while (fr[var->i] == ' ')
			var->i++;
		var->j = print_str(flag_zero(fr + var->i, my_struct, ap), var);
	}
	else if (my_struct.minus)
		var->j = print_str(flag_minus(fr + var->i, my_struct, ap), var);
	else if (my_struct.wdt)
		var->j = print_str(flag_width(fr + var->i, my_struct, ap), var);
	else if (my_struct.prc)
	{
		while (fr[var->i] == ' ')
			var->i++;
		var->j = print_str(flag_prc(fr + var->i, my_struct, ap), var);
	}
}

int						ft_reception_struct(const char *fr, va_list ap)
{
	t_variabl			var;
	t_printf			my_struct;

	var.i = -1;
	var.j = 0;
	while (fr[++var.i])
	{
		if (fr[var.i] == '%')
		{
			my_struct = ft_check_flags(fr + var.i, ap);
			var.i++;
			my_funct(&var, my_struct, ap, fr);
			while (!ft_strchr("%cdixXusp", fr[var.i]))
				var.i++;
		}
		else
		{
			write(1, &fr[var.i], 1);
			var.j++;
		}
	}
	return (var.j);
}
