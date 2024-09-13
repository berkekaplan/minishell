/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:44 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:39:45 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	if (s1 != NULL)
	{
		while (0 < i)
		{
			str[i] = s1[i];
			i--;
		}
		str[i] = s1[i];
		return (str);
	}
	free(str);
	return (NULL);
}
