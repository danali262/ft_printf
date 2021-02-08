/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 11:42:53 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list ap, t_print *tab)
{
	unsigned char c;

	c = va_arg(ap, int);
	if (tab->field_width > 1)
		pad_spaces(tab->field_width - 1, tab);
	ft_putchar_fd(c, 1);
	if (tab->spaces > 1)
		pad_spaces(tab->spaces - 1, tab);
	tab->pos++;
	tab->chars_printed++;
}
