#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	while (str && str[i])
		i++;
	return i;
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*new_str = malloc(len1 + len2 + 1);
	size_t	i = 0;
	size_t	j = 0;

	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len = ft_strlen(s1);
	char	*dup = malloc(len + 1);
	size_t	i = 0;
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	i = 0;
	if (!*buffer || !**buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_strdup(*buffer);
	line[i] = '\0';
	temp = ft_strdup(*buffer + i);
	free(*buffer);
	*buffer = temp;
	return (line);
}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*chunk = malloc(BUFFER_SIZE + 1);
	ssize_t	b_read;

	if (!chunk)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, chunk, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(chunk);
			free(buffer);
			return (NULL);
		}
		chunk[b_read] = '\0';
		buffer = ft_strjoin(buffer, chunk);
	}
	free(chunk);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	return (line);
}

/*
#include <stdlib.h>
int	main(void)
{
	int	fd = open("file.txt", O_RDONLY);
	char	*line;

	while((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
*/
