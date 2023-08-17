/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:36:31 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 19:30:18 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_built_in_pwd(char **str)
{
	char	*pwd;

	if (*str == NULL)
		return (0);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (50);
	g_exit_status = 0;
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
