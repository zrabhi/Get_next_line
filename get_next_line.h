/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:15:14 by zrabhi            #+#    #+#             */
/*   Updated: 2022/01/14 13:26:48 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct vrbls {
	size_t	len;
	int		i;
	int		j;
}	t_vrbls;
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
#endif
