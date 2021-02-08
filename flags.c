/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 11:24:35 by danali        #+#    #+#                 */
/*   Updated: 2020/12/11 13:31:20 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	pad_zeroes(int diff, t_print *tab)
{
	int i;

	i = 0;
	if (diff > 0)
	{
		while (i < diff)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		tab->chars_printed += diff;
	}
}

void	pad_spaces(int diff, t_print *tab)
{
	int i;

	i = 0;
	if (diff > 0)
	{
		while (i < diff)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		tab->chars_printed += diff;
	}
}

void	handle_zero(const char *string, t_print *tab)
{
	int		i;
	char	*number;
	int		len;

	i = 1;
	len = 0;
	while (ft_isdigit(string[len]))
		len++;
	number = malloc(len * sizeof(char));
	if (number == NULL)
		return ;
	while (ft_isdigit(string[i]))
	{
		number[i - 1] = string[i];
		i++;
	}
	number[i] = '\0';
	tab->zeroes = ft_atoi(number);
	free(number);
	tab->pos += len;
}

void	handle_minus(const char *string, t_print *tab)
{
	int		i;
	char	*number;
	int		len;

	i = 0;
	len = 0;
	while (ft_isdigit(string[len]))
		len++;
	number = malloc(len + 1 * sizeof(char));
	if (number == NULL)
		return ;
	while (ft_isdigit(string[i]))
	{
		number[i] = string[i];
		i++;
	}
	number[i] = '\0';
	tab->spaces = ft_atoi(number);
	free(number);
	tab->pos += len + 1;
}
