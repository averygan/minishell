/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:20:45 by yliew             #+#    #+#             */
/*   Updated: 2023/09/06 10:24:38 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char	*test[6] = {"a", "A", "0", "7", "-", ""};
	int	i = 0;

	while (i < 6)
	{
		printf("%s: %i\n", test[i], ft_isdigit((int)(*test[i])));
		i++;
	}
	return (0);
}
*/
