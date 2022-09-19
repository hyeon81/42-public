#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main() {
    void    *mlx_ptr;
	void	*win_ptr;
    t_data  img;

    mlx_ptr = mlx_init(); //사용자의 소프트웨어와 디스플레이의 연결을 초기화해줌
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello World!");

	//<메모리 주소의 출발점>
    img.img = mlx_new_image(mlx_ptr, 1920, 1080); //새로운 이미지 전달
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian); //주소 전달?

	//메모리 오프셋 계산
	// int offset = (y * line_length + x * (bits_per_pixel / 8));
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	// mlx_key_hook(win_ptr, key_hook, );
    mlx_loop(mlx_ptr);
}