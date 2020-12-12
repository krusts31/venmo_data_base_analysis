/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_keyword.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:36:26 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/12 12:28:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "header.h"
#include "libft.h"

const char	*keywords[] =
{
"1P",
"5MeODMT",
"dissociatives",
"noids",
"1P_LSD",
"DissonautUniverse",
"Nootropics",
"2cb",
"DMT",
"opiates",
"4acodmt",
"DPH",
"PCP",
"adderall",
"dxm",
"phenibut",
"afinil",
"fentanyl",
"PoppyTea",
"alcohol",
"Kava",
"PsilocybinMushrooms",
"ambien",
"ketamine",
"ResearchChemicals",
"aMT",
"Kombucha",
"Salvia",
"anabolic",
"kratom",
"steroids",
"lean",
"stims",
"Ayahuasca",
"LSA",
"TheSaviorSubstances",
"benzodiazepines",
"LSD",
"treedibles",
"cannabis",
"MDMA",
"trees",
"CannabisExtracts",
"MemantineHCl",
"cocaine",
"mescaline",
"Cigarettes",
"meth",
"DrugCombos",
"modafinil",
"MrE",
"drugs",
"line",
"coke",
"alcohol",
"high",
"shroom",
"weed",
"meth",
"shrooms",
"crack",
"grass",
"dope",
"edibles",
"acid",
"heroin",
"booze",
"guns",
"sative",
"indica",
"molly",
"MDMA",
"morphine",
"speed",
"opium",
"kandy",
"not drugs",
"steroids",
"lean",
"sizzurp",
"flakka",
"kush",
"smack",
"420",
"sex",
"blow",
"head",
"strip",
"sugar",
"daddy",
"loyal",
"spoil",
"mommy",
"milk",
"strippers",
"drank",
"nudes",
"glizzy",
"mushroom",
"pill",
"eggplant",
"banana",
"aubergine",
"peach",
"water",
"needle",
"hydrohomie",
"xxx",
"I love you",
"Will you marye me",
"password",
"pas",
"kill",
"fuck",
NULL
};


size_t	ft_strings_size(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i] != NULL)
		i++;
	return (i);
}

int	find_match(char *line, t_docs *docs)
{
	char	**strings;
	size_t	i;
	int		found;

	strings = ft_split(line, ',');
	if (strings == NULL)
		return (error);
	if (ft_strings_size(strings) != 2)
		return (success);
	i = 0;
	found = 0;
	while (keywords[i] != NULL)
	{
		if (strstr(strings[0], keywords[i]) != NULL)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (keywords[i] == NULL)
	{
		ft_free_split(strings);
		return (success);
	}
	doc_pushback(docs, strings[1]);
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
	{
		perror(pathname);
		return (error);
	}
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

int	print_doc_ids(t_docs *docs)
{
	size_t	i;

	i = 0;
	while (i < docs->nmemb)
	{
		printf("%s\n", docs->doc_ids[i]);
		i++;
	}
	return (success);
}

int	get_keyword_matches(void)
{
	t_docs	*docs;
	int		ret;

	docs = doc_init(0);
	if (docs == NULL)
		return (error);
	ret = read_in_data("src/notes.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	ret = read_in_data("src/comment_one.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	ret = read_in_data("src/comment_two.txt", docs);
	if (ret == error)
	{
		ft_free_doc(docs);
		return (error);
	}
	print_doc_ids(docs);
	ft_free_doc(docs);
	return (success);
}
