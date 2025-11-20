/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:48:06 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/20 19:02:01 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < (int)(size * nmemb))
		result[i] = 0;
	return ((void *)result);
}

char	*ft_realloc(char *str, int old_len, int new_len)
{
	char	*new_str;
	int		i;

	new_str = ft_calloc(new_len + 1, sizeof(char));
	i = 0;
	while (i < old_len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	y;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		result[i] = s1[i];
	y = -1;
	while (++y < ft_strlen(s2))
		result[i + y] = s2[y];
	result[i + y] = '\0';
	free(s1);
	return (result);
}
