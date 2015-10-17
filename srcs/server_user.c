/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 15:43:10 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

t_info		*init_user_info(int sock, char *pwd)
{
	t_info		*i;

	i = malloc(sizeof(t_info));

	i->sock = sock;
	i->pwd = pwd;
	i->end = 0;
	i->argv = NULL;
	i->cmd = NULL;
	ft_bzero(i->buff, 1024);

	return (i);
}

void		parse_cmd(t_info *i)
{
	int		j;

	j = 0;
	while (i->argv != NULL && i->argv[j])
	{
		free(i->argv[j]);
		j++;
	}
	if (i->argv != NULL)
		free(i->argv);
	i->argv = ft_strsplit(i->buff, ' ');
	j = 0;
	if ( i->argv != NULL && i->argv[0] )
		i->cmd = i->argv[0];
	while (i->argv != NULL && i->argv[j])
		j++;
	if (j != 0 && i->argv[j - 1][ft_strlen(i->argv[j - 1]) - 1] == '\n')
		i->argv[j - 1][ft_strlen(i->argv[j - 1]) - 1] = '\0';
}

void		print_prompt(t_info *i)
{
	ft_putstr_fd("\033[32m", i->sock);
	ft_putstr_fd(i->pwd, i->sock);
	ft_putstr_fd("\033[33m", i->sock);
	ft_putstr_fd(" $ ", i->sock);
	ft_putstr_fd("\033[0m", i->sock);
}

void		user_fork(int sock, char *pwd)
{
	t_info		*i;
	int			count;

	i = init_user_info(sock, pwd);
	print_prompt(i);
	while (i->end == 0 && (count = read(sock, i->buff, 1023)) > 0)
	{
		if ( count == 1023 )
		{
			ft_putendl_fd("Command not allowed", i->sock);
			continue ;
		}
		parse_cmd(i);
		control_cmd(i);
		ft_bzero(i->buff, 1024);
		if (i->end == 0)
			print_prompt(i);
	}
}

void		new_client(int sock, char *pwd)
{
	struct sockaddr_in		csin;
	unsigned int			cslen;
	int						cs;

	while (1)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		if (fork() == 0)
			user_fork(cs, pwd);
		close(cs);
	}
}
