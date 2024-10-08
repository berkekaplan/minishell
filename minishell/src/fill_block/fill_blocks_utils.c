/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_blocks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:46:55 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:46:56 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	ft_arg_size(t_expand *exp)
{
	int	i;

	i = 0;
	while (exp && !ft_is_pipe(exp->str))
	{
		if (exp->str && !ft_is_redir(exp->str))
			i++;
		else if (exp->str && ft_is_redir(exp->str))
		{
			exp = exp->next;
		}
		exp = exp->next;
	}
	return (i);
}

char	**ft_fill_args(t_expand **exp, t_block *block, int arg_cnt,
		t_data *g_data)
{
	char	**args;
	int		i;

	i = -1;
	args = (char **)malloc(sizeof(char *) * (arg_cnt + 1));
	if (!args)
		return (NULL);
	while ((*exp) && !(ft_is_pipe((*exp)->str)))
	{
		if (ft_is_redir((*exp)->str))
		{
			if (handle_redir(block, exp, g_data) == -1)
				return (NULL);
		}
		else
		{
			args[++i] = ft_trim_quotes((*exp)->str, 0, 0);
			(*exp) = (*exp)->next;
		}
	}
	args[++i] = NULL;
	return (args);
}

int	ft_count_pipe(t_expand *exp)
{
	int	cnt;

	cnt = 0;
	while (exp)
	{
		if (exp->str && exp->str[0] == '|')
		{
			if (exp->next->str && exp->next->str[0] == '|')
				return (-1);
			cnt++;
		}
		exp = exp->next;
	}
	return (cnt);
}

int	ft_is_redir(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '>' || str[0] == '<')
		return (1);
	return (0);
}

int	ft_is_pipe(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (1);
	return (0);
}
