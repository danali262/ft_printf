/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 16:00:01 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 16:34:12 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	do_print(const char *format, va_list ap, t_print *tab)
{
	struct_first_init(tab);
	while (format[tab->pos] != '\0')
	{
		struct_second_init(tab);
		if (format[tab->pos] == '\\')
		{
			ft_putchar_fd('\\', 1);
			tab->chars_printed++;
			is_special_char(format[tab->pos + 1], tab);
		}
		else if (format[tab->pos] == '%')
			process_args(format, ap, tab);
		else
			print_char(format[tab->pos], tab);
	}
}

int			ft_printf(const char *format, ...)
{
	t_print *tab;
	va_list arg_ptr;
	int		res;

	va_start(arg_ptr, format);
	tab = malloc(sizeof(t_print));
	if (tab == NULL)
		return (0);
	do_print(format, arg_ptr, tab);
	va_end(arg_ptr);
	res = tab->chars_printed;
	free(tab);
	return (res);
}
