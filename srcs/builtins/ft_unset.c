/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:33:18 by yliew             #+#    #+#             */
/*   Updated: 2024/01/11 17:33:25 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Function to unset environment variables
- Loops through the command arguments
- Extracts the name of each variable to be removed in envp
- Updates envp */
int	ft_unset(t_minishell *minishell, t_node *node)
{
	int		i;

	if (!node->expanded_arg[1])
		return (set_exit_success(minishell));
	i = 1;
	while (node->expanded_arg[i])
	{
		if (update_envp(minishell, node->expanded_arg[i], NULL,
				"unset") == -1)
			return (minishell->exit_status);
		i++;
	}
	if (minishell->minishell_err != NO_ERR)
		return (minishell->exit_status);
	return (set_exit_success(minishell));
}
