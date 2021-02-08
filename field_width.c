/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/07 18:35:41 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_digit_field_width(const char *string, t_print *tab)
{
	int		i;
	char	*number;
	int		len;

	i = 0;
	len = 0;
	while (ft_isdigit(string[len]))
		len++;
	number = malloc((len + 1) * sizeof(char));
	if (number == NULL)
		return ;
	while (ft_isdigit(string[i]))
	{
		number[i] = string[i];
		i++;
	}
	number[i] = '\0';
	tab->field_width = ft_atoi(number);
	free(number);
	tab->pos += len;
}

void	handle_asterisk_field_width(const char *string, va_list ap, t_print
*tab)
{
	int i;
	int width;

	i = 0;
	width = va_arg(ap, int);
	if (width < 0)
	{
		tab->spaces = -width;
		tab->field_width = width;
	}
	else if (width > 0 && string[i] == '0')
	{
		tab->zeroes = width;
		tab->field_width = width;
	}
	else if (width > 0 && string[i] == '-')
	{
		tab->spaces = width;
		tab->field_width = -width;
	}
	else
		tab->field_width = width;
	tab->pos++;
}
