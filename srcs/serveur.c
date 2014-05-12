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

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <libft.h>

void		usage(char *str)
{
	ft_printf("Usage: %s <port>\n", str);
	exit(-1);
}

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
	bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(sock, 42);
	return (sock);
}

int			main(int argc, char *argv[])
{
	int						port;
	int						sock;
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		csin;
	int						r;
	char					buff[1024];

	if (argc != 2)
		usage(argv[0]);
	port = ft_atoi(argv[1]);
	sock = create_server(port);
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	while ((r = read(cs, buff, 1023)) > 0)
	{
		buff[r] = '\0';
		ft_printf("received %d bytes: [%s]\n", r, buff);
	}
	close(cs);
	close(sock);
	return (0);
}
