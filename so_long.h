/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:50:36 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:21:50 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}		t_rect;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_sprite
{
	t_list	*frame;
	int		update_time;
	int		time;
	int		cur_nb;
	int		nb_frames;
	int		w;
	int		h;
}		t_sprite;

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_map
{
	char	**content;
	int		nb_line;
	int		nb_colomn;
	t_point	pos;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map_ptr;
	t_point		pos;
	t_img		image_base;
	t_img		bricks;
	t_img		floor;
	t_img		c;
	t_img		perso;
	t_img		perso_back;
	t_img		perso_left;
	t_img		perso_right;
	t_img		enemy;
	t_img		exit;
	t_img		*rect;
	int			trig;
	int			move;
	char		*move_nb;
	int			init_co;
	int			co;
	int			move_pos;
	t_sprite	sp_perso;
	t_sprite	sp_perso_back;
	t_sprite	sp_perso_left;
	t_sprite	sp_perso_right;
	t_sprite	sp_enemy;
}				t_game;

/*------------------------- so_long.c -------------------------*/
int				ft_strcmp(char *str1, char *str2);
void			check_extension(char *av1);
int				main(int ac, char **av);

/*---------------------- so_long_utils.c ----------------------*/
int				count_colomn(char **map);
int				count_line(char **map);
int				count_digit(int nbr);
char			*ft_itoa(int nbr);

/*------------------------ read_map.c ------------------------*/
int				count_line_fd(char *av1);
char			**read_map(char *av1);

/*---------------------- check_error.c ------------------------*/
void			check_line(char **map);
void			check_size(int nb_line, int nb_colomn, char **map);
int				check_char(char **map);
void			check_error_map(char **map, int nb_line, int nb_colomn);

/*---------------------- check_error2.c -----------------------*/
int				fill_is(char c, char *to_fill);
void			fill(char **map, t_point cur, t_point size, char *to_fill);
void			flood_fill(char **map, char **map_cpy);
int				check_map(char **map);
void			check_access(char **map);

/*---------------------- check_error3.c -----------------------*/
void			check_p(char **map);
void			check_e(char **map);
void			check_c(char **map);
void			quit_border(char **map);
void			check_border(char **map);

/*------------------ check_error_utils.c ---------------------*/
char			*str_cpy(char *map);
char			**make_copy(char **map);
t_point			pos_perso(char **map);

/*------------------------ init_map.c ------------------------*/
void			sprite_init_null(t_game *game);
void			img_init_null(t_game *game);
void			init_struct_game(t_game *game);
void			sprite(t_game *game);
void			init_map(t_game *game);

/*------------------------ init_img.c ------------------------*/
t_img			init_bricks(t_game *game);
t_img			init_floor(t_game *game);
t_img			init_collectible(t_game *game);
t_img			init_enemy(t_game *game);
t_img			init_exit(t_game *game);

/*------------------------ init_img_perso.c ------------------------*/
t_img			init_perso(t_game *game);
t_img			init_perso_back(t_game *game);
t_img			init_perso_left(t_game *game);
t_img			init_perso_right(t_game *game);

/*------------------------ draw_img.c ------------------------*/
void			draw_bricks(t_game	*game);
void			draw_floor(t_game *game);
void			draw_collect(t_game *game);
void			draw_perso(t_game *game);
void			draw_exit(t_game *game);

/*------------------------ draw_rect.c ------------------------*/
void			draw_enemy(t_game *game);
int				render_rect(t_game *data, t_rect rect);
void			img_pix_put(t_img *img, int x, int y, int color);

/*------------------------- img_utils.c ------------------------*/
t_img			new_img(int w, int h, t_game *game);
t_img			new_file_img(char *path, t_game *game);
void			put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);

/*------------------- image_utils_sprite.c ---------------------*/
void			new_img_ptr(t_img *image, int w, int h, t_game *game);
void			put_pixel_img_sprite(t_img *img, int x, int y, int color);

/*-------------------------- movement.c ------------------------*/
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);

/*-------------------------- movement2.c ------------------------*/
void			move_up2(t_game *game);
void			move_down2(t_game *game);
void			move_right2(t_game *game);
void			move_left2(t_game *game);

/*------------------------ count_move.c ------------------------*/
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			count_move(t_game *game);
int				count_collec(t_game *game);

/*----------------------------- sprite.c -------------------------*/
void			init_sprite(t_game *game, t_sprite *sprite, t_img *img, int t);
t_img			*slice_sprite(t_game *game, t_img *img, t_sprite *sprite, \
t_point coord);
void			slice_sprite2(t_img *frame, t_img *img, t_point coord, \
t_sprite *sprite);
void			create_frames(t_game *game, t_img *img, t_list *temp, \
t_sprite *sprite);
void			update_sprite(t_game *game, t_sprite *sprite, t_list *frame, \
t_point coord);

/*--------------------------- sprite_utils.c -----------------------*/
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstgetlast(t_list *lst, int index);

/*--------------------------- handle.c --------------------------*/
int				handle_no_event(t_game *game);
int				handle_input(int keysym, t_game *game);

/*------------------------ free_exit.c ------------------------*/
void			ft_free_map(char **map);
void			ft_free_lst(t_game *game, t_list *frame);
void			free_img(t_game *game);
int				ft_exit(t_game *game);

/*---------------------- get_next_line.c ---------------------*/
int				ft_check(char *storage);
char			*ft_line_extract(char *line);
char			*ft_line_maker(int fd, char *buf, char *storage);
char			*get_next_line(int fd);

/*-------------------- get_next_line_utils.c ------------------*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif