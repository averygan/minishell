/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:56:43 by yliew             #+#    #+#             */
/*   Updated: 2024/01/29 11:24:05 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// RECURSIVE - traverse_tree
    // Is there heredoc?
    // When it finds a binop
        // traverse_tree left
        // (Condition to check binop)
            // traverse_tree right
    // When simple cmd found -> 
        // Exec and set status
t_node *traverse_tree(t_node *ast, t_minishell *minishell)
{
    if (!ast)
        return (ast);
    if (is_binop_node(ast))
    {
        traverse_tree(ast->left, minishell);
        if ((WIFEXITED(minishell->exit_status) && ast->type == T_AND) \
            || (!WIFEXITED(minishell->exit_status) && ast->type == T_OR)
            || ast->type == T_PIPE)
                traverse_tree(ast->right, minishell);
    }
    else
        exec_command(ast, minishell);
    return (ast);
}

t_node *ft_exec(t_minishell *minishell)
{
    if (minishell->heredoc_count >= 1)
       ft_heredoc(minishell->heredoc_list);
    traverse_tree(minishell->ast, minishell);
    return (minishell->ast);
}