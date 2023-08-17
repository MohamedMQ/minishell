/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:37:44 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 16:29:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	wait_pid(t_commande_line **cmdl, pid_t *pid)
{
	t_commande_line	*cur;
	int				len;
	int				i;

	i = 0;
	cur = *cmdl;
	len = len_cmd(cur);
	if (len == 1 && ft_is_builtin((*cmdl)->argv[0]))
		return (0);
	while (i < len)
	{
		waitpid(pid[i], &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		else if (WIFSIGNALED(g_exit_status))
			g_exit_status = 128 + WTERMSIG(g_exit_status);
		i++;
	}
	return (0);
}

int	no_forking(t_commande_line **cmdl, pid_t *pid)
{
	if ((*cmdl)->argv == NULL)
		return (0);
	else if (ft_exec_bd_fd((*cmdl)->argv[0],
			(*cmdl)->argv, cmdl, pid) != 0)
		return (0);
	return (0);
}

int	exec_builtin(char **str, t_commande_line **cmdl,
	t_commande_line **first, pid_t *pid)
{
	free(str);
	if (ft_exec_builtin((*cmdl)->argv[0], (*cmdl)->argv, first, pid) == 2)
		exit(1);
	exit(0);
	return (0);
}

void	signal_cmd_2(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
	}
}

void	ft_print_err_backslach(t_commande_line **cmdl)
{
	if ((*cmdl)->argv[0][0] == '/')
	{
		write(2, "minishell: ", 11);
		write(2, (*cmdl)->argv[0], ft_strlen((*cmdl)->argv[0]));
		write(2, " No such file or directory\n",
			ft_strlen(" No such file or directory\n"));
	}
	else if ((*cmdl)->argv[0][0] == '.')
	{
		write(2, "minishell: ", 11);
		write(2, (*cmdl)->argv[0], ft_strlen((*cmdl)->argv[0]));
		write(2, " : commande introuvable\n",
			ft_strlen(" : commande introuvable\n"));
	}
}
