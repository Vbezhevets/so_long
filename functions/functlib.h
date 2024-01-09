typedef struct s_data
{	
	char    **map;
	int 	h; //height
	int		w; //width
	int		p;
	int		e;
	int		score;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	int		dir;		
} t_data;


typedef struct s_image
{
    void    *mlx;
    void    *img;
    char    *path;
/*  int     *w;
    int     *h;
*/
} t_image;

# define WALL '1'
# define SPACE '0'
# define SCORE 'C'
# define EXIT 'E'
# define PLAYER 'P'

#define LEFT_A 97
#define LEFT_B 65361

#define RIGHT_A 100
#define RIGHT_B 65363

#define UP_A 119
#define UP_B 65362

#define DOWN_A 115
#define DOWN_B 65364

#define ESC 65307

# define WIND_W 800
# define WIND_H 800

# define IMG_H (WIND_H / 10)
# define IMG_W (WIND_W / 10)




#ifndef FUNCTLIB_H
# define FUNCTLIB_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

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
int is_action(char point, t_data * data);
int	player_detect(t_data *data);
int is_map_ok(t_data *data, int y, int x);
int load_map(t_data *data, char *f_path);
int map_init(t_data *data, char *f_path);

t_image *get_img(t_data *data, char c);


void error(int n);

char	*get_next_line(int fd);
void	free_map(t_data * data, int q);


int		ft_printf(char *str, ...);
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
void	*ft_memcpy(void *to, void *from, size_t n);
void	*ft_memmove(void *to, void *from, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t n);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(char *str1, char *str2, size_t n);
void	*ft_memchr(void *str, int c, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
int		ft_atoi(char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd); */
#endif

