#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    unsigned char *des_p;
    unsigned char *src_p;

    i = 0;
    des_p = (unsigned char*)dst;
    src_p = (unsigned char*)src;

    // //des가 비었을경우
    // if (des_p == 0)
    //     return (0);

    // //src가 비어있을경우
    // if (src_p == 0)
    //     return (des_p);

    //주소가 같을 경우
    if (des_p == src_p)
        return (des_p);

    while (i < n)
    {
        des_p[i] = src_p[i];
        i++;
    }
    return (des_p);
}





// int main()
// {
//     int src[] = {0,5,423};
//     int dest[3];

//     memcpy(dest, src, sizeof(int) * 3);
//     for (int i = 0; i < 3; i++)
//     {
//         printf("%d ", src[i]);
//     }
//     printf("\n");
    
//     for(int i = 0; i < 3; i++)
//     {
//         printf("%d ", dest[i]);
//     }

//     printf("\n------------\n");

//     ft_memcpy(dest, src, sizeof(int) * 3);

//     for (int i = 0; i < 3; i++)
//     {
//         printf("%d ", src[i]);
//     }
//     printf("\n");
    
//     for(int i = 0; i < 3; i++)
//     {
//         printf("%d ", dest[i]);
//     }

// }

// int main()
// {
//     printf("%p\n", ft_memcpy(((void*)0), ((void*)0), 3));
//     printf("%p\n", memcpy(((void*)0), ((void*)0), 3));
    
// }