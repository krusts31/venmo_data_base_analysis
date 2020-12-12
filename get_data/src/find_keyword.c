/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_keyword.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:36:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 11:28:49 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"
#include "libft.h"

int	find_match(char *line, t_docs *docs)
{
	char	**strings;

	strings = ft_split(line, ',');
	if (strings == NULL)
		return (error);
	
	ft_free_split(strings);
	return (success);
}

int	read_in_data(char *pathname, t_docs *docs)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (error);
	ret = 1;
	while (ret > 0)
	{
		ret = ft_getline(fd, &line);
		if (ret == -1)
			return (error);
		if (*line != '\0');
			find_match(line, docs);
		free(line);
	}
	close(fd);
	return (success);
}



int	get_keyword_matches(void)
{
	t_docs	*docs;
	int		ret;

	docs = doc_init(0);
	if (docs == NULL)
		return (error);
	ret = read_in_data("input.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	ret = read_in_data("comment_one.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	ret = read_in_data("comment_two.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	ft_free_doc(docs);
	return (success);
}
