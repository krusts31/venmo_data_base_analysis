/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   template.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:17:35 by kfu           #+#    #+#                 */
/*   Updated: 2020/12/12 11:38:58 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define KRED  "\x1B[31m"
#define RESET "\x1B[0m"

char *str = "Replace";
char *comment = "Best head ever \U0001F346 \U0001F4A7";
char *comment1 = "Strippers \U0001F351";

void	message()
{
	printf("Welcome to your public Venmo information, please keep in mind that this is very REAL.\n\n");
}

// Function to display general info
void	general()
{
	printf("\U0001F9D2 Personal information:\n\n");
	printf("Username: %s\n", str);
	printf("First name: %s\n", str);
	printf("Last name: %s\n", str);
	printf("\n");
}

// Function to display comments
void	comments()
{
	printf("\U0001F6A8\U0001F6A8\U0001F6A8 Transactions that EVERYONE can see: \U0001F6A8\U0001F6A8\U0001F6A8\n\n");
	printf("1. %s\n", comment);
	printf("2. %s\n", comment1);
	printf("\n");
}

void	help()
{
	printf("Did you know this? If not, you can change this very easily in your settings.\n");
	printf("1. Instructions.\n");
}

int		main()
{
	message();
	general();
	comments();
	help();
}
