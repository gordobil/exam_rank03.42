#include "get_next_line.h"

char	*ft_strdup(char *line)
{
	char	*dup;
	int		i = 0;

	while (line[i] != '\0')
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup || !line)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		dup[i] = line[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static int	rd_buff;
	static int	i_buff;
	char		line[5000];
	char		i = 0;

	while (1)
	{
		if (i_buff >= rd_buff)
		{
			rd_buff = read(fd, buffer, BUFFER_SIZE);
			i_buff = 0;
			if (rd_buff <= 0)
				break ;
		}
		if (line[i] == '\n')
			break ;
		
		line[i] = buffer[i_buff];
		i_buff++;
		i++;
	}
	line[i] = '\0';
	if (i = 0)
		return (NULL);
	else
		return (ft_strdup(line));
}

int	main()
{
	int	fd;

	fd = open("./file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return(0);
}