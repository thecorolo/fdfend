

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

# define ZOOM 40

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		**mape;
	int		color;
	float	x_next;
	float	y_next;
	int		move_x;
	int		move_y;
	int 	*g_data;
	void	*g_image;
	int 	tab[4];
}	t_data;

t_data	*parse(char *file_name);
char    *get_next_line(int fd);
int		word_counter(char const *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	design(t_data *data);
void	bresenham_law(float x, float y, int bool, t_data *data);
int		ft_max(int a, int b);
int		absolute_value(int a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
