/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 16:27:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 14:39:10 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef enum		e_color
{
	RESET = 0,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	B_BLACK,
	B_RED,
	B_GREEN,
	B_YELLOW,
	B_BLUE,
	B_MAGENTA,
	B_CYAN,
	B_WHITE
}					t_color;

typedef struct		s_pattern
{
	char			*str;
}					t_pattern;

typedef struct		s_elem
{
	struct s_elem	*next;
	void			*data;
}					t_elem;

typedef struct		s_list
{
	int				size;
	t_elem			*first;
	t_elem			*last;
}					t_list;

typedef char		t_bool;

/*
**	BOOL
*/
# define TRUE							(1)
# define FALSE							(0)

/*
**	ANSI COLOR
*/
# define ANSI_COLOR_BLACK				("\x1b[30m")
# define ANSI_COLOR_RED					("\x1b[31m")
# define ANSI_COLOR_GREEN				("\x1b[32m")
# define ANSI_COLOR_YELLOW				("\x1b[33m")
# define ANSI_COLOR_BLUE				("\x1b[34m")
# define ANSI_COLOR_MAGENTA				("\x1b[35m")
# define ANSI_COLOR_CYAN				("\x1b[36m")
# define ANSI_COLOR_WHITE				("\x1b[36m")
# define ANSI_BACKGROUND_COLOR_BLACK	("\x1b[40m")
# define ANSI_BACKGROUND_COLOR_RED		("\x1b[41m")
# define ANSI_BACKGROUND_COLOR_GREEN	("\x1b[42m")
# define ANSI_BACKGROUND_COLOR_YELLOW	("\x1b[43m")
# define ANSI_BACKGROUND_COLOR_BLUE		("\x1b[44m")
# define ANSI_BACKGROUND_COLOR_MAGENTA	("\x1b[45m")
# define ANSI_BACKGROUND_COLOR_CYAN		("\x1b[46m")
# define ANSI_BACKGROUND_COLOR_WITHE	("\x1b[47m")
# define ANSI_COLOR_RESET				("\x1b[0m")

/*
**	BASE
*/
# define BINARY							(2)
# define TRINARY						(3)
# define OCTAL							(8)
# define NONAIRE						(9)
# define DECIMAL						(10)
# define HEXADECIMAL					(16)
# define SEXIGESIMAL					(60)

/*
**	ALIAS
*/
# define MIN(n, m)						((n) < (m) ? (n) : (m))
# define EQUAL(n, m)					(!ft_strcmp(n, m))
# define TO_RAD(n)						(n * M_PI / 180.0f)
# define TO_DEG(n)						(n * 180.0f / M_PI)
# define VEC2							t_vector2f
# define VEC3							t_vector3f
# define MAT4							t_matrix4f
# define QUAT							t_quaternion
# define VERT							t_vertex
# define TRAN							t_transform
# define BOOL							t_bool

/*
**	PUT
*/
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, size_t fd);
void				ft_putendl(char *str);
void				ft_putendl_fd(char *str, size_t fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, size_t fd);
void				ft_putmem(void *adr);
void				ft_putmem_fd(void *adr, size_t fd);
void				ft_putnbr_base(int n, size_t base);
void				ft_putnbr_base_fd(int n, size_t base, size_t fd);

/*
**	STR
*/
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlen(char const *str);
int					ft_strcmp(char *str1, char *str2);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				ft_colorize(t_color color, int backgroud);
char				*ft_strjoin_malloced(char *str1, char *str2);
char				*ft_strjoin(char *str1, char *str2);
char				*ft_strdup(char *str);
char				*ft_strsub(char const *s, size_t start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_trunc(const char *msg, ...);
t_pattern			pattern(int repeat, const char *msg, ...);

/*
**	TAB
*/
size_t				ft_tabsize(void **tab);
void				ft_freetab(void **tab);
char				**ft_cpytab(char **tab, int lenth);
int					**ft_cpytab_int(int **tab, int x, int y);

/*
**	IS
*/
BOOL				ft_isalnum(int c);
BOOL				ft_islower(int c);
BOOL				ft_isupper(int c);
BOOL				ft_isalpha(int c);
BOOL				ft_isascii(int c);
BOOL				ft_isdigit(int c);
BOOL				ft_isprint(int c);
BOOL				ft_isspace(char c);

/*
**	CONVERT
*/
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
float				ft_atof(const char *str);

/*
**	MEM
*/
void				*ft_memalloc(size_t size);
void				*ft_memrealloc(void **ptr, size_t size, size_t new_size);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **mem);

/*
**	ERROR
*/
int					error(const char *msg, ...);
void				exit_error(char *error);

/*
**	LIST
*/
t_list				*new_list(void);
t_elem				*add_elem(t_list *list, void *data);
t_elem				*get_elem(t_list *list, size_t index);
void				del_list(t_list *list);
t_elem				*del_elem(t_list *list, size_t index);
t_elem				*del_last_elem(t_list *list);


/*
**	UTILS
*/
int					get_next_line(int fd, char **line);
void				add_char(char **res, char c);
void				add_str(char **res, char *str);
void				add_int(char **res, int i);
void				add_pattern(char **res, t_pattern pat);

/*
** -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 3D -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*/
typedef struct		s_vector2f
{
	float			x;
	float			y;
}					t_vector2f;

typedef struct		s_vector3f
{
	float			x;
	float			y;
	float			z;
}					t_vector3f;

typedef struct		s_quaternion
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_quaternion;

typedef struct		s_matrix4f
{
	float			m[4][4];
}					t_matrix4f;

typedef struct		s_vertex
{
	VEC3			pos;
	VEC3			color;
}					t_vertex;

typedef struct		s_transform
{
	VEC3			pos;
	VEC3			scale;
	QUAT			rot;
}					t_transform;

/*
**	vector2f
*/
VEC2				*new_vector2f(float x, float y);
float				length2(VEC2 *vec);
float				dot2(VEC2 *vec1, VEC2 *vec2);
float				cross2(VEC2 *vec1, VEC2 *vec2);
VEC2				*normalized2(VEC2 *vec);
VEC2				*inv2(VEC2 *vec);
VEC2				*add2v(VEC2 *vec1, VEC2 *vec2);
VEC2				*sub2v(VEC2 *vec1, VEC2 *vec2);
VEC2				*mul2v(VEC2 *vec1, VEC2 *vec2);
VEC2				*div2v(VEC2 *vec1, VEC2 *vec2);
VEC2				*add2f(VEC2 *vec1, float value);
VEC2				*sub2f(VEC2 *vec1, float value);
VEC2				*mul2f(VEC2 *vec1, float value);
VEC2				*div2f(VEC2 *vec1, float value);
VEC2				*pow2f(VEC2 *vec1, float value);
VEC2				*rt2(VEC2 *vec1);
VEC2				*rotate2(VEC2 *vec, float angle);
float				get_value2(VEC2 *vec);

/*
**	vector3f
*/
VEC3				*new_vector3f(float x, float y, float z);
float				length3(VEC3 *vec);
float				dot3(VEC3 *vec1, VEC3 *vec2);
VEC3				*cross3(VEC3 *vec1, VEC3 *vec2);
VEC3				*normalized3(VEC3 *vec);
VEC3				*inv3(VEC3 *vec);
VEC3				*add3v(VEC3 *vec1, VEC3 *vec2);
VEC3				*sub3v(VEC3 *vec1, VEC3 *vec2);
VEC3				*mul3v(VEC3 *vec1, VEC3 *vec2);
VEC3				*div3v(VEC3 *vec1, VEC3 *vec2);
VEC3				*add3f(VEC3 *vec1, float value);
VEC3				*sub3f(VEC3 *vec1, float value);
VEC3				*mul3f(VEC3 *vec1, float value);
VEC3				*div3f(VEC3 *vec1, float value);
VEC3				*pow3f(VEC3 *vec1, float value);
VEC3				*rt3(VEC3 *vec1);
VEC3				*rotate3(VEC3 *vec, VEC3 *axis, float angle);
VEC3				*rotate3q(VEC3 *vec, QUAT *rotation);
float				get_value3(VEC3 *vec);
VEC3				vector3f(float x, float y, float z);

/*
**	matrix4f
*/
MAT4				*new_matrix4();
MAT4				*mul4m(MAT4 *m, MAT4 *r);
MAT4				*init_rotation3f(float x, float y, float z);
MAT4				*init_translation(VEC3 *vec);
MAT4				*init_rotation3v(VEC3 *f, VEC3 *u, VEC3 *r);
MAT4				*init_scale(float x, float y, float z);
MAT4				*init_perspective(float a, float b, float c, float d);
void				update_fov_aspect(MAT4 *perspective, float fov, float a);

/*
**	quaternion
*/
QUAT				*new_quaternion4f(float x, float y, float z, float w);
QUAT				*new_quaternion4vf(VEC3 *axis, float angle);
float				length4(QUAT *q);
QUAT				*normalized4(QUAT *q);
QUAT				*conjugate4(QUAT *q);
MAT4				*to_rotation_matrix(QUAT *q);
QUAT				*mul4q(QUAT *q, QUAT *r);
QUAT				*mul4v(QUAT *q, VEC3 *r);

/*
**	vertex
*/
VERT				*new_vertex3f(float x, float y, float z);
VERT				*new_vertexp(VEC3 pos);
VERT				*new_vertexpc(VEC3 pos, VEC3 color);

/*
**	transforms
*/
TRAN				*new_transform(void);
VEC3				*transform(VEC3 *v, MAT4 *m);
MAT4				*get_transforms(TRAN *t);

/*
**	utils
*/
float				to_radians(float angle);
float				rt(float val);

#endif
