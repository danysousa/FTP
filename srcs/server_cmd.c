/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:54:20 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void		ft_ls(t_info *i)
{
	struct dirent*		elem;

	i->folder = opendir(i->pwd);
	if (i->folder == NULL)
	{
		ft_putendl_fd("Permission denied\4", i->sock);
		return ;
	}

	while ((elem = readdir(i->folder)) != NULL)
		ft_putendl_fd(elem->d_name, i->sock);
	closedir(i->folder);
}

void		ft_help(t_info *i)
{
	ft_putendl_fd("Allowed command :", i->sock);
	ft_putendl_fd("[ls, pwd, cd, quit]", i->sock);
}

void		ft_pwd(t_info *i)
{
	ft_putendl_fd(i->pwd, i->sock);
}

void		ft_exit(t_info *i)
{
	ft_putendl_fd("Goodbye !\4", i->sock);
	i->end = 1;
}

void		ft_cd(t_info *i)
{
	char	*tmp;

	if (i->argv[1])
	{
		tmp = ch_pwd(i->pwd, i->argv[1]);
		if ( chdir(tmp) == -1 )
		{
			ft_putendl_fd("cd: no such file or directory\4", i->sock);
			chdir(i->pwd);
			free(tmp);
			return ;
		}
		free(i->pwd);
		i->pwd = tmp;
	}
	ft_putendl_fd(i->pwd, i->sock);
}

void		ft_get(t_info *i)
{
	char	*path;
	char	buff[1024];
	FILE	*fd;
	int		count;

	if (!i->argv[1])
		return ;
	if (i->argv[1] && i->argv[1][0] != '/')
		path = ft_trunc("%s/%s", i->pwd, i->argv[1]);
	else
		path = ft_strdup(i->argv[1]);
	if (ft_is_dir(path))
	{
		ft_putendl_fd("ERROR: can't get directory\4", i->sock);
		return ;
	}
	if ((fd = fopen(path, "rb")) == NULL)
	{
		ft_putendl_fd("ERROR: no such file or permission denied\4", i->sock);
		return ;
	}
	ft_bzero(buff, 1024);
	send(i->sock, "ERROR: NULL\n", 12, 0);
	while (!feof(fd))
	{
		count = fread(buff, 1, 1023, fd);
		send(i->sock, buff, count, 0);
		ft_bzero(buff, 1024);
	}
	fclose(fd);
}

void		control_cmd(t_info *i)
{
	int				j;
	static t_cmd	pt[7] =
	{
		{"ls", ft_ls},
		{"pwd",ft_pwd},
		{"help",ft_help},
		{"quit",ft_exit},
		{"cd",ft_cd},
		{"get",ft_get},
		{NULL, NULL}
	};

	j = 0;
	while (j < 6)
	{
		if (ft_strncmp(i->cmd, pt[j].cmd, ft_strlen(pt[j].cmd)) == 0)
		{
			pt[j].f(i);
			ft_putstr_fd("\4", i->sock);
			return ;
		}
		j++;
	}
	ft_putendl_fd("Command not found : use help\n\4", i->sock);

}


