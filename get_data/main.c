/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 09:51:36 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 10:06:08 by mraasvel      ########   odam.nl         */
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

int	read_in_data(char *pathname)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (error);
	ret = 1;
}

int	main(void)
{
	return (0);
}
