#include <stdio.h>
#include <mlx.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
}               t_vars;

int key_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook! : %d\n", keycode);
    return (0);
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
    printf("Hello from mouse_hook!\n");
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	mlx_key_hook(vars.win, key_hook, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
}
