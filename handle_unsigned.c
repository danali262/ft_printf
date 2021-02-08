/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_unsigned.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 16:37:01 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		pad_spaces_begin(int len, t_print *tab)
{
	if (tab->minus_used == 1 && tab->spaces == 0)
		tab->field_width *= -1;
	if (tab->field_width > len && tab->field_width > tab->precision)
	{
		if (tab->precision > len)
			pad_spaces(tab->field_width - tab->precision - tab->zeroes,
			tab);
		else
			pad_spaces(tab->field_width - len - tab->zeroes, tab);
	}
	else
	{
		if (tab->field_width > len && tab->field_width > tab->precision)
		{
			if (tab->precision >= len)
				pad_spaces(tab->field_width - tab->precision - 1 - tab->zeroes,
				tab);
			else
				pad_spaces(tab->field_width - len - tab->zeroes, tab);
		}
	}
}

static void		pad_spaces_end(int len, t_print *tab)
{
	if ((tab->spaces > len && tab->spaces > tab->precision))
	{
		if (tab->precision > len)
			pad_spaces(tab->spaces - tab->precision - tab->zeroes, tab);
		else
			pad_spaces(tab->spaces - len - tab->zeroes, tab);
	}
	else
	{
		if (tab->spaces > len && tab->spaces > tab->precision)
		{
			if (tab->precision >= len)
				pad_spaces(tab->spaces - tab->precision - 1 - tab->zeroes, tab);
			else
				pad_spaces(tab->spaces - len - tab->zeroes, tab);
		}
	}
	if (tab->field_width < 0 && tab->spaces == 0)
		pad_spaces(-tab->field_width - len, tab);
}

static void		positive_zero_unsigned(int d, char *s, int len, t_print *tab)
{
	int i;

	i = 0;
	if (d == 0)
	{
		if (tab->precision_used == 1 && tab->precision == 0)
		{
			len = 0;
			i = 1;
			tab->chars_printed--;
		}
	}
	if (tab->precision < 0)
		tab->precision = 0;
	pad_spaces_begin(len, tab);
	if (tab->zeroes > len)
		pad_zeroes(tab->zeroes - len, tab);
	if (tab->precision > len)
		pad_zeroes(tab->precision - len, tab);
	if (d == 0)
		ft_putstr_fd(&s[i], 1);
	else
		ft_putstr_fd(s, 1);
	pad_spaces_end(len, tab);
}

void			handle_unsigned(char c, va_list ap, t_print *tab)
{
	unsigned int	u;
	char			*unsigned_integer;
	int				len;

	u = va_arg(ap, unsigned int);
	if (c == 'u')
		unsigned_integer = ft_itoa_unsigned(u);
	if (c == 'x')
		unsigned_integer = ft_itoa_base_lower(u, 16);
	if (c == 'X')
		unsigned_integer = ft_itoa_base_upper(u, 16);
	len = ft_strlen(unsigned_integer);
	if (tab->precision_used == 1 && tab->precision >= 0 && tab->zero_used == 1)
		tab->zeroes = 0;
	positive_zero_unsigned(u, unsigned_integer, len, tab);
	tab->pos++;
	tab->chars_printed += len;
	free(unsigned_integer);
}
