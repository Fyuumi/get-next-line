/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:51:53 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/05 12:40:45 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	p;
	size_t	i;

	p = ft_strlen(src);
	if (size == 0)
	{
		return (p);
	}
	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (p);
}

// strjoin_trim is only joining the string till i character like strlcopy
char	*ft_strjoin_trim(char *s1, char const *s2, int i)
{
	char	*string;
	int		ls;
	int		li;

	ls = ft_strlen(s1);
	li = ft_strlen(s2);
	if (i > 0)
		li = i;
	if (i == -1)
		li += 1;
	string = (char *)ft_calloc(ls + li + 1, sizeof(char));
	if (!string)
		return (0);
	if (ls > 0)
		ft_strlcpy(string, s1, ls + 1);
	if (li > 0)
		ft_strlcat(string, s2, ls + li);
	string[ls + li] = '\0';
	return (string);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	if (dst[0] == '\0')
		lend = 0;
	else
		lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (size <= lend)
		return (lens + size);
	while (i < size - lend && src[i] != '\0')
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lens + lend);
}

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	string = malloc(len_s * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s, len_s);
	return (string);
}
