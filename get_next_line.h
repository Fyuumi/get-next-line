/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:53:32 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/15 20:40:05 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct y
{
	char *buff;
	char *temp;
	char *fullstring;
	int i;
	int bytesread;
	char *newrem;
	int li;

}		t_gnl_c;

char	*get_next_line(int fd);
char	*ft_strjoin_trim(char *s1, char *s2, int i, int p);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*read_add(char *rem, char **lastbuffer, int fd);
char	*buffjoin(char *buff_fullstring, char *buffer, int i, char *rem);
int		my_strn(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	my_stricpy(char *dst, const char *src, int size, int start);
char	*ft_strdup(const char *s);
#endif
