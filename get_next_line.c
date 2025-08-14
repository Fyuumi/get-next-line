/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:51:38 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/05 13:36:43 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_gnl_c		y;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (my_strn(rem) != 0)
	{
		y.i = my_strn(rem);
		y.fullstring = ft_strjoin_trim("", rem, y.i);
		y.buff = ft_strjoin_trim(rem + y.i, "", 0);
		free(rem);
		rem = ft_strjoin_trim(y.buff, "", 0);
		return (free(y.buff), y.fullstring);
	}
	y.fullstring = read_add(rem, &y.lastbuffer, fd, "0");
	if (y.fullstring == NULL)
		return (NULL);
	free(rem);
	rem = NULL;
	if (y.lastbuffer)
		rem = ft_strjoin_trim("", y.lastbuffer, 0);
	return (free(y.lastbuffer), y.fullstring);
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

char	*read_add(char *rem, char **lastbuffer, int fd, char *fulls)
{
	t_gnl_c	y;

	y.buff = ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	if (!y.buff)
		return (NULL);
	while (my_strn(y.buff) <= 0)
	{
		y.bytesread = read(fd, y.buff, BUFFER_SIZE);
		if (y.bytesread == 0)
		{
			*lastbuffer = NULL;
			if (fulls && rem)
				return (free(y.buff), fulls);
			return (free(y.buff), NULL);
		}
		y.buff[y.bytesread] = '\0';
		y.i = my_strn(y.buff);
		if (fulls[0] == '0')
			fulls = ft_calloc(ft_strlen(y.buff) + ft_strlen(rem), sizeof(char));
		fulls = buffjoin(fulls, y.buff, y.i, rem);
	}
	*lastbuffer = ft_strjoin_trim("", y.buff + y.i, 0);
	return (free(y.buff), fulls);
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

char	*buffjoin(char *buff_fullstring, char *buffer, int i, char *rem)
{
	char	*temp;

	if (rem)
	{
		if (i == 0)
			i = ft_strlen(buffer);
		temp = ft_strjoin_trim(rem, buffer, i);
		return (free(buff_fullstring), temp);
	}
	if (!buff_fullstring)
	{
		if (i == 0)
			i = ft_strlen(buffer) + 1;
		temp = ft_strjoin_trim("", buffer, i);
	}
	else
		temp = ft_strjoin_trim(buff_fullstring, buffer, i);
	if (!temp)
		return (free(buff_fullstring), NULL);
	return (free(buff_fullstring), temp);
}
