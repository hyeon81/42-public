#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * \
	(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != 0)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1, int idx)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (idx));
	if (!arr)
		return (0);
	while (i < idx)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char s[], int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

char *get_next_line(int fd)
{
    //파일을 read할 임시 버퍼
    char buf[BUFFER_SIZE];
    // read한 버퍼를 저장해 둘 (백업할) static 버퍼
    static char *backup;
    char *line; //(리턴할) 읽은 라인
    int line_idx;
    //파일 읽기
    if ((fd < 0) || (BUFFER_SIZE <= 0))
        return (-1);
    backup = "";
    while (read(fd, buf, BUFFER_SIZE) != 0)
    {
    //읽은 내용을 backup에 백업
        backup = ft_strjoin(backup, buf);
    //개행문자가 있는지 없는지 검사 (strchr)
        if (line_idx = ft_strchr(backup, '\n') != 0)
        {
            //완성된 문자열은 line에 저장
            line = ft_strdup(backup, line_idx);
            //완성된 문자열 그 뒤에는 다시 backup에 넣어줌
            backup = ft_str
            return (line);
        }
    }
    return (0);
    //1. 없을시 다시 버퍼만큼 라인 읽고 백업하고 개행문자 검색. -> 기존에 백업한 내용에 계속 합침 (strjoin)

    //2. 있을시 backup을 잘라서 line에 넣어주고 (strdup)
    //개행문자 후는 다시 static 변수 backup에 넣는다.
    //return (line);
    //실패 시 -1 반환. 파일을 끝까지 읽었다면 0 반환.

    //읽었을때 \n이 여러개라면??
}