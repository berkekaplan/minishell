/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:46:49 by mkaplan           #+#    #+#             */
/*   Updated: 2023/12/01 21:45:29 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include "libft.h"

static int	handle_pipe(t_block *block, int idx, t_data *g_data)
{
	if ((idx != 0 && idx < g_data->block_cnt - 1))
	{
		if (block->infile == 0)
			block->infile = g_data->fd_pipe[idx - 1][0];
		if (block->outfile == 1)
			block->outfile = g_data->fd_pipe[idx][1];
	}
	else if (idx == 0 && idx < g_data->block_cnt - 1 && block->outfile == 1)
	{
		block->outfile = g_data->fd_pipe[idx][1];
	}
	else if (idx != 0 && idx == g_data->block_cnt - 1)
	{
		if (block->infile == 0)
			block->infile = g_data->fd_pipe[idx - 1][0];
		if (block->outfile == 1)
			block->outfile = 1;
	}
	return (1);
}

int	handle_redir(t_block *block, t_expand **exp, t_data *g_data)
{
	char	*filename;

	filename = ft_trim_quotes((*exp)->next->str, 0, 0);
	if (!(*exp) || !(*exp)->str || !(*exp)->next || !(*exp)->next->str)
		return (-1);
	if ((*exp)->str[0] == '>' && (*exp)->str[1] == '>')
		block->outfile = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if ((*exp)->str[0] == '<' && (*exp)->str[1] == '<')
		handle_heredoc_file(block, filename, g_data);
	else if ((*exp)->str[0] == '>')
		block->outfile = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if ((*exp)->str[0] == '<')
		block->infile = open(filename, O_RDONLY);
	if (block->infile == -1 || block->outfile == -1)
	{
		ft_redir_error(block, (*exp)->next->str, filename);
		g_data->exit_status = 1;
		return (-1);
	}
	*exp = (*exp)->next->next;
	free(filename);
	return (1);
}

int	ft_get_block(t_expand **exp, t_block *cmd_blocks, int indx, t_data *g_data)
{
	while (*exp && !ft_is_pipe((*exp)->str))
	{
		if (ft_is_redir((*exp)->str))
		{
			if (handle_redir(cmd_blocks, exp, g_data) == -1)
				return (-1);
		}
		else if (!(cmd_blocks->cmd_name))
		{
			cmd_blocks->cmd_name = ft_trim_quotes((*exp)->str, 0, 0);
			cmd_blocks->args = ft_fill_args(exp, cmd_blocks, ft_arg_size(*exp),
					g_data);
			if (!(cmd_blocks->args))
				return (-1);
			handle_pipe(cmd_blocks, indx, g_data);
		}
		else
			*exp = (*exp)->next;
	}
	if (*exp)
		*exp = (*exp)->next;
	return (1);
}

static int	init_pipe(int cnt, t_data *g_data)
{
	int	**pipefd;
	int	i;

	i = 0;
	g_data->block_cnt = cnt + 1;
	pipefd = (int **)malloc(sizeof(int *) * (cnt + 1));
	if (!pipefd)
		return (-1);
	while (i < cnt + 1)
	{
		pipefd[i] = (int *)malloc(sizeof(int) * 2);
		if (!(pipefd[i]))
			return (-1);
		if (pipe(pipefd[i]) == -1)
		{
			ft_error('p', NULL);
			return (-1);
		}
		i++;
	}
	g_data->fd_pipe = pipefd;
	return (0);
}

int	ft_fill_block(t_expand *exp, t_data *g_data)
{
	int		cnt;
	int		indx;
	t_block	*cmd_block;

	cnt = ft_count_pipe(exp);
	if (cnt == -1)
		return (-2);
	init_pipe(cnt, g_data);
	indx = 0;
	while (exp)
	{
		cmd_block = (t_block *)ft_calloc(sizeof(t_block), 1);
		if (!cmd_block)
			return (-1);
		cmd_block->outfile = 1;
		if (ft_get_block(&exp, cmd_block, indx, g_data) == -1)
			return (-1);
		if (cmd_block->cmd_name != 0 && *(cmd_block->cmd_name) != '\0')
			exec_ft(cmd_block, indx, g_data);
		wait(NULL);
		free_blocks(cmd_block);
		cmd_block = NULL;
		indx++;
	}
	return (0);
}
