

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 20
char	*ft_free(char *str);
char	*get_next_line(int fd);
void    line_changer(char **save , char **line, char *temp);
char	*ft_strjoin(char const *s, char const *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int     ft_strchr(const char *s1, char c);


#endif