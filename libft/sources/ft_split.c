/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:04:26 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 10:32:37 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	count_words(char const *str, char c)
{
	int	wcount;
	int	i;

	wcount = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			wcount++;
			i++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (wcount);
}

static char	**free_all(char **strarr, int index)
{
	while (index >= 0)
	{
		free(strarr[index]);
		index--;
	}
	free(strarr);
	return (NULL);
}

static char	**malloc_words(char **strarr, char const *str, char c)
{
	int	i;
	int	j;
	int	wlen;

	i = 0;
	j = 0;
	while (str[j] != '\0' && i < count_words(str, c))
	{
		while (str[j] == c)
			j++;
		wlen = 0;
		while (str[j] != c && str[j] != '\0')
		{
			wlen++;
			j++;
		}
		strarr[i] = (char *)malloc((wlen + 1) * sizeof(char));
		if (strarr[i] == NULL)
			return (free_all(strarr, i));
		ft_strlcpy(strarr[i++], str + (j - wlen), wlen + 1);
	}
	strarr[i] = NULL;
	return (strarr);
}

char	**ft_split(char const *str, char c)
{
	char	**strarr;
	int		wcount;

	if (str == NULL)
		return (NULL);
	wcount = count_words(str, c);
	strarr = (char **)malloc((wcount + 1) * sizeof(char *));
	if (strarr == NULL)
		return (NULL);
	strarr = malloc_words(strarr, str, c);
	return (strarr);
}
/*
#include <stdio.h>

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	**strarr;
		char	*str;
		char	delimiter;
		int		i;

		str = argv[1];
		delimiter = ' ';

		printf("String to be split: %s\n", str);
		printf("Number of Words: %i\n", count_words(str, delimiter));
		strarr = ft_split(str, delimiter);
		i = 0;
		while (i < count_words(str, delimiter))
		{
				printf("%s\n", strarr[i]);
				i++;
		}
		free(strarr);
	}
	return (0);
}
*/

// #include <stdio.h>

// int		main(void)
// {
// 	char	**strarr;
// 	char	*str;
// 	char	delimiter;
// 	int		i;

// 	str = "   1  2a,    3    --h    ";
// 	delimiter = ' ';

// 	printf("String to be split: %s\n", str);
// 	printf("Number of Words: %i\n", count_words(str, delimiter));
// 	strarr = ft_split(str, delimiter);
// 	i = 0;
// 	while (i < count_words(str, delimiter))
// 	{
// 		printf("%s\n", strarr[i]);
// 		i++;
// 	}
// 	free(strarr);
// 	return (0);
// }