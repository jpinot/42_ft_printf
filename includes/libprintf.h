/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:54:06 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/03 19:18:16 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//revisar includes!!!!

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
#include <wchar.h>
# include "../libft/libft.h"
# include "stddef.h"

//#define CONVERSIONS sSpdDioOuUxXcCeEfFgGaAn
//static const char conv[] = {CONVERSIONS};

typedef struct		s_arg
{
	int				arg;
	int				left_justify;
	int				force_positive;
	int				prefix;
	int				pad_zero;
	int				thousands_group;
	int				filed_width;
	int				precision;
	int				lenght;
	int				fd;
	int				p_switch;
}					t_arg;

int			ft_printf(const char *restrict format, ...);
t_arg		ft_printf_new_arg(t_arg *arg);
int			ft_printf_putint(intmax_t num, t_arg *arg);
int         ft_printf_putuint(uintmax_t num, t_arg *arg, int conv);
int			ft_printf_putchar(char c, t_arg *arg);
int         ft_printf_putstr(char *s, t_arg *arg);
int         ft_printf_pututf_8(char *c, t_arg *arg);
int         ft_printf_putstr_utf_8(char **c, t_arg *arg);
char        *ft_printf_itoa(uintmax_t n);
char        *ft_printf_itoa_hex(uintmax_t num, int conv, t_arg *arg);
char        *ft_printf_itoa_oct(uintmax_t num, t_arg *arg);
char		*ft_printf_itoa_bin(uintmax_t num);
char        *ft_printf_from_int_to_utf_8(int c, t_arg *arg);
void		ft_write(char c, int i);
int			ft_pf_write_until(char c, int j, int fd);
int			ft_pf_putstr(char *s, int fd);
int			ft_pf_putchar(char c, int fd);
int			ft_pf_putstr_until(char *s, int i, int fd);
int			ft_pf_strlen(const char *s);

char	*ft_check_flags(char *s, t_arg *arg);
char	*ft_check_field_with(va_list ap, char *s, t_arg *arg);
char	*ft_check_precision(va_list ap, char *s, t_arg *arg);
char	*ft_check_length(char *s, t_arg *arg);

int		conv_int(va_list ap, t_arg *arg, int conv);
int		conv_unsigned_int(va_list ap, t_arg *arg, int conv);
int     conv_char(va_list ap, t_arg *arg);
int     conv_str(va_list ap, t_arg *arg);
int		conv_void(va_list ap, t_arg *arg, int conv);
int		conv_utf_8(va_list ap, t_arg *arg);
int     conv_str_utf_8(va_list ap, t_arg *arg);
#endif
