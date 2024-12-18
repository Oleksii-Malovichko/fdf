/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:41:17 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/18 15:07:49 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
// #include "mlx/include/MLX42/MLX42.h"
#include <stdlib.h>
// gcc -o mlx_example main.c -lmlx -lXext -lX11 -lm

int main()
{
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, 800, 600, "Buffered Rendering");

    // Создаем изображение
    void *image = mlx_new_image(mlx, 800, 600);
    char *data = mlx_get_data_addr(image, &(int){0}, &(int){0}, &(int){0});

    // Заполняем изображение белым цветом
    for (int y = 0; y < 600; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            int pixel_index = y * 800 * 4 + x * 4;
            data[pixel_index] = 0xFF;       // Синий компонент
            data[pixel_index + 1] = 0xFF;  // Зеленый компонент
            data[pixel_index + 2] = 0xFF;  // Красный компонент
            data[pixel_index + 3] = 0;     // Прозрачность (alpha)
        }
    }

    // Отображаем изображение в окне
    mlx_put_image_to_window(mlx, window, image, 0, 0);

    mlx_loop(mlx);
    return (0);
}// gcc -o train train.c -Iminilibx_macos -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit