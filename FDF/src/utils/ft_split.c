
#include "fdf.h"

int	countwords(char const *s, char c)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			wd++;
		i++;
	}
	return (wd + 1);
}

int	countofchar(char const *s, char c)
{
	int	i;
	int	cc;

	i = 0;
	cc = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		cc++;
		i++;
	}
	return (cc);
}

char	**ft_split(char const	*s, char c)
{
	int			i;
	int			j;
	int			cc;
	char		**str;

	str = malloc(sizeof (char *) * (countwords(s, c) + 1));
	if (str == NULL)
		return (NULL);
	cc = countofchar(s, c);
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (i < countwords(s, c))
	{
		cc = countofchar(s + j, c);
		while (s[j] == c)
			j++;
		str[i] = ft_substr(s, j, cc);
		i++;
		j += cc;
	}
	str[i] = NULL;
	return (str);
}
