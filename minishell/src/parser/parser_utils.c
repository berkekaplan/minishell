/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:49:09 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:49:09 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_len_util(char *str, int idx, char quote)
{
	int	a;

	a = 0;
	while (str[idx] && (!ft_is_delimiter(str[idx]) || quote > 0))
	{
		if (str[idx + 1] && ((a % 2 == 0 && str[idx + 1] == ' ') || (quote > 0
					&& quote == str[idx] && str[idx + 1] == ' ')))
		{
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
		{
			quote = str[idx];
			a++;
		}
		idx++;
	}
	return (idx);
}

int	ft_get_word_len(char *str)
{
	int		idx;
	char	is_quote;
	int		a;

	a = 0;
	idx = 0;
	is_quote = 0;
	while (str[idx] != '\0' && (!ft_is_delimiter(str[idx]) || is_quote > 0))
	{
		if (str[idx + 1] && ((a % 2 == 0 && str[idx + 1] == ' ')
				|| (is_quote > 0 && is_quote == str[idx]
					&& str[idx + 1] == ' ')))
		{
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
		{
			is_quote = str[idx];
			a++;
		}
		idx++;
	}
	return (idx);
}

int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}
