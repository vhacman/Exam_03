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
	size_t	i;
	size_t	j;

	if (!new_str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
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

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	i = 0;
	if (!*buffer || !**buffer)
		return (NULL);
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

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*read_buf = malloc(BUFFER_SIZE + 1);
	ssize_t	bytes_read;

	if (!read_buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_buf);
			free(buffer);
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_buf);
	}
	free(read_buf);
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

// // //x testare
// int main(int argc, char **argv)
// {
// 	int     fd;
// 	char    *line;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <file_path>\n", argv[0]);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// // x compilare --> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c
