/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:53:22 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/12 19:10:12 by dsousa           ###   ########.fr       */
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
