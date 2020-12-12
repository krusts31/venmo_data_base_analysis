/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:03:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 11:06:10 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stddef.h>
# include <stdio.h> // rm

typedef enum	e_errnums
{
	success,
	error
}				t_errnums;

/*
** First keywords are found, then matching doc IDs are saved
*/

typedef struct	s_docs
{
	char	**doc_ids;
	size_t	nmemb;
	size_t	size;
}				t_docs;

/*
** find_keyword.c
*/

int	get_keyword_matches(void);

/*
** doc_management.c
*/

t_docs	*doc_init(size_t initial_size);
int		doc_realloc(t_docs *docs);
int		doc_pushback(t_docs *docs, char *id);
void	ft_free_doc(t_docs *docs);

#endif
