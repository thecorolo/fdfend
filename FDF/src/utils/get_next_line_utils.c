

#include "get_next_line.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}


int ft_strchr(const char *s1, char c)
{
	int i;
	i = 0;

	if(!s1)
	return (-1);

	if(s1[i] == '\0' || (char)c == '\0')
	return (-1);
	while(s1[i])
	{

		if (s1[i] == (char)c)
		{
			return i;
		}
		i++;
	}
	return (-1);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	int i;
	int j;

	char *str;

	i = 0;
	j = 0;

	if(!s1)
		return ft_strdup((char *)s2);

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));

	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
} 
