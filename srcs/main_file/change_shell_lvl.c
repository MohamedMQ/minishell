/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shell_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:32:19 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 13:06:13 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	init_shlvl_cont(char **shlvl, int *check, char **num_shlvl)
{
	int	num;

	if (!(*check))
	{
		*shlvl = ft_strjoin("SHLVL=", ft_itoa(1));
		ft_add_env(*shlvl);
		free(*shlvl);
		return ;
	}
	num = ft_atoi(*shlvl);
	if (num < 0)
	{
		*shlvl = ft_strjoin("SHLVL=", ft_itoa(0));
		ft_add_env(*shlvl);
		free(*shlvl);
		return ;
	}
	num++;
	*num_shlvl = ft_itoa(num);
	*shlvl = ft_strjoin("SHLVL=", *num_shlvl);
	ft_add_env(*shlvl);
	free(*shlvl);
	free(*num_shlvl);
}

void	init_shlvl(void)
{
	t_env	**env_list;
	char	*shlvl;
	char	*num_shlvl;
	int		check;
	int		i;

	i = 0;
	env_list = get_adress_env();
	if (!ft_get_value_of_env(env_list, "SHLVL="))
	{
		ft_add_env("SHLVL=1");
		return ;
	}
	shlvl = ft_get_value_of_env(env_list, "SHLVL=");
	while (shlvl[i])
	{
		check = ft_is_alpha(shlvl[i]);
		if (!check)
			break ;
		i++;
	}
	init_shlvl_cont(&shlvl, &check, &num_shlvl);
}

void	welcome_msg(void)
{
	printf(" ____    _____  _____  ____  _____  _____  ");
	printf("  _______  ____  ____  _________  _____     _____\n");
	printf("|_   \\  /   _||_   _||_   \\|_   _||_   _|  / ");
	printf(" ___  ||_   ||   _||_   ___  ||_   _|   |_   _|\n");
	printf("  |   \\/   |    | |    |   \\ | |    | |   | ");
	printf(" (__ \\_|  | |__| |    | |_  \\_|  | |       | |\n");
	printf("  | |\\  /| |    | |    | |\\ \\| |    | |  ");
	printf("  '.___`-.   |  __  |    |  _|  _   | |   _   | |   _\n");
	printf(" _| |_\\/_| |_  _| |_  _| |_\\   |_  _| |_ |`\\");
	printf("____) |  _| |  | |_  _| |___/ | _| |__/ | _| |__/ |\n");
	printf("|______||_____||_____||_____|\\____||_____|");
	printf("|_______.' |____||____||_________||________||________|\n\n");
	init_shlvl();
}
