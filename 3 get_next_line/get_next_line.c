/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:51:38 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/02 16:24:20 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	tgnl_c		y;
	static char	*remainders;
	char		*savedbuffer;
	char		*lastbuffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (remainders)
			free(remainders);
		return (remainders = NULL);
	}
	if (!remainders)
	{
		remainders = ft_strdup("");
		if (!remainders)
			return (NULL);
	}
	if (my_strn(remainders) != 0) // if nextline in remainder
	{
		y.i = my_strn(remainders);
		savedbuffer = ft_strjoin_trim(remainders, "", y.i);
		remainders = ft_strdup(remainders + y.i);
		return (savedbuffer);
	}
	savedbuffer = buff_to_savebuff(remainders, &lastbuffer, fd, &y.bytesread);
	if (savedbuffer == NULL)
		return (NULL);
	remainders = NULL;
	free(remainders);
	if (lastbuffer != NULL)
		remainders = ft_strdup(lastbuffer);
	if (savedbuffer == NULL)
		return (free(lastbuffer), NULL);
	return (free(lastbuffer), savedbuffer);
}

int	my_strn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*buff_to_savebuff(char *remain_savedbuff, char **lastbuffer, int fd,
		int *i)
{
	tgnl_c	y;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	y.i = -1;
	while (y.i <= 0)
	{
		y.bytesread = read(fd, buffer, BUFFER_SIZE);
		if (y.bytesread < 0 || ((y.bytesread == 0) && (y.i == -1)))
			return (free(buffer), free(remain_savedbuff), NULL);
		if (y.bytesread == 0)
		{
			*lastbuffer = NULL;
			*i = y.bytesread;
			return (remain_savedbuff);
		}
		y.i = my_strn(buffer);
		buffer[y.bytesread] = '\0';
		remain_savedbuff = ft_strjoin_trim(remain_savedbuff, buffer, y.i);
		if (!remain_savedbuff)
			return (free(buffer), NULL);
	}
	*lastbuffer = ft_strdup(buffer + y.i);
	return (free(buffer), remain_savedbuff);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp_m;
	size_t			k;

	k = nmemb * size;
	temp_m = malloc(k);
	if (temp_m == 0)
	{
		return (NULL);
	}
	ft_memset(temp_m, 0, k);
	return (temp_m);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}