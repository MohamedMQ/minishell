/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:35:54 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 19:49:34 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_pwd_change(int *ret, char **pwd, char **curpwd)
{
	*pwd = getcwd(NULL, 0);
	if (*pwd == NULL)
		return (50);
	*curpwd = ft_strjoin("PWD=", *pwd);
	free(*pwd);
	if (*curpwd == NULL)
		return (50);
	*ret = ft_add_env(*curpwd);
	free(*curpwd);
	return (0);
}

int	ft_pwd(char *s)
{
	char	*oldpwd;
	char	*curpwd;
	char	*pwd;
	int		ret;

	ret = 0;
	if (ft_strcmp(s, "OLDPWD="))
	{
		pwd = ft_get_pwd();
		if (pwd == NULL)
			return (50);
		oldpwd = ft_strjoin("OLDPWD=", pwd);
		if (oldpwd == NULL)
			return (50);
		ret = ft_add_env(oldpwd);
		free(oldpwd);
		return (ret);
	}
	if (ft_pwd_change(&ret, &pwd, &curpwd) == 50)
		return (50);
	return (ret);
}

void	ft_msg_cwd(void)
{
	write(2, "cd: error retrieving current directory: ", 41);
	write(2, "getcwd: cannot access parent directories:", 42);
	write(2, "No such file or directory\n", 27);
}

int	ft_built_in_cd(char **str)
{
	char	*pwd;

	if (*(str + 1) == NULL || ft_strcmp(str[1], "~"))
	{
		*(str + 1) = ft_get_home();
		if (*(str + 1) == NULL)
		{
			printf("HOME not set\n");
			return (0);
		}
		if (str[1][0] == '\0')
			return (0);
	}
	if (chdir(*(str + 1)) == -1)
		if (ft_print_error("minishell: cd: ", *(str + 1)) == 50)
			return (50);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_msg_cwd(), 0);
	free(pwd);
	if (ft_pwd("OLDPWD=") == 50)
		return (50);
	if (ft_pwd("PWD=") == 50)
		return (50);
	return (0);
}
