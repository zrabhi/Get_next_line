/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:46:18 by zrabhi            #+#    #+#             */
/*   Updated: 2022/01/14 13:06:21 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(char *s1)
{
	t_vrbls	vb;
	char	*ln;

	vb.i = 0;
	vb.j = -1;
	if (!s1)
		return (NULL);
	if (s1[0] == '\0')
		return (NULL);
	while (s1[vb.i] != '\0' && s1[vb.i] != '\n')
		vb.i++;
	if (s1[vb.i] == '\n')
		vb.i = vb.i + 1;
	ln = (char *)malloc(sizeof(char) * (vb.i + 1));
	if (!ln)
		return (NULL);
	while (++vb.j < vb.i)
		ln[vb.j] = s1[vb.j];
	ln[vb.j] = '\0';
	return (ln);
}

char	*ft_read_line(char *str, int fd)
{
	t_vrbls	vb;
	char	*buf;

	vb.i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (vb.i != 0 && ft_strchr(str) == 0)
	{
		vb.i = read(fd, buf, BUFFER_SIZE);
		if (vb.i == 0)
			break ;
		if (vb.i < 0)
			return (free(buf), NULL);
		buf[vb.i] = '\0';
		if (buf)
			str = ft_strjoin(str, buf);
	}
	return (free(buf), str);
}

char	*ft_rest(char *str)
{
	t_vrbls	vb;
	char	*rest;

	vb.i = 0;
	vb.j = 0;
	if (!str)
		return (NULL);
	if (str[vb.i] == '\0')
		return (NULL);
	while (str[vb.i] != '\0' && str[vb.i] != '\n')
		vb.i++;
	if (str[vb.i] == '\n')
		vb.i = vb.i + 1;
	vb.len = ft_strlen(str);
	rest = (char *)malloc(sizeof(char) * ((vb.len - vb.i) + 1));
	if (!rest)
		return (NULL);
	while (str[vb.i])
		rest[vb.j++] = str[vb.i++];
	rest[vb.j] = '\0';
	if (rest[0] == '\0')
		free(str);
	if (rest[0] == '\0')
		return (free(rest), NULL);
	return (free(str), rest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(str, fd);
	if (str == NULL)
		return (NULL);
	line = ft_find_line(str);
	str = ft_rest(str);
	return (line);
}

// int main(void)
// {
//     char *str;
//     int fd = open("multiple_nlx5", O_RDONLY);
//      str = get_next_line(fd);
//      printf("%s", str);
//      str = get_next_line(fd);
//      printf("%s", str);
//       str = get_next_line(fd);
//      printf("%s", str);
//       str = get_next_line(fd);
//      printf("%s", str);
//        str = get_next_line(fd);
//      printf("%s", str);
// }
