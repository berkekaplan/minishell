/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:44:30 by mkaplan           #+#    #+#             */
/*   Updated: 2023/12/04 17:42:26 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*after_dollar(char *key, char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (tmp[i] != key[j])
		i++;
	while (tmp[i] && tmp[i] == key[j])
	{
		i++;
		j++;
		if (!key[j] && (tmp[i] > 0))
		{
			if (tmp[i] == 0)
				return (NULL);
			str = ft_substr(tmp, i, ft_strlen(tmp));
			return (str);
		}
	}
	return (NULL);
}
