/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:45:42 by opaulman          #+#    #+#             */
/*   Updated: 2025/08/15 20:07:42 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_num;

	line_num = 1;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Fehler beim Öffnen von file.txt");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Zeile %d: %s", line_num, line);
		free(line);
		line_num++;
	}
	close(fd);
	return (0);
}
