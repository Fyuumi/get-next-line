/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:51:38 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/15 18:51:29 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_gnl_c		y;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (my_strn(rem) > 0) // if a nextline is in the buffer
	{
		y.i = my_strn(rem);
		y.fullstring = ft_strjoin_trim("", rem, y.i, 0);
		if (rem[y.i] != '\0')
		{
			y.newrem = ft_strdup(rem + y.i);
			free(rem);
			rem = y.newrem;
			y.newrem = NULL;												
		}
		else
		{
			free(rem);
			rem = NULL;
		}
		return (y.fullstring);
	}
	y.fullstring = read_add(rem, &y.newrem, fd);
	if (y.fullstring == NULL) // important for the last read
		return (NULL);
	if (y.newrem)
	{
		rem = ft_strjoin_trim("", y.newrem, 0, 2);
		free(y.newrem);
		y.newrem = NULL;
	}
	else
		rem = NULL;
	return (y.fullstring);
}
// strjoin_trim is only joining the string till i character like strlcopy
char	*ft_strjoin_trim(char *s1, char *s2, int i, int p)
{
	t_gnl_c	y;
	int		ls;

	if (s1[0] == '\0' || !s1)
		ls = 0;
	else
		ls = ft_strlen(s1);
	y.li = ft_strlen(s2);
	if (i > 0 && i < y.li)
		y.li = i;
	y.temp = (char *)ft_calloc(ls + y.li + 1, sizeof(char));
	if (!y.temp)
		return (NULL);
	if (ls > 0)
		y.i = my_stricpy(y.temp, s1, ls, 0);
	else
		y.i = 0;
	if (y.li > 0)
		my_stricpy(y.temp, s2, y.li, y.i);
	if (p == 1)
	{
		free(s1);
		s1 = NULL;
	}
	if (p == 2)
	{
		free(s2);
		s2 = NULL;
	}
	return (y.temp[ls + y.li] = '\0', y.temp);
}

char	*read_add(char *rem, char **newrem, int fd)
{
	t_gnl_c	y;

	y.buff = ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	if (!y.buff)
		return (NULL);
	y.temp = NULL;
	while (1)
	{
		y.bytesread = read(fd, y.buff, BUFFER_SIZE);
		if (y.bytesread < 0)
			return (free(y.buff), NULL);
		y.buff[y.bytesread] = '\0';
		y.i = my_strn(y.buff);
		y.temp = buffjoin(y.temp, y.buff, y.i, rem);
		rem = NULL;
		if (y.i > 0)
		{
			*newrem = ft_strjoin_trim("", y.buff + y.i, 0, 0);
			break ;
		}
		if (y.bytesread == 0)
			break ;
	}
	return (free(y.buff), y.temp);
}

char	*buffjoin(char *buff_fullstring, char *buffer, int i, char *rem)
{
	char	*temp;

	if (rem)
	{
		if (i == 0)
			i = ft_strlen(buffer);
		if (i == 0) // bytesread 0 and rem
			temp = ft_strjoin_trim("", rem, i, 2);
		else
			temp = ft_strjoin_trim(rem, buffer, i, 1);
		return (temp);
	}
	if (!buff_fullstring)
	{
		if (buffer)
		{
			temp = ft_strjoin_trim("", buffer, i, 0);
			return (temp);
		}
		return (NULL);
	}
	temp = ft_strjoin_trim(buff_fullstring, buffer, i, 1);
	return (temp);
}
