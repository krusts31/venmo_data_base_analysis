/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 17:07:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 17:25:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../libft/libft.h"

typedef struct	s_user
{
	char	*username;
	int		amount;
}				t_user;

int	update_user(char *line, t_user *user)
{
	size_t	i;
	char	**strings;

	i = 0;
	strings = ft_split(line, ',');
	if (strings == NULL)
		return (-1);
	while (user[i].username != NULL)
	{
		if (ft_strcmp(strings[0], user[i].username) == 0)
		{
			user[i].amount += 1;
			break ;
		}
		i++;
	}
	if (user[i].username == NULL)
	{
		user[i].username = ft_strdup(strings[0]);
		if (user[i].username == NULL)
			return (-1);
		user[i].amount = 1;
	}
	return (0);
}

static void	swap_values(t_user *a, t_user *b)
{
	char	*tmp;
	int		i_tmp;

	
}

void	sort_users(t_user *users)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (users[i].username != NULL)
	{
		key = users[i].amount;
		j = i - 1;
		while (j >= 0)
		{
			if (key >)
			else
				break;
			j--;
		}
		swap_ptrs(users + i), &(users + j + 1));
		i++;
	}
}

int	main(void)
{
	int		fd;
	int		max[3];
	int		ret;
	char	*line;
	t_user	*users;

	fd = open("../note_data.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	users = (t_user*)ft_calloc(158442, sizeof(t_user));
	if (users == NULL)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (0);
		update_user(line, users);
		free(line);
	}
	ft_bzero(max, 3 * sizeof(int));
	for (size_t i = 0; users[i].username != NULL; i++)
	{
		printf("")
	}
	return (0);
}
