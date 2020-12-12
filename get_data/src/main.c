/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 09:51:36 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 10:24:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"
#include "libft.h"

const char *keywords[] = {
	"drug",
	"coke"
};

int	find_match(char *line, t_docs **docs)
{

}

int	read_in_data(char *pathname)
{
	int		fd;
	int		ret;
	char	*line;
	t_docs	*docs;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (error);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (error);
		// do stuff with line
		free(line);
	}
	return (success);
}

int	main(void)
{
	read_in_data("notes.txt");
	return (0);
}
