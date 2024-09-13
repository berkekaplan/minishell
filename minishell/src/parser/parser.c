/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:49:16 by mkaplan           #+#    #+#             */
/*   Updated: 2023/12/04 17:44:42 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	ft_words_nbr(char *str, int idx, int word_count)
{
	char	quote;

	quote = 0;
	while (str[idx] != '\0')
	{
		quote = 0;
		while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
			idx++;
		if (str[idx] && ft_is_quote(str[idx]))
		{
			word_count++;
			quote = str[idx];
			idx++;
			while (str[idx] && str[idx] != quote)
				idx++;
			idx++;
			while (str[idx] != '\0' && !ft_is_delimiter(str[idx])
				&& !ft_is_quote(str[idx]))
				idx++;
		}
		else if (str[idx] && !ft_is_delimiter(str[idx]) && word_count++ > -1)
			idx = find_len_util(str, idx, quote);
	}
	return (word_count);
}

static char	*ft_get_word_quote(char *str, char quote)
{
	int		idx;
	char	*word;
	int		len;

	idx = 1;
	while (str[idx] != '\0' && str[idx] != quote)
		idx++;
	if (str[idx])
		idx++;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx])
		&& !ft_is_quote(str[idx]))
		idx++;
	len = idx;
	if (idx == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	idx = -1;
	while (++idx < len)
		word[idx] = str[idx];
	word[idx] = '\0';
	return (word);
}

static char	*ft_get_word(char *str, int a, int idx, char is_quote)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (ft_get_word_len(str) + 1));
	if (!word)
		return (NULL);
	while (str[idx] != '\0' && (!ft_is_delimiter(str[idx]) || is_quote > 0))
	{
		if (str[idx + 1] && ((a % 2 == 0 && str[idx + 1] == ' ')
				|| (is_quote > 0 && is_quote == str[idx]
					&& str[idx + 1] == ' ')))
		{
			word[idx] = str[idx];
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
		{
			is_quote = str[idx];
			a++;
		}
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	*parse_with_type(char *str, char **split, int idx)
{
	char	*ret;

	if (ft_is_quote(*str))
	{
		ret = ft_get_word_quote(str, *str);
		if (ret)
			split[idx] = ret;
		str += ft_strlen(ret);
	}
	else
	{
		ret = ft_get_word(str, 0, 0, 0);
		if (ret)
			split[idx] = ret;
		str += ft_strlen(ret);
	}
	return (str);
}

char	**ft_parser(char *str, int idx)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_words_nbr(str, 0, 0) + 1));
	if (!split)
		return (NULL);
	while (*str && (*str || ft_is_delimiter(*str)))
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			str = parse_with_type(str, split, idx);
			idx++;
		}
	}
	split[idx] = NULL;
	return (split);
}
