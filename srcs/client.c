/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:56:38 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/12 19:18:37 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <libft.h>

void		usage(void)
{
	ft_putendl("Usage: ./client <port>");
	exit(-1);
}

int			create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	connect(sock, (const struct sockaddr *)&sin, sizeof(sin));
	return (sock);
}

int			main(int argc, char *argv[])
{
	int						port;
	int						sock;
	int						r;
	char					buff[1024];

	if (argc != 3)
		usage();
	port = ft_atoi(argv[2]);
	sock = create_client(argv[1], port);
	while ((r = read(0, buff, 1023)) > 0)
	{
		buff[r - 1] = '\0';
		write(sock, buff, r);
	}
	close(sock);
	return (0);
}
