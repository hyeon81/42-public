#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int make_move(char *map, int m_width, int m_height)
{
	//버튼 눌렀을때 반응
	
}

int key_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook! : %d\n", keycode);
    return (0);
}

int render_map(char *map, int m_width, int m_height)
{
    int img_width;
    int img_height;
    void *img1;
    void *img2;
    void *img3;
    void *img4;
    void *img5;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, m_width * 43, m_height * 43, "Hello World!");

    img1 = mlx_xpm_file_to_image(vars.mlx, "./img/1.xpm", &img_width, &img_height);
    img2 = mlx_xpm_file_to_image(vars.mlx, "./img/2.xpm", &img_width, &img_height);
    img3 = mlx_xpm_file_to_image(vars.mlx, "./img/3.xpm", &img_width, &img_height);
    img4 = mlx_xpm_file_to_image(vars.mlx, "./img/4.xpm", &img_width, &img_height);
    img5 = mlx_xpm_file_to_image(vars.mlx, "./img/5.xpm", &img_width, &img_height);

    int i = 0;
    int y = -1;
    while (++y < m_height)
    {
        int x = -1;
        while (++x < m_width)
        {
            if (map[i] == '1')
                mlx_put_image_to_window(mlx_ptr, win_ptr, img1, x * 43, y * 43);
            else if (map[i] == '0' || map[i] == 'P')
                mlx_put_image_to_window(mlx_ptr, win_ptr, img2, x * 43, y * 43);
            else if (map[i] == 'E')
                mlx_put_image_to_window(mlx_ptr, win_ptr, img3, x * 43, y * 43);
			else if (map[i] == 'C')
            	mlx_put_image_to_window(mlx_ptr, win_ptr, img4, x * 43, y * 43);
			i++;
        }
    }
	mlx_key_hook(win_ptr, key_hook);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img1, x * img_width, y * img_height);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 43, 43);

    mlx_loop(mlx_ptr);
    return (0);
}
