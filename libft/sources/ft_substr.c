/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:02:49 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 12:32:01 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*substr;
	size_t			substrlen;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) <= start)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substrlen = 0;
	i = start;
	while (str[i] != '\0' && substrlen < len)
		substr[substrlen++] = str[i++];
	substr[substrlen] = '\0';
	return (substr);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char			*str;
		char			*substr;
		unsigned int	start;
		size_t			len;
	
		str = argv[1];
		printf("String: %s\n", str);
		start = atoi(argv[2]);
		len = atoi(argv[3]);
		substr = ft_substr(str, start, len);
		printf("Substring: %s\n", substr);
		free(substr);
	}
	return (0);
}
*/