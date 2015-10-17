/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:53:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:59:24 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <dirent.h>

typedef struct		s_info
{
	int				sock;
	char *			pwd;
	DIR *			folder;
	char			buff[1024];
	char			*cmd;
	char			**argv;
	int				end;
}					t_info;

typedef struct		s_cmd
{
	char *			cmd;
	void			(*f)(t_info *);
}					t_cmd;

#endif
