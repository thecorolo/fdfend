

#include "fdf.h"

int	calcul_height(char *file_name)
{
	char	*str;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (height);
}

int	calcul_width(char *file_name)
{
	int		width;
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	str = get_next_line(fd);
	width = word_counter(str, ' ');
	free(str);
	return (width);
}

void	mape_remplir(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		//dprintf(2,"%d",z_line[i]);
		free(nums[i]);
		i++;
	}
	//printf("\n");
	free(nums);
}

t_data	*parse(char *file_name)
{
	t_data	*data;
	int		fd;
	char	*str;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	data->height = calcul_height(file_name);
	data->width = calcul_width(file_name);
	data->mape = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->mape[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		mape_remplir(data->mape[i], str);
		//printf("%d\n",data->mape[i]);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	//free(data->mape[i]);
	return (data);
}
