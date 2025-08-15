/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:51:53 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:19 by opaulman         ###   ########.fr       */
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

size_t	my_stricpy(char *dst, const char *src, int size, int start)
{
	int	i;
	int	p;

	i = start;
	p = 0;
	while (src[p] != '\0' && i < (start + size))
	{
		dst[i] = src[p];
		i++;
		p++;
	}
	dst[i] = '\0';
	return (i);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp_m;
	size_t			k;
	size_t			total;

	total = nmemb * size;
	temp_m = malloc(total);
	if (temp_m == NULL)
		return (NULL);
	k = 0;
	while (k < total)
	{
		temp_m[k] = 0;
		k++;
	}
	return (temp_m);
}
int	my_strn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
char	*ft_strdup(const char *s)
{
	char *string;
	size_t len_s;

	len_s = ft_strlen(s) + 1;
	string = ft_calloc(len_s, sizeof(char));
	if (string == 0)
	{
		return (NULL);
	}
	ft_strlcpy(string, s, len_s);
	return (string);
}