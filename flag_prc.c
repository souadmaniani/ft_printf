/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:30 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 10:43:45 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*init_sign_nzero(const char *fr, va_list ap, int *nzero,
int *sign)
{
	char			*str;

	str = create_str(fr, ap);
	*sign = 0;
	*nzero = 0;
	return (str);
}

char				*flag_prc(const char *fr, t_printf sr, va_list ap)
{
	char			*str;
	int				nzero;
	int				n_espace;
	int				sign;
	size_t			len;

	str = init_sign_nzero(fr, ap, &nzero, &sign);
	if (ft_strchr(fr, 's'))
	{
		len = ((size_t)sr.prc_nb < ft_strlen(str)) ? sr.prc_nb : ft_strlen(str);
		str = ft_substr(str, 0, len);
	}
	else if (!atoi(str) && !sr.prc_nb)
		str = ft_substr(str, 0, 0);
	else if (*str != '%')
		nzero = ((size_t)sr.prc_nb > ft_strlen(str)) ? (size_t)sr.prc_nb -
		ft_strlen(str) : 0;
	depass_sign(&str, &sign, &nzero);
	while (nzero--)
		str = ft_strjoin("0", str);
	str = (sign) ? ft_strjoin("-", str) : str;
	n_espace = (sr.space && sign != -1) ? 1 : 0;
	while (n_espace--)
		str = ft_strjoin(" ", str);
	return (str);
}
