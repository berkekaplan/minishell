/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:44:00 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:44:00 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ORANGE "\033[91m"
# define GREY "\033[90m"
# define DEFAULT "\033[0m"

# include <stdio.h>
# include "struct.h"

extern int	g_sin;

t_env		*ft_new_env(char *str, t_data *g_data);
t_expand	*ft_add_tail_expander(t_expand *head, char *str);
t_expand	*ft_expander(char **line, int i, int j, t_data *g_data);
t_expand	*ft_handle_special_signs(t_expand *head, t_expand *tmp, char *type);
t_expand	*check_special_char(t_expand *head, t_expand *temp);
t_expand	*subsplit(t_expand *expander);
t_env		*ft_new_list(void);
int			ft_is_valid_env(char *str, t_data *g_data);
int			ft_cd(t_block *cmd, t_data *g_data);
int			ft_echo(t_block *cmd);
int			ft_env(t_data *g_data);
int			ft_exit_b(t_block *cmd, t_data *g_data);
int			ft_export(t_block *cmd, t_data *g_data);
int			ft_pwd(void);
int			ft_unset(t_block *cmd, t_data *g_data);
int			exec_ft(t_block *block, int indx, t_data *g_data);
int			ft_get_path(t_block *block, char **path, t_data *g_data);
int			i_x(char c, char x);
int			is_in_single_quote(char *str, int indx);
int			handle_redir(t_block *block, t_expand **exp, t_data *g_data);
int			ft_get_block(t_expand **exp, t_block *cmd_blocks, int indx,
				t_data *g_data);
int			ft_fill_block(t_expand *exp, t_data *g_data);
int			ft_ultimate_check(const char *s1, const char *s2);
int			ft_arg_size(t_expand *exp);
int			ft_count_pipe(t_expand *exp);
int			ft_is_redir(char *str);
int			ft_is_pipe(char *str);
int			ft_error(char type, t_block *block);
int			find_len_util(char *str, int idx, char quote);
int			ft_get_word_len(char *str);
int			ft_is_delimiter(char c);
int			ft_is_quote(char c);
int			ft_index_of_equal_sign(char *str);
int			ft_quote_check(char *input);
int			check_strange_chars(t_expand *exp);
int			main(int argc, char **argv, char **env);
int			ft_cntrl(char *input);
int			ft_sspace_pipe(char *input, int i);
char		**ft_env_to_matrix(t_data *g_data);
char		*ft_search_env(char *splitted_input, t_data *g_data);
char		**ft_fill_args(t_expand **exp, t_block *block, int arg_cnt,
				t_data *g_data);
char		*ft_trim_quotes(char *str, int i, int len);
char		*parse_with_type(char *str, char **split, int idx);
char		**ft_parser(char *str, int idx);
char		*ft_strsub(char *str, int start, int end);
char		*ft_prompt(void);
char		*after_dollar(char *key, char *tmp);
char		**ft_copy_matrix(char **matrix);
char		*ft_strstr(char *big, char *little);
void		ft_delete_env(char *str, t_data *g_data);
void		ft_change_env(char *str, char *new_value, t_data *g_data);
void		ft_redir_error(t_block *block, char *str, char *filename);
void		ft_get_heredoc_lines(char *delim, int fd, t_data *g_data);
void		handle_heredoc_file(t_block *block, char *delim, t_data *g_data);
void		free_pipes(int **pipefd, int cnt);
void		free_string(char *str);
void		free_matrix(char **str);
void		free_blocks(t_block *blocks);
void		free_exp(t_expand *exp);
void		ft_banner(void);
void		free_env_node(t_env *env);
void		free_env(t_env *env);
void		ft_exit_start(char *str, t_data	*g_data);
void		ft_exit(char *str, int status, t_data *g_data);
void		sig_int(int sig);
void		ft_signal(int flag, t_data *g_data);
void		ft_add_tail(t_env *new, t_env **head);
void		ft_fill_env(char **env, t_data *g_data);
void		set_and_execute(char *input, t_data *g_data);
void		ft_start_proccess(t_data *g_data);
void		ft_ft_ft(t_data *g_data);
void		ft_pipe_process(t_block *block, t_data *g_data, int indx);

#endif
