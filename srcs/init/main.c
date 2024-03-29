/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:44:38 by yliew             #+#    #+#             */
/*   Updated: 2024/01/11 15:46:40 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_minishell(t_minishell *minishell)
{
	char	*command;

	while (1)
	{
		command = ft_readline(minishell);
		if (!command)
			return (printf("exit\n"), free_data_and_exit(minishell), 0);
		if (command[0])
		{
			add_history(command);
			ft_lexer(minishell, command);
		}
		if (minishell->tokens && !minishell->minishell_err)
		{
			minishell->curr_token = minishell->tokens;
			if (!minishell->minishell_err)
				ft_parser(minishell);
			if (!minishell->minishell_err)
				ft_exec(minishell);
		}
		ft_reinit(minishell, command);
	}
	close(minishell->old_stdin);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	minishell;

	if (arg_checker(argc, argv) == -1)
		return (1);
	init_env(&minishell, envp);
	init_minishell(&minishell, true);
	ft_minishell(&minishell);
	return (0);
}
