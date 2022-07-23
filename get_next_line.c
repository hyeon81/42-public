/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:38 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/23 15:56:33 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

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

int	ft_strchr(const char s[], int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char *ft_return_last(char *backup)
{
	char *tmp;

	if (backup == 0)
	{
		tmp = ft_strdup("", 1);
		return (0);
	}
	//마지막 줄 리턴하고 프리?
	tmp = ft_strdup(backup, ft_strlen(backup) + 1);
	free(backup);
	backup = 0;
	return (tmp);
}

char *get_next_line(int fd)
{
	//파일을 read할 임시 버퍼
	char buf[BUFFER_SIZE];
	// read한 버퍼를 저장해 둘 (백업할) static 버퍼
	static char *backup;
	//(리턴할) 읽은 라인
	char *line; 
	//읽은 바이트수를 저장할 수
	int line_idx; 
	//파일 읽기
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	backup = ft_strdup("", 1);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		line_idx = read(fd, buf, BUFFER_SIZE);
	//strjoin을 하기위 해 널값을 넣어줌
		buf[line_idx] = '\0';
	//읽은 내용을 backup에 백업
		backup = ft_strjoin(backup, buf);
		//할당 실패한 것도 체크해줘야하나?
		if (!backup)
			return (0);
	//개행문자가 있는지 없는지 검사 (strchr)
		line_idx = ft_strchr(backup, '\n');
		if (line_idx >= 0)
		{
			//완성된 문자열은 line에 저장
			line = ft_strdup(backup, line_idx);
			//backup은 이제 안 쓰니까 free?
			free(backup);
			backup = 0;
			return (line);
		}
	}
	if (line_idx == 0)
		//마지막 한 줄을 리턴하는 함수
		return(ft_return_last(backup));
	return (0);
	//1. 없을시 다시 버퍼만큼 라인 읽고 백업하고 개행문자 검색. -> 기존에 백업한 내용에 계속 합침 (strjoin)
	//2. 있을시 backup을 잘라서 line에 넣어주고 (strdup)
	//개행문자 후는 다시 static 변수 backup에 넣는다.
	//읽었을때 \n이 여러개라면??
}

//만약 line에 아무것도 할당되지 않으면 어떻게 되는걸까?