/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:45:42 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/05 13:39:23 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = "hey";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		printf("%c", '\n');
		free(line);
	}
	close(fd);
	return (0);
}
