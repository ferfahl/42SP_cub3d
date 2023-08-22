/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:09:53 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:24 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freeall(char **dest, int index);
static void	ft_word(char **dest, char const *src, char c);

/**
*@brief allocates and returns an array of strings obtained by splitting ’s’
*using the character ’c’ as a delimiter
*@param s : The string to be split.
*@param c: The delimiter character
*@return array of new strings resulting from the split. NULL if the allocation
*fails
*/
char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count;
	size_t	index;

	index = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[index] != '\0')
	{
		if (s[index] == c && index != 0 && s[index - 1] != c)
			count++;
		index++;
	}
	if (index != 0 && s[index - 1] != c && ft_strlen(s) > 0)
		count++;
	list = malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);
	ft_word(list, s, c);
	return (list);
}

static void	*ft_freeall(char **dest, int index)
{
	if (!dest[index])
	{
		while (index != 0)
		{
			index--;
			free(dest[index]);
		}
		free(dest);
	}
	return (NULL);
}

static void	ft_word(char **dest, char const *src, char c)
{
	size_t			len;
	unsigned int	start;
	size_t			index;

	index = 0;
	len = 0;
	start = 0;
	while (src[start + len] != '\0')
	{
		while (src[start + len] == c && src[start + len] != '\0')
			start++;
		while (src[start + len] != c && src[start + len] != '\0')
			len++;
		if (len != 0)
		{
			dest[index] = ft_substr(src, start, len);
			if (!dest[index])
				ft_freeall(dest, index);
			start = start + len;
			len = 0;
			index++;
		}
	}
	dest[index] = NULL;
}
