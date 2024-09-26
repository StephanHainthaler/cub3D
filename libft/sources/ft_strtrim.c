/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:04:00 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/20 17:04:48 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	ft_isset(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char			*strtrim;
	unsigned int	i;
	unsigned int	trimstart;
	unsigned int	trimend;

	trimstart = 0;
	while (str[trimstart] != '\0'
		&& ft_isset((char *)set, str[trimstart]) == 1)
		trimstart++;
	trimend = ft_strlen(str);
	while (trimend > trimstart && ft_isset((char *)set, str[trimend - 1]) == 1)
		trimend--;
	strtrim = (char *)malloc(((trimend - trimstart) + 1) * sizeof(char));
	if (strtrim == NULL)
		return (NULL);
	i = 0;
	while (trimstart < trimend)
		strtrim[i++] = str[trimstart++];
	strtrim[i] = '\0';
	return (strtrim);
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char    *str;
        char    *charset;
        char    *strtrim;

        str = argv[1];
        charset = argv[2];
        printf("String: %s\n", str);
        printf("Character Set: %s\n", charset);
        strtrim = ft_strtrim(str, charset);
        printf("Trimmed String: %s\n", strtrim);
        free(strtrim);
    }

    return (0);
}
*/
