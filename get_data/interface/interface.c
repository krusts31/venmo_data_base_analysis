/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 17:23:08 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"
#include "template/template.h"

char	name[100];

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

p_list	*findname(char *name, char **prof)
{
	int	fd;
	char	*line;
	p_list	*head;
	p_list	*temp;
	fd = open("test.txt", O_RDONLY);
	
	while (ft_getline(fd, &line) != 0)
	{
		prof = ft_split(line, ',');
		if (ft_strncmp(name, prof[0], ft_strlen(prof[0])) == 0)
		{
			temp = ft_profilenew(prof);
			ft_profileadd_back(&head, temp);
		}
	}
	return (head);
}

int	main(void)
{
	int	msec;
	char	**prof;
	p_list	*ptr;
	p_list	*iterate;

	prof = 0;
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

	ptr = findname(name, prof);
	iterate = ptr;	
	while (iterate != 0)
	{
		printf("%s", iterate->username);
		iterate = iterate->next;
	}

	message();
	general();
	comments();
	help();
}
