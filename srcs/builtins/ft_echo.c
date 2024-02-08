/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:30:05 by yliew             #+#    #+#             */
/*   Updated: 2024/01/11 17:31:35 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_node *node)
{
	bool	omit_newline;
	int		i;

	i = 1;
	omit_newline = false;
	if (node->expanded_arg[1])
	{
		if (ft_strncmp(node->expanded_arg[1], "-n", 3) == 0)
		{
			omit_newline = true;
			i++;
		}
		while (node->expanded_arg[i])
		{
			remove_quotes(&node->expanded_arg[i]);
			if (ft_strlen(node->expanded_arg[i]) > 0)
			{
				printf("%s", node->expanded_arg[i]);
				if (node->expanded_arg[i + 1])
					printf(" ");
			}
			i++;
		}
	}
	if (!omit_newline)
		printf("\n");
	return (set_exit_success(node->minishell));
}
/*
int	ft_echo(t_node *node)
{
	bool	omit_newline;
	int		i;

	i = 1;
	omit_newline = false;
	if (!node->expanded_arg[1])
		return (printf("\n"), set_exit_success(node->minishell));
	if (ft_strncmp(node->expanded_arg[1], "-n", 3) == 0)
	{
		omit_newline = true;
		i++;
	}
	while (node->expanded_arg[i])
	{
		remove_quotes(&node->expanded_arg[i]);
		if (ft_strlen(node->expanded_arg[i]) > 0)
		{
			printf("%s", node->expanded_arg[i]);
			if (node->expanded_arg[i + 1])
				printf(" ");
		}
		i++;
	}
	if (omit_newline)
		return (set_exit_success(node->minishell));
	printf("\n");
	return (set_exit_success(node->minishell));
}*/
