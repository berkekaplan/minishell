/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:30 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/30 14:40:57 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

static void	ft_error1(char type, t_block *block)
{
	if (type == 'u')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (type == 'p')
	{
		ft_putstr_fd(" pipe open error\n", 2);
	}
	else if (type == 'q')
	{
		ft_putstr_fd("I cant handle '||'\n", 2);
	}
	else if (type == 'x')
	{
		ft_putstr_fd("no command after pipe\n", 2);
	}
}

static void	ft_error2(char type)
{
	if (type == 'm')
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
	}
	else if (type == ';' || type == 's')
	{
		ft_putstr_fd("I cant handle ';' or ';;'\n", 2);
	}
	else if (type == '\\')
	{
		ft_putstr_fd("I cant handle '\\'\n", 2);
	}
	else if (type == 'r')
	{
		ft_putstr_fd("No file after redirection\n", 2);
	}
}

int	ft_error(char type, t_block *block)
{
	ft_putstr_fd("minishell: ", 2);
	if (type == 'u' || type == 'p' || type == 'q' || type == 'x')
		ft_error1(type, block);
	else if (type == ';' || type == '\\' || type == 'r' || type == 'm')
		ft_error2(type);
	else if (type == 'd')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": is a directory\n", 2);
		free_blocks(block);
	}
	else if (type == 'e')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(block->args[1], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	return (1);
}

int	ft_sspace_pipe(char *input, int i)
{
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		return (0);
	}
	return (1);
}

int	ft_cntrl(char *input)
{
	if (!ft_sspace_pipe(input, 0))
		return (0);
	if ((input[0] == '\"' && input[1] == '\"') || (input[0] == '\''
			&& input[1] == '\''))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(": command not found\n", 2);
		return (0);
	}
	if (ft_strchr(input, ';') != (char *)0)
	{
		ft_error(';', 0);
		return (0);
	}
	if (ft_strchr(input, '\\') != (char *)0)
	{
		ft_error('\\', 0);
		return (0);
	}
	return (1);
}
