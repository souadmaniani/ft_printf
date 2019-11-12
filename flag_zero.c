/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:08:58 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/11 10:54:58 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				depass_sign_zero(char **str, int *sign)
{
	if (atoi(*str) < 0 && **str)
	{
		*sign = -1;
		*str = *str + 1;
	}
}

char				*flag_zero(const char *fr, t_printf sr, va_list ap)
{
	char			*str;
	int				nzero;
	int				n_espace;
	int				sign;
	size_t			len;

	str = create_str(fr, ap);
	len = (!str) ? 0 : ft_strlen(str);
	str = (!str) ? "" : str;
	sign = 0;
	if (sr.prc)
		nzero = ((size_t)sr.prc_nb > len) ? (size_t)sr.prc_nb -
		len : 0;
	else
		nzero = (sr.zero_nb > len) ? sr.zero_nb - len : 0;
	nzero = (sr.space && atoi(str) > 0) ? --nzero : nzero;
	depass_sign_zero(&str, &sign);
	while (nzero--)
		str = ft_strjoin("0", str);
	str = (sign) ? ft_strjoin("-", str) : str;
	n_espace = (sr.zero_nb > ft_strlen(str)) ? sr.zero_nb - ft_strlen(str) : 0;
	n_espace = (sr.space && n_espace == 0 && sign != -1) ? 1 : n_espace;
	while (n_espace--)
		str = ft_strjoin(" ", str);
	return (str);
}
