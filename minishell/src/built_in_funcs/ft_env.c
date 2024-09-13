/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:45:16 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:45:17 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	ft_env(t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	while (env)
	{
		ft_putstr_fd(env->front, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env->back, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
