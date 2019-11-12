/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:46:35 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 10:36:31 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				depass_sign(char **str, int *sign, int *nzero)
{
	if (atoi(*str) < 0 && **str && *nzero)
	{
		*sign = -1;
		*str = *str + 1;
		*nzero = *nzero + 1;
	}
}

char				*flag_minus(const char *fr, t_printf sr, va_list ap)
{
	char			*str;
	int				nzero;
	int				n_es;
	int				sign;
	size_t			len;

	str = create_str(fr, ap);
	sign = 0;
	nzero = 0;
	if (ft_strchr(fr, 's') && sr.prc)
	{
		len = ((size_t)sr.prc_nb < ft_strlen(str)) ? sr.prc_nb : ft_strlen(str);
		str = ft_substr(str, 0, len);
	}
	else if (sr.prc)
		nzero = ((size_t)sr.prc_nb > ft_strlen(str)) ?
		(size_t)sr.prc_nb - ft_strlen(str) : 0;
	depass_sign(&str, &sign, &nzero);
	while (nzero--)
		str = ft_strjoin("0", str);
	str = (sign) ? ft_strjoin("-", str) : str;
	n_es = (sr.minus_wdt > ft_strlen(str)) ? sr.minus_wdt - ft_strlen(str) : 0;
	while (n_es--)
		str = ft_strjoin(str, " ");
	return (str);
}
