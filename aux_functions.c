/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aux_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 09:04:34 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 16:29:21 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		is_special_char(char c, t_print *tab)
{
	if (c != 'a' || c != 'b' || c != 'f' || c != 'n' || c != 'r' || c != 't'
	|| c != 'v')
		tab->pos++;
	else
	{
		if (c == 'a')
			ft_putchar_fd('\a', 1);
		else if (c == 'b')
			ft_putchar_fd('\b', 1);
		else if (c == 'f')
			ft_putchar_fd('\f', 1);
		else if (c == 'n')
			ft_putchar_fd('\n', 1);
		else if (c == 'r')
			ft_putchar_fd('\r', 1);
		else if (c == 't')
			ft_putchar_fd('\t', 1);
		else if (c == 'v')
			ft_putchar_fd('\v', 1);
		else if (c == 'v')
			ft_putchar_fd('\v', 1);
		tab->pos += 2;
		tab->chars_printed++;
	}
}

void		struct_first_init(t_print *tab)
{
	tab->pos = 0;
	tab->chars_printed = 0;
	tab->flags_used = 0;
}

void		struct_second_init(t_print *tab)
{
	tab->zeroes = 0;
	tab->spaces = 0;
	tab->zero_used = 0;
	tab->minus_used = 0;
	tab->field_width = 0;
	tab->precision = 0;
	tab->precision_used = 0;
}

void		process_args(const char *str, va_list ap, t_print *tab)
{
	tab->pos++;
	handle_flags(&str[tab->pos], tab);
	handle_field_width(&str[tab->pos], ap, tab);
	handle_precision(&str[tab->pos], ap, tab);
	handle_conversion(str[tab->pos], ap, tab);
}

void		print_char(char c, t_print *tab)
{
	ft_putchar_fd(c, 1);
	tab->chars_printed++;
	tab->pos++;
}
