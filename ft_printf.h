/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 16:52:19 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 17:44:52 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct		s_print
{
	int				pos;
	int				chars_printed;
	int				zeroes;
	int				spaces;
	int				flags_used;
	int				zero_used;
	int				minus_used;
	int				field_width;
	int				precision;
	int				precision_used;
}					t_print;

int					ft_printf(const char *format, ...);
void				is_special_char(char c, t_print *tab);
void				struct_first_init(t_print *tab);
void				struct_second_init(t_print *tab);
void				process_args(const char *str, va_list ap, t_print *tab);
void				print_char(char c, t_print *tab);

void				handle_char(va_list ap, t_print *tab);
void				handle_string(va_list ap, t_print *tab);
void				handle_pointer(va_list ap, t_print *tab);
void				handle_integer(va_list ap, t_print *tab);
void				handle_unsigned(char c, va_list ap, t_print *tab);

void				handle_flags(const char *string, t_print *tab);
void				handle_zero(const char *string, t_print *tab);
void				handle_minus(const char *string, t_print *tab);
void				pad_zeroes(int diff, t_print *tab);
void				pad_spaces(int diff, t_print *tab);
void				handle_field_width(const char *format, va_list ap,
					t_print *tab);
void				handle_digit_field_width(const char *string, t_print *tab);
void				handle_asterisk_field_width(const char *format,
					va_list ap, t_print *tab);
void				handle_precision(const char *format, va_list ap,
					t_print *tab);
void				handle_digit_precision(const char *string, t_print *tab);
void				handle_asterisk_precision(va_list ap, t_print *tab);
void				handle_conversion(char c, va_list ap, t_print *tab);

#endif
