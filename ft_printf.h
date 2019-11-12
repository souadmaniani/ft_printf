/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 08:45:19 by smaniani          #+#    #+#             */
/*   Updated: 2019/11/12 12:32:26 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_variabl
{
	int				i;
	int				j;
}					t_variabl;

typedef struct		s_printf
{
	size_t			zero;
	size_t			zero_nb;
	size_t			wdt;
	size_t			minus;
	size_t			minus_wdt;
	size_t			prc;
	int				prc_nb;
	size_t			space;
	int				modulo;

}					t_printf;

size_t				ft_strlen(const char *s);
char				*buf_itoa(long n);
char				*ft_itoa(long n);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*buf(unsigned int n);
char				*ft_putnbr_base_hex(unsigned int nbr);
char				*ft_putnbr_base_hex_captl(unsigned int nbr);
char				*ft_putnbr_base_dix(int nbr);
char				*buf_adress(unsigned long long int n);
char				*ft_putnbr_base(unsigned long long int nbr);
char				*ft_print_adress(void *ptr);
unsigned int		ft_putnbr_unsi(int nb);
int					index_format(const char *fr);
const char			*format_zero(const char *fr, t_printf *my_struct,
		va_list ap);
const char			*format_minus(const char *fr, t_printf *my_struct,
		va_list ap);
char				*init_sign_nzero(const char *fr, va_list ap, int *nzero,
		int *sign);
const char			*format_prc(const char *fr, t_printf *my_struct,
		va_list ap);
const char			*format_modulo(const char *fr, t_printf *my_struct,
		va_list ap);
const char			*format_width(const char *fr, t_printf *my_struct,
		va_list ap, int *k);
int					test_cas(const char *fr, t_variabl *var, va_list ap);
int					print_str(char *str, t_variabl *var);
void				my_funct(t_variabl *var, t_printf my_struct, va_list ap,
		const char *fr);
t_printf			initialser_struct(t_printf *my_struct);
int					ft_reception_struct(const char *fr, va_list ap);
void				arriv_convers(const char **fr);
char				*create_str(const char *fr, va_list ap);
void				depass_sign(char **str, int *sign, int *nzero);
void				depass_sign_zero(char **str, int *sign);
char				*flag_zero(const char *fr, t_printf my_struct, va_list ap);
char				*flag_minus(const char *fr, t_printf sr, va_list ap);
char				*init_str_vid(char *str, const char *fr, t_printf sr);
char				*flag_width(const char *fr, t_printf sr, va_list ap);
void				couper_str(size_t *len, char **str, t_printf sr);
char				*flag_prc(const char *fr, t_printf sr, va_list ap);
void				check_cas(const char **fr, t_printf *my_struct, va_list ap,
		int *k);
const char			*depass_spaces(const char *fr, t_printf *my_struct, int *k);
t_printf			ft_check_flags(const char *fr, va_list ap);
int					ft_printf(const char *format, ...);

#endif
