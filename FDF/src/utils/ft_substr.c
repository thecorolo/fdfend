#include "fdf.h"

int	count_char(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	str_len;
	int		diff;

	size = 0;
	str_len = ft_strlen(s);
	if (start > str_len)
		return (1);
	diff = len - start;
	while (s[start] && size < len)
	{
		size++;
		start++;
	}
	return (size + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * count_char(s, start, len));
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}