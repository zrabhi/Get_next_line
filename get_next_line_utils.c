#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(0);
    while(str[i])
        i++;
    return(i);
}

int   ft_strchr(char *str)
{
    int i;
    
    i = -1;
    if (!str)
        return (0);
    while(str[++i])
    {
        if(str[i] == '\n')
            return(1);
        //i++;
    }
     //if(str[0] == '\n')
        // return (1);
    return(0);
}


char    *ft_strjoin(char *s1,  char *s2)
{
    t_vrbls vb;
    char *str;

    vb.i = -1;
    vb.j = -1;
    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = 0;
    }
    vb.len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char )* (vb.len + 1));
    if (!str)
        return(NULL);
    while(s1[++vb.i])
        str[vb.i] = s1[vb.i];
    while(s2[++vb.j])
        str[vb.i + vb.j] = s2[vb.j];
    str[vb.i + vb.j] = '\0';
    free(s1);
    return(str);    
}