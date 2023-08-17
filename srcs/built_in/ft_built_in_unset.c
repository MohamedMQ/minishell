/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:36:37 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:36:38 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_built_in_unset(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_singletone(str[i], DELETE) == 50)
			return (50);
		i++;
	}
	g_exit_status = 0;
	return (0);
}
