/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:21:10 by agan              #+#    #+#             */
/*   Updated: 2024/01/15 16:21:11 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

typedef enum e_token_type
{
	T_STRING,
	T_REDIR_L,
	T_REDIR_R,
	T_APPEND,
	T_HEREDOC,
	T_PIPE,
	T_OPEN,
	T_CLOSE,
	T_AND,
	T_OR,
}	t_token_type;

typedef struct s_token
{
	char *value;
	t_token_type type;
	struct s_token *next;
	struct s_token *prev;
}	t_token;

t_token *ft_lexer(char *line);

//lexer utils
t_token *create_node(char *content, t_token_type type);
t_token	*token_last(t_token *lst);
void token_add_back(t_token **token_list, t_token *new);
void print_token_list(t_token *token_list);

#endif
