/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 16:36:02 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "template/template.h"

char name[100];

void	printascii(char *pathname, char *colour, int delay)
{
	int	fd;
	fd = open(pathname, O_RDONLY);

	char *line;
	while (ft_getline(fd, &line) == 1)
	{
		printf("%s%s%s\n", colour, line, reset);
		usleep(delay);
		free(line);
	}
	free(line);
	close(fd);
}

void	nextslide(char *question)
{
	int	i;
	char	answer[30];
	
	i = 0;
	if (question != NULL)
	{
		printf("%s", question);
		scanf("%s", answer);
	}
	while (i < 100)
	{
		printf("\n");
		usleep(10000);
		i++;
	}
}

p_lst	*findname(char *name, char **profile)
{
	int	fd;
	char	*line;
	p_list	*head;
	p_list	*temp;
	fd = open("test.txt", O_RDONLY);
	
	while (ft_getline(fd, &line) != 0)
	{
		profile = ft_split(line, ',');
		if (ft_strncmp(name, profile[0]) == 0)
		{
			temp = ft_lstnew(
			
		}
	}
}

int	main(void)
{
	int	msec;
	char	**profile;

	msec = 0;
	printascii("ascii_art/welcome", YEL, 1);
	printf("\n%s			Continue?%s\n", BLU, reset);
	scanf("%s", name);
	if (ft_strnstr(name, "no", 10) != NULL)
		return (0);
	system("clear");
	printascii("ascii_art/continue", RED, 100000);
	printf("\n%s			Please enter your user/real name:%s\n", BLU, reset);
	ft_memset(name, 0, 50);
	scanf("%s", name);
	findname(name, profile);
	message();
	general();
	comments();
	help();
}
