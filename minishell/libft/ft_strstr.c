/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:41:31 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:41:32 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	int	i;
	int	j;
	int	l_i;

	i = -1;
	if (!big)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i])
	{
		l_i = 0;
		if (big[i] == little[l_i])
		{
			j = i;
			while (big[j] == little[l_i])
			{
				l_i++;
				j++;
				if (little[l_i] == '\0')
					return ((char *)(big + i));
			}
		}
	}
	return (0);
}
