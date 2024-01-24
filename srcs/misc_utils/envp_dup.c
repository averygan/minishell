/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:03 by yliew             #+#    #+#             */
/*   Updated: 2024/01/11 16:51:04 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_envp(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->envp[i])
	{
		j = i + 1;
		while (data->envp[j])
		{
			if (ft_strncmp(data->envp[i], data->envp[j],
				ft_strlen(data->envp[i])) > 0)
			{
				ft_swap(&data->envp[i], &data->envp[j]);
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	array_dup(t_data *data, char **envp)
{
	int	i;

	data->envp_size = 0;
	while (envp[data->envp_size])
		data->envp_size++;
	data->envp = malloc((data->envp_size + 1) * sizeof(char*));
	i = 0;
	while (i < data->envp_size)
	{
		data->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	data->envp[i] = NULL;
	sort_envp(data);
}
