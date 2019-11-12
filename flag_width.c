/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:14:09 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 10:53:11 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*init_str_vid(char *str, const char *fr, t_printf sr)
{
	if (*str == '0' && (ft_strchr(fr, 'd') || ft_strchr(fr, 'i') ||
	ft_strchr(fr, 'u') || ft_strchr(fr, 'x') ||
	ft_strchr(fr, 'X')) && sr.prc && !sr.prc_nb)
		str = "";
	return (str);
}

char				*flag_width(const char *fr, t_printf sr, va_list ap)
{
	char			*str;
	int				nzero;
	int				n_espace;
	int				sign;
	size_t			len;

	str = init_sign_nzero(fr, ap, &nzero, &sign);
	str = init_str_vid(str, fr, sr);
	if (ft_strchr(fr, 's') && sr.prc)
	{
		len = ((size_t)sr.prc_nb < ft_strlen(str)) ? (size_t)sr.prc_nb :
		ft_strlen(str);
		str = ft_substr(str, 0, len);
	}
	else if (sr.prc && *str != '%')
		nzero = ((size_t)sr.prc_nb > ft_strlen(str)) ? (size_t)sr.prc_nb -
		ft_strlen(str) : 0;
	depass_sign(&str, &sign, &nzero);
	while (nzero--)
		str = ft_strjoin("0", str);
	str = (sign) ? ft_strjoin("-", str) : str;
	n_espace = (sr.wdt > ft_strlen(str)) ? sr.wdt - ft_strlen(str) : 0;
	while (n_espace--)
		str = ft_strjoin(" ", str);
	return (str);
}
