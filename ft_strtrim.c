#include <stdlib.h>
#include <stdio.h>

int search_set(char c, char *set) {
    int i;
    i = 0;

    while (set[i] != 0) {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set) {
    char *str;
    int i;
    int start;
    int end;

    i = 0;
    //시작 문자  검색
    while (s1[i] != '\0') {
        if (search_set(s1[i], (char *) set) == 0)
            break;
        i++;
    }

    start = i;
    while (s1[i] != '\0')
        i++;

    //ㄲㅡㅌ무ㄴ자 검색
    while (start < i - 1) {
        if (search_set(s1[i - 1], (char *) set) == 0)
            break;
        i--;
    }
    end = i - 1;

    str = (char *)malloc(sizeof(char)* (end - start + 2));
    if (!str)
        return 0;
    i = 0;
    while (start <= end) {
        str[i] = s1[start];
        start++;
        i++;
    }
    str[i] = '\0';
    return (str);
}

// int main() {
//     printf("%s", ft_strtrim("", "1234"));
// }