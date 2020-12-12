/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interface.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:07:33 by jhille        #+#    #+#                 */
/*   Updated: 2020/12/12 17:50:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

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
	fd = open("../files/note_data.txt", O_RDONLY);

	head = 0;
	while (ft_getline(fd, &line) != 0)
	{
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		prof = ft_split(line, ',');
		if (prof == NULL)
			return (NULL);
		if (ft_strcmp(name, prof[0]) == 0)
		{
			temp = ft_profilenew(prof);
			ft_profileadd_back(&head, temp);
			free(prof);
		}
		else
			ft_free_split(prof);
		free(line);
	}
	free(line);
	return (head);
}

void	message()
{
	printf("\n");
	printf("%sWelcome to your public Venmo information, please keep in mind that this is very REAL.%s\n\n", UBLU, reset);
}

// Function to display general info
void	general(p_list *iterate)
{
	printf("\U0001F9D2 Personal information\U0001F9D2\n\n");
	printf("Username: %s\n", iterate->username);
	printf("Name: %s\n", iterate->displayname);
	printf("\n");
}

// Function to display comments
void	comments(p_list *iterate)
{
	printf("\U0001F6A8\U0001F6A8\U0001F6A8 %sTransactions that EVERYONE can see:%s \U0001F6A8\U0001F6A8\U0001F6A8\n\n", BRED, reset);
	printf("%s - %s\n", iterate->date, iterate->comment);
	printf("\n");
}

void	help()
{
	printf("\U0001F31F Don't you worry, you can change this really quick!\n");
	printf("\U0001F31F   %s1.%s Go to your settings -> privacy.\n", BLU, reset);
	printf("\U0001F31F   %s2.%s Select your preferred default privacy setting.\n", BLU, reset);
	printf("\U0001F31F   %s3.%s Finally, make sure to click 'Save Settings'.\n", BLU, reset);
	printf("\n");
}

void	clear_scuffed_free_list(p_list *ptr)
{
	p_list *tmp;
	while (ptr != 0)
	{
		tmp = ptr->next;
		free(ptr->comment);
		free(ptr->date);
		free(ptr->displayname);
		free(ptr->username);
		free(ptr);
		ptr = tmp;
	}
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
	// while (iterate != 0)
	// {
	// 	printf("%s", iterate->username);
	// 	printf("%s: ", iterate->date);
	// 	printf("%s\n", iterate->comment);
	// 	iterate = iterate->next;
	// }

	message();
	general(iterate);
	comments(iterate);
	help();
	// free the list and all it's char pointers.
	clear_scuffed_free_list(ptr);
}
