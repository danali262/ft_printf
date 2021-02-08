/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/10 15:50:12 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	handle_digit_precision(const char *string, t_print *tab)
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
	tab->precision = ft_atoi(number);
	free(number);
	tab->pos += len;
}

void	handle_asterisk_precision(va_list ap, t_print *tab)
{
	int width;

	width = va_arg(ap, int);
	tab->precision = width;
	tab->pos++;
}
