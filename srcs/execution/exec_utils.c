/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:40:05 by agan              #+#    #+#             */
/*   Updated: 2024/01/29 12:40:09 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checks if ast node is binop */
int	is_binop_node(t_node *node)
{
	if (node->type == T_AND || node->type == T_OR || node->type == T_PIPE)
		return (1);
	return (0);
}

/* Checks for binop given type */
int	binop_next_checker(t_token_type type)
{
	if (type == T_AND || type == T_OR || type == T_PIPE)
		return (1);
	return (0);
}

/* Function to remove first node of heredoc list */
void	remove_heredoc_node(t_heredoc **list)
{
	t_heredoc	*to_free;

	to_free = *list;
	if (to_free)
	{
		*list = (*list)->next;
		free(to_free->delimiter);
		free(to_free);
		to_free = NULL;
	}
}
