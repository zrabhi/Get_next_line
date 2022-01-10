#include <stdlib.h>
#include "get_next_line.h"

char    *ft_find_line(char *s1)
{
    t_vrbls vb;
    char *ln;

    vb.i = 0;
    vb.j = -1;
    while(s1[vb.i] != '\0' && s1[vb.i] != '\n')
        vb.i++;
  while(s1[vb.i] == '\n')
        vb.i++;
    ln = (char*)malloc(sizeof(char) * (vb.i + 1));
    if (!ln)
        return(NULL);
    while(++vb.j < vb.i)
        ln[vb.j] = s1[vb.j];
    ln[vb.j] ='\0';
  //free(s1);
    return(ln);
}

char *ft_read_line(int fd, char *str)
{
    t_vrbls vb;
    char    *buf;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return(NULL);
    vb.i = 1;
    while( vb.i != 0 && ft_strchr(str) == 0)
    {
        vb.i = read(fd, buf, BUFFER_SIZE);
        printf("read : %d\n", vb.i);
        buf[vb.i] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);
    return(str);
}
char    *ft_rest(char *str)
{
    t_vrbls vb;

   vb.i = 0;
   while(str[vb.i] != '\0' && str[vb.i] != '\n')
       vb.i++;
    while(str[vb.i] == '\n')
        vb.i++;
    vb.len = ft_strlen(str);
    char *rest = (char *)malloc(sizeof(char) * ((vb.len - vb.i) +1));
    if(!rest)
        return(NULL);
    vb.j = 0;
    while(str[vb.i])
        rest[vb.j++] = str[vb.i++];
    rest[vb.j] ='\0';
    return(rest);
}

char    *get_next_line(fd)
{
    static char         *str;
    char        *line;

    if ( fd < 0 || BUFFER_SIZE <= 0 )
            return(NULL);
    str = ft_read_line(fd, str);
    line = ft_find_line(str);
    str = ft_rest(str);
    return(line);
}
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
//     int fd;
//     //char *str;
//     fd = open("file.txt", O_RDONLY);
//     // str = get_next_line(fd);
//     //  while(str)
//     //  {
//     //   str = get_next_line(fd);
//     //        printf("%s", str);
//     //  }
    
//     //  str = get_next_line(fd);
//     //   printf("%s", str);
//     //     str = get_next_line(fd);
//     //     printf("%s", str);
//     //    str = get_next_line(fd);
//     //      printf("%s", str);
//     //     str = get_next_line(fd);
//     //    printf("%s", str);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
     
  
// }
