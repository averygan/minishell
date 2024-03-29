/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:31:24 by agan              #+#    #+#             */
/*   Updated: 2024/01/29 17:31:25 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

enum e_node_type
{
	LEFT_NODE,
	RIGHT_NODE,
	PARENT_NODE,
};

// Exec command functions
void	exec_simple_cmd(char **argv, t_minishell *minishell, int pid);
void	exec_command(t_node *node, t_minishell *minishell, \
	t_node *parent_node);

// Exec heredoc functions
void	clean_heredoc(t_node *ast, t_minishell *minishell);
int		ft_heredoc(t_heredoc *list, t_minishell *minishell);
int		heredoc_count(t_io_node *io_list);

// Exec path functions
char	**get_env_path(char **envp, t_minishell *minishell);
void	get_command_path(char **command_path, char *arg, \
	t_minishell *minishell);
int		is_directory(char *path);

// Exec redirect functions
int		redir_handler(t_node *node, int pid);

// Exec handler functions
int		ft_dup(t_minishell *minishell, int oldfd, int newfd);
int		pipe_handler(int *pipefd, t_minishell *minishell);
int		fork_handler(int *pid, t_minishell *minishell);

// Exec util functions
int		is_binop_node(t_node *node);
int		binop_next_checker(t_token_type type);
void	remove_heredoc_node(t_heredoc **list);

// Open utils
int		open_handler(t_minishell *minishell, t_io_node *io_node, int *fd);

// Exec main
t_node	*ft_exec(t_minishell *minishell);
t_node	*traverse_tree(t_node *ast, t_minishell *minishell, \
	t_node *parent_node);

// Exec pipe
t_node	*traverse_pipe(t_node *ast, t_minishell *minishell);

#endif
