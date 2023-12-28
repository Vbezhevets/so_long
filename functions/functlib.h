/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:37:06 by bvalerii          #+#    #+#             */
/*   Updated: 2023/09/12 12:48:28 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_data
{
	char    **map;
	int 	h; //height
	int		w; //width
	int		score;
	int		collect;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
} t_data;


#ifndef FUNCTLIB_H
# define FUNCTLIB_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"

//# include "../m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int mlx_go(t_data *data);
int mlx_stop(t_data *data);
int key_pressed(int key, t_data *data);

//void move(int key, t_data *map);
void move_up(t_data *data);
void move_down(t_data *data);
void move_left(t_data *data);
void move_right(t_data *data);
void map_render(t_data *data);
int map_anal(char point, t_data * data);

t_data *scan(t_data *data);
int check_map(t_data *data);
int load_map(t_data *data, char *f_path);

int		ft_strlen( char *str);
void	ft_strcpy(char *dst, char *src);
char	*get_next_line(int fd);


int		ft_printf(const char *str, ...);
void	ft_putnbr(long long int n, int *count);
void	ft_putchr(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_putpntr(void *pntr, int *count);
void	ft_putx(int n, int *count);
void	ft_put_x(int n, int *count);
/*
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *to, const void *from, size_t n);
void	*ft_memmove(void *to, const void *from, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd); */
#endif

