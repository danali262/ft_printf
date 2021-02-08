/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_args.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 16:31:36 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 17:46:07 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_multiples(int i, const char *format, t_print *tab)
{
	while ((format[i] == '0' || format[i] == '-') && format[i] != '\0')
	{
		tab->pos++;
		i++;
	}
	return (i);
}

void		handle_flags(const char *format, t_print *tab)
{
	int i;

	i = 0;
	i = check_multiples(i, format, tab);
	if ((format[i] == '0' && format[i + 1] == '-') ||
	(format[i] == '-' && format[i + 1] == '0'))
	{
		tab->zero_used = 1;
		tab->minus_used = 1;
		tab->pos += 2;
		return ;
	}
	if (format[i] == '0')
	{
		handle_zero(&format[i], tab);
		tab->zero_used = 1;
	}
	if (format[i] == '-')
	{
		handle_minus(&format[i + 1], tab);
		tab->minus_used = 1;
	}
}

void		handle_field_width(const char *format, va_list ap, t_print *tab)
{
	int i;

	i = 0;
	if (ft_isdigit(format[i]))
		handle_digit_field_width(&format[i], tab);
	else if (format[i] == '*')
		handle_asterisk_field_width(&format[i - 1], ap, tab);
}

void		handle_precision(const char *format, va_list ap, t_print *tab)
{
	int i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		tab->pos++;
		if (ft_isdigit(format[i]))
			handle_digit_precision(&format[i], tab);
		else if (format[i] == '*')
			handle_asterisk_precision(ap, tab);
		tab->precision_used = 1;
	}
}

void		handle_conversion(char c, va_list ap, t_print *tab)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		tab->pos++;
		tab->chars_printed++;
	}
	else
	{
		if (c == 'c')
			handle_char(ap, tab);
		else if (c == 's')
			handle_string(ap, tab);
		else if (c == 'p')
			handle_pointer(ap, tab);
		else if (c == 'd' || c == 'i')
			handle_integer(ap, tab);
		else if (c == 'u' || c == 'x' || c == 'X')
			handle_unsigned(c, ap, tab);
	}
}
