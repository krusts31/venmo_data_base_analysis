/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 13:48:57 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "template/template.h"

char name[100];

void	printascii(char *pathname, char *colour)
{
	int	fd;
	fd = open(pathname, O_RDONLY);

	char *line;
	while (ft_getline(fd, &line) == 1)
	{
		printf("%s%s%s\n", colour, line, reset);
		free(line);
	}
	free(line);
	close(fd);
}

int	main(void)
{
	int	msec;

	msec = 0;
	
	printascii("ascii_art/welcome", YEL);
	printf("\nAre you ready to dig up some dirty laundry? Please enter your user/real name:\n");
	scanf("%s", name);
	message();
	general();
	comments();
	help();
}
