
#include "fdf.h"
#include "get_next_line.h"

void line_changer(char **save , char **line, char *temp)
{
	temp = *save;
	*line = ft_substr(*save, 0, ft_strchr(*save, '\n') + 1);
	*save = ft_substr(*save, (ft_strchr(*save, '\n') + 1), ft_strlen(*save));
	ft_free(temp);
} 

char *get_next_line(fd)
{
	static char *stock;
	char *line;
	char *buff;
	int l;
	char *temp;
	
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buff)
		return NULL;
	while(ft_strchr(stock,'\n') == -1)
	{
		l = read(fd, buff, BUFFER_SIZE);
        if(l == -1 || l == 0)
		{
			ft_free(buff);
			if (stock == NULL)
				return NULL;
			line = stock;
			stock = NULL;
			return (line);
		}   
		buff[l] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(temp);
	}
	ft_free(buff);
	line_changer( &stock,  &line, temp);
	return (line);
}
