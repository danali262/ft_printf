/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_string.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 17:52:31 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	field_width_str(int strlen, t_print *tab)
{
	if (tab->field_width > 0)
	{
		if (tab->field_width > strlen)
		{
			if ((tab->precision_used == 0) || (tab->precision_used == 1 &&
			tab->precision != 0))
			{
				if (strlen < tab->precision || tab->precision_used == 0 ||
				tab->precision < 0)
					pad_spaces(tab->field_width - strlen,
					tab);
				else
					pad_spaces(tab->field_width - tab->precision, tab);
			}
			else
				pad_spaces(tab->field_width, tab);
		}
		else
		{
			if (tab->precision_used == 1 && tab->precision >= 0 &&
			tab->field_width > tab->precision)
				pad_spaces(tab->field_width - tab->precision, tab);
		}
	}
}

static void	precision_str(char *string, int strlen, t_print *tab)
{
	int i;

	i = 0;
	if (tab->precision < strlen)
	{
		if (tab->precision == 0)
		{
			string = ft_strdup("");
			ft_putstr_fd(string, 1);
		}
		while (i < tab->precision)
		{
			ft_putchar_fd(string[i], 1);
			i++;
		}
		tab->chars_printed += tab->precision;
	}
	else
	{
		ft_putstr_fd(string, 1);
		tab->chars_printed += strlen;
	}
}

static void	left_adjustment_str(int strlen, t_print *tab)
{
	if (tab->field_width < 0 || tab->minus_used == 1)
	{
		if (tab->precision == strlen)
		{
			if (-tab->field_width > strlen)
				pad_spaces(-tab->field_width - strlen, tab);
			else if (tab->spaces > strlen)
				pad_spaces(tab->spaces - strlen, tab);
		}
		else if (tab->precision == 0 && tab->precision_used == 1)
			pad_spaces(-tab->field_width, tab);
		else
		{
			if (tab->precision < -tab->field_width && tab->precision < strlen)
				pad_spaces(tab->spaces - tab->precision, tab);
			else
				pad_spaces(tab->spaces - strlen, tab);
		}
	}
}

void		handle_string(va_list ap, t_print *tab)
{
	char	*s;
	char	*string;
	int		len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	string = ft_strdup(s);
	len = ft_strlen(string);
	field_width_str(len, tab);
	if (tab->precision < 0 || tab->precision_used == 0)
		tab->precision = len;
	precision_str(string, len, tab);
	left_adjustment_str(len, tab);
	tab->pos++;
	if (string != NULL)
		free(string);
}
