/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:13:42 by danali        #+#    #+#                 */
/*   Updated: 2020/11/04 15:50:50 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		string_number(char const *s, char c)
{
	int num;
	int i;
	int strlen;

	num = 0;
	i = 0;
	strlen = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (strlen != 0)
				num++;
			strlen = 0;
		}
		else
			strlen++;
		i++;
	}
	if (strlen != 0)
		return (num + 1);
	else
		return (num);
}

static void		*free_strings(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static char		**do_split(char const *s, char c, char **array, int str_num)
{
	int		word;
	int		strlen;
	int		i;

	i = 0;
	word = 0;
	strlen = 0;
	while (word < str_num)
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (strlen != 0)
			{
				array[word] = ft_substr(s + i - strlen, 0, strlen);
				if (array[word] == NULL)
					return (free_strings(array, word - 1));
				word++;
			}
			strlen = 0;
		}
		else
			strlen++;
		i++;
	}
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	int		str_num;

	if (s == 0)
		return (NULL);
	str_num = string_number(s, c);
	array = (char **)malloc((str_num + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = do_split(s, c, array, str_num);
	array[str_num] = NULL;
	return (array);
}
