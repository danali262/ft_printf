/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_pointer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 11:44:37 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_pointer(va_list ap, t_print *tab)
{
	unsigned long		p;
	int					len;
	char				*ptr_address;

	p = (unsigned long)va_arg(ap, void *);
	ptr_address = ft_itoa_base_pointer(p, 16);
	len = ft_strlen(ptr_address);
	if ((void *)p == NULL)
		len = 5;
	if (tab->field_width > len)
		pad_spaces(tab->field_width - len, tab);
	if ((void *)p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		tab->chars_printed += 5;
	}
	else
	{
		ft_putstr_fd(ptr_address, 1);
		tab->chars_printed += len;
	}
	if (tab->spaces > len)
		pad_spaces(tab->spaces - len, tab);
	tab->pos++;
	free(ptr_address);
}
