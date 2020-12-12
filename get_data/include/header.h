/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:03:07 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 10:24:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef enum	e_errnums
{
	success,
	error
}				t_errnums;

typedef struct	s_docs
{
	char	*doc_id;
	char	*username;
	size_t	size;
}				t_docs;

#endif
