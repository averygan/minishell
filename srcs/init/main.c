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

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc > 1 && argv)
	{
		ft_putstr_fd("Program does not accept arguments.\n", 2);
		return (0);
	}
	array_dup(&data, envp);
	//testing
	data.command_list = malloc(sizeof(t_command));
	data.command_list->data = &data;
	char	*command = readline("Test command: ");

	data.command_list->argv = ft_split_argv(command);
	if (data.command_list->argv)
	{
		int	i = 0;
		while (data.command_list->argv[i])
		{
			printf("command[%i]: %s\n", i, data.command_list->argv[i]);
			i++;
		}
		if (!check_builtin(&data, data.command_list))
			printf("command is not a builtin\n");
	}
	return (0);
}

