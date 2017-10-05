/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/06/28 14:28:02 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ISO_CONST1 2
# define ISO_CONST2 2
# define WIN_W 1900
# define WIN_H 1200
# define ISO 1
# define PARA 0
# define ON 1
# define OFF 0

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				new_x;
	int				new_y;
	int				color;

}					t_points;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				cumul;
	int				x;
	int				y;
	int				xinc;
	int				yinc;
	int				delta_e;
	int				color;

}					t_bresenham;

typedef	struct		s_window
{
	char			*path;
	void			*mlx;
	void			*win;
	char			*data;
	void			*img;
	int				opt;
	int				size;
	int				endian;
	int				pad;
	int				pad_h;
	int				move_lr;
	int				move_ud;
	t_points		***map;
	int				map_h;
	int				map_w;
	int				max_z;
	int				color;
	int				legend;
}					t_window;

int					put_points(t_points ***tab);

void				calcul_coords(t_window *win);
void				calculate(t_window *win, t_points *point);
t_bresenham			*bres_build(t_points *p1, t_points *p2, int max_z);
int					ft_paint(int p1, int p2, int max_z);
int					mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);
void				draw_map(t_window *win);
void				redraw(t_window *window);
void				draw_line(t_window *win, t_points *p1, t_points *p2);
void				ft_slow_increase(t_bresenham *bres, t_window *window);
void				ft_high_increase(t_bresenham *bres, t_window *window);

int					expose_hook(t_window *win);
int					mouse_hook(int button, t_window *window);
int					key_hook(int keycode, t_window *window);
int					key_press(int keycode, t_window *window);

void				ft_do_fdf(t_window *win);

t_points			*ft_newpoint(char *data, int y, int index, t_window *win);
t_points			**ft_new_line(char *line, int y, t_window *win);
t_points			***ft_create_map(t_list *map, t_window *win);
t_points			***ft_fdf(t_window *win);

int					check_x(int x);
int					check_y(int y);
int					ft_length(char **tab);
void				ft_destroy(char **tab);

void				move_u(t_window *window);
void				move_d(t_window *window);
void				move_l(t_window *window);
void				move_r(t_window *window);
void				projection(t_window *window);
void				reset_settings(t_window *window);

void				file_error(void);
void				del(void *content, size_t size);
void				ft_quit(t_window *win);

void				zoom_inc(t_window *window);
void				zoom_dec(t_window *window);
void				increase_h(t_window *window);
void				decrease_h(t_window *window);

void				put_legend(t_window *window);
void				switch_legend(t_window *window);
#endif
