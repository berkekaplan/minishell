/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:35 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:47:35 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	free_env_node(t_env *env)
{
	free_string(env->front);
	free_string(env->back);
	free(env);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (env)
	{
		tmp = env;
		env = env->next;
		free_string(tmp->front);
		free_string(tmp->back);
		free(tmp);
	}
}

void	ft_exit(char *str, int status, t_data	*g_data)
{
	free_env(g_data->environmental);
	free_matrix(g_data->env);
	free(g_data);
	if (status == 0)
		ft_putstr_fd(str, 1);
	else if (status == 1)
		ft_putstr_fd(str, 1);
	exit(0);
}

void	ft_exit_start(char *str, t_data	*g_data)
{
	if (g_data)
		free(g_data);
	ft_putstr_fd(str, 1);
	exit(0);
}
