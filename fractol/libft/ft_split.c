/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:14:43 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/24 13:06:45 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **array, int i)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
}

static char	**ft_arrayalloc(char const *s, char c)
{
	int		i;
	int		substrcount;
	char	**substrarray;

	i = 0;
	substrcount = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			substrcount++;
		i++;
	}
	substrarray = (char **)malloc((substrcount + 1) * sizeof(char *));
	return (substrarray);
}

static int	ft_fill_array(char **splitarray, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			splitarray[j] = ft_substr(s, start, i - start);
			if (!splitarray[j])
				return (ft_free_all(splitarray, j - 1), 0);
			j++;
		}
	}
	splitarray[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splitarray;

	if (!s)
		return (NULL);
	splitarray = ft_arrayalloc(s, c);
	if (!splitarray)
		return (NULL);
	if (!ft_fill_array(splitarray, s, c))
		return (NULL);
	return (splitarray);
}
