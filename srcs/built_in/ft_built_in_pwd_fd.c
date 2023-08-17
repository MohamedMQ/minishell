/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_pwd_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:36:26 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 19:24:45 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*ft_get_pwd(void)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey("PWD=");
	cpy = *get_adress_env();
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str)
			&& !ft_strncmp(cpy->str, "PWD", len))
		{
			if (ft_equal(cpy->str))
				return (cpy->str + len + 1);
		}
		cpy = cpy->next;
	}
	return (NULL);
}

int	ft_built_in_pwd_fd(char **str, int fd)
{
	char	pwd[1024];

	if (*str == NULL)
		return (0);
	getcwd(pwd, 1024);
	g_exit_status = 0;
	ft_putstr_fd(pwd, fd);
	ft_putchar_fd('\n', fd);
	return (0);
}
