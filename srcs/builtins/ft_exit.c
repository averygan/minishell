/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:42 by yliew             #+#    #+#             */
/*   Updated: 2024/01/11 17:32:50 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//add in proper free_data function after the structs are finalised
int	ft_exit(t_data *data)
{
	printf("exit\n");
	free(data->command_list);
	exit(1);
	return (1);
}
