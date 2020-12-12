/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 12:12:57 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	printascii(int fd)
{
	char *line;
	while (ft_getline(fd, &line) == 1)
	{
		printf("%s%s%s\n", RED, line, reset);
		free(line);
	}
	free(line);
}

int	main(void)
{
	int	fd;

	fd = open("ascii_art/welcome", O_RDONLY);
	printascii(fd);
	close(fd);


	printf("Please enter your user/real name\n");
}
