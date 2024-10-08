/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:44:06 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:44:06 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*front;
	char			*back;
	struct s_env	*next;
}					t_env;

typedef struct s_expand
{
	char				*str;
	struct s_expand		*next;
}	t_expand;

typedef struct s_data
{
	t_env		*environmental;
	t_expand	*exp;
	int			exit_status;
	char		**env;
	int			**fd_pipe;
	int			fd_heredoc[2];
	int			block_cnt;
	char		*default_prompt;
}				t_data;

typedef struct s_block
{
	char	*cmd_name;
	char	**args;
	int		infile;
	int		outfile;
}	t_block;

#endif
