/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:22:13 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 11:10:42 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *fr, ...)
{
	va_list			ap;
	size_t			len;

	va_start(ap, fr);
	len = ft_reception_struct(fr, ap);
	va_end(ap);
	return (len);
}
