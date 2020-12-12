/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   template.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:17:35 by kfu           #+#    #+#                 */
/*   Updated: 2020/12/12 12:33:49 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "colors.h"

char *str = "Replace";
char *comment = "Best head ever \U0001F346 \U0001F4A7";
char *comment1 = "Strippers \U0001F351";

void	message()
{
	printf("\n");
	printf("%sWelcome to your public Venmo information, please keep in mind that this is very REAL.%s\n\n", UBLU, reset);
}

// Function to display general info
void	general()
{
	printf("\U0001F9D2 Personal information\U0001F9D2\n\n");
	printf("Username: %s\n", str);
	printf("First name: %s\n", str);
	printf("Last name: %s\n", str);
	printf("\n");
}

// Function to display comments
void	comments()
{
	printf("\U0001F6A8\U0001F6A8\U0001F6A8 %sTransactions that EVERYONE can see:%s \U0001F6A8\U0001F6A8\U0001F6A8\n\n", BRED, reset);
	printf("01/01/2020 - %s\n", comment);
	printf("21/08/2020 - %s\n", comment1);
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
