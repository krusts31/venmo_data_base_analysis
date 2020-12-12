/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 11:41:11 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("ascii_art/welcome", O_RDONLY);
	while (ft_getline(fd, &line) == 1)
	{
		printf("%s%s\n", RED, line);
		free(line);
	}
	free(line);
	close(fd);


	printf("Please enter your user/real name\n");
}
