/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:41:46 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:41:47 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	c;
	size_t	f;

	f = 0;
	c = start;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (f < len && s[f + start] != '\0')
		f++;
	str = malloc((f + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[c] != '\0')
		str[i++] = s[c++];
	str[i] = '\0';
	return (str);
}
