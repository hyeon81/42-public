#include <strings.h>
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
    unsigned char *des_p;
    unsigned char *src_p;

    i = 0;
    des_p = (unsigned char*)dst;
    src_p = (unsigned char*)src;

    // if (!des_p && !src_p)
    // {
    //     return 0;
    // }

    if (des_p == src_p || len == 0)
        return dst;

    if (des_p <= src_p)
    {
        while (i < len)
        {
            des_p[i] = src_p[i];
            i++;
        }
    }

    //자리가 모자람
    else
    {
        while (len > 0)
        {
            des_p[len - 1] = src_p[len - 1];
            len--;
        }
    }
    return (des_p);
}

// int main()
// {
//     char src[6]="abcded";
//     char dst1[10]="1234567890";
//     char dst2[4]="1234";

//     printf("%s: %s\n", ft_memmove(dst1, src, 6), memmove(dst1, src, 6));
//     printf("%s: %s\n", ft_memmove(dst1, src, 2), memmove(dst1, src, 2));
//     printf("%s: %s\n", ft_memmove(dst2, src, 4), memmove(dst2, src, 4));
// }