/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/12 19:16:25 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int			create_server(int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
		ft_error("error with bind()");
	if (listen(sock, 42))
		ft_error("error with listen()");
	return (sock);
}

char		*get_pwd(char **env)
{
	int		i;

	i = 0;
	while ( env[i] )
	{
		if ( ft_strncmp("PWD=", env[i], 4) == 0 )
			return( ft_strsub(env[i], 4, ft_strlen(env[i]) - 4) );
		i++;
	}
	ft_error("Error, no pwd set in env variable");
	return (NULL);
}

int			main(int argc, char *argv[])
{
	int						port;
	int						sock;
	extern char				**environ;
	char					*pwd;

	if (argc != 2)
		ft_error("Usage: ./serveur <port>");
	port = ft_atoi(argv[1]);
	sock = create_server(port);
	pwd = get_pwd(environ);
	new_client(sock, pwd);
	close(sock);
	return (0);
}
