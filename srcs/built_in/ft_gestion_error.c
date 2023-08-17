/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:37:06 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:37:07 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_print_error(char *str1, char *str2)
{
	char	*ret;

	g_exit_status = 1;
	ret = ft_strjoin(str1, str2);
	if (ret == NULL)
		return (50);
	perror(ret);
	free(ret);
	return (0);
}
