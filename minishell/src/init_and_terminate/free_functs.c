/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:18 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:47:19 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	free_pipes(int **pipefd, int cnt)
{
	int	i;

	i = 0;
	if (!pipefd)
		return ;
	while (i < cnt)
	{
		if (pipefd[i])
		{
			close(pipefd[i][0]);
			close(pipefd[i][1]);
			free(pipefd[i]);
		}
		i++;
	}
	free(pipefd);
}

void	free_string(char *str)
{
	if (str)
		free(str);
}

void	free_matrix(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free (str[i]);
	free(str);
	str = NULL;
}

void	free_blocks(t_block *blocks)
{
	if (!blocks)
		return ;
	free_string(blocks->cmd_name);
	free_matrix(blocks->args);
	free(blocks);
}

void	free_exp(t_expand *exp)
{
	t_expand	*tmp;

	if (!exp)
		return ;
	while (exp)
	{
		tmp = exp;
		exp = exp->next;
		free(tmp->str);
		free(tmp);
	}
}
