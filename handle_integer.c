/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_integer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 15:01:13 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		pad_spaces_begin(int d, int len, t_print *tab)
{
	if (tab->minus_used == 1 && tab->spaces == 0)
		tab->field_width *= -1;
	if (d >= 0)
	{
		if (tab->field_width > len && tab->field_width > tab->precision)
		{
			if (tab->precision > len)
				pad_spaces(tab->field_width - tab->precision - tab->zeroes,
				tab);
			else
				pad_spaces(tab->field_width - len - tab->zeroes, tab);
		}
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

static void		pad_spaces_end(int d, int len, t_print *tab)
{
	if (d >= 0)
	{
		if ((tab->spaces > len && tab->spaces > tab->precision))
		{
			if (tab->precision > len)
				pad_spaces(tab->spaces - tab->precision - tab->zeroes, tab);
			else
				pad_spaces(tab->spaces - len - tab->zeroes, tab);
		}
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

static void		positive_zero_integer(int d, char *s, int len, t_print *tab)
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
	pad_spaces_begin(d, len, tab);
	if (tab->zeroes > len)
		pad_zeroes(tab->zeroes - len, tab);
	if (tab->precision > len)
		pad_zeroes(tab->precision - len, tab);
	if (d == 0)
		ft_putstr_fd(&s[i], 1);
	else
		ft_putstr_fd(s, 1);
	pad_spaces_end(d, len, tab);
}

static void		negative_integer(int d, char *s, int len, t_print *tab)
{
	if (tab->precision < 0)
		tab->precision = 0;
	pad_spaces_begin(d, len, tab);
	if (tab->zeroes >= len)
	{
		ft_putchar_fd(s[0], 1);
		pad_zeroes(tab->zeroes - len, tab);
		ft_putstr_fd(&s[1], 1);
	}
	else if (tab->precision >= len)
	{
		ft_putchar_fd(s[0], 1);
		pad_zeroes(tab->precision - (len - 1), tab);
		ft_putstr_fd(&s[1], 1);
	}
	else
		ft_putstr_fd(s, 1);
	pad_spaces_end(d, len, tab);
}

void			handle_integer(va_list ap, t_print *tab)
{
	int		d;
	char	*integer;
	int		len;

	d = va_arg(ap, int);
	integer = ft_itoa(d);
	len = ft_strlen(integer);
	if (tab->precision_used == 1 && tab->precision >= 0 && tab->zero_used == 1)
		tab->zeroes = 0;
	if (d >= 0)
		positive_zero_integer(d, integer, len, tab);
	else
		negative_integer(d, integer, len, tab);
	tab->pos++;
	tab->chars_printed += len;
	free(integer);
}
