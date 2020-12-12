/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 12:33:04 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "template/template.h"

char name[100];

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

	printf("\nAre you ready to dig up some dirty laundry? Please enter your user/real name:\n");
	scanf("%s", name);
	message();
	general();
	comments();
	help();
}
