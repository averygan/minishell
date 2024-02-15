/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:22:15 by yliew             #+#    #+#             */
/*   Updated: 2024/02/05 15:22:19 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_exit_success(t_minishell *minishell)
{
	minishell->exit_status = EXIT_SUCCESS;
	return (0);
}

int	set_exit_error(t_minishell *minishell, int error, int status)
{
	minishell->minishell_err = error;
	minishell->exit_status = status;
	return (0);
}

int	ft_exit_status(t_minishell *minishell)
{
	if (WIFSIGNALED(minishell->exit_status))
		minishell->exit_status = 128 + WTERMSIG(minishell->exit_status);
	else
		minishell->exit_status = WEXITSTATUS(minishell->exit_status);
	return (minishell->exit_status);
}
