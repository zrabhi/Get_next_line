#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct vrbls {
    size_t len;
    int i;
    int j;
}   t_vrbls;
size_t  ft_strlen(const char *str);
char *get_next_line(int fd);
int   ft_strchr(const char *str);
char    *ft_strjoin(char *s1, char *s2);
#endif