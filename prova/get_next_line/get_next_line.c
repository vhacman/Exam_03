#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	size_t i = 0;
	while(str && str[i])
		i++;
	return i;
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	size_t	i = 0;
	size_t	j = 0;
	char	*new_str = malloc(len1 + len2 + 1);
	size_t	i = 0;
	size_t	j = 0;

	if(!new_str)
		return NULL;
	while(s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while(s2 && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return(new_str);
}

char	*ft_strchr(const char *s, char c)
{
	if(!s)
		return NULL;
	while(*s)
	{
		if(*s == c)
			return((char *)s);
		s++;
	}
	return NULL;
}	

char	*ft_strdup(const char *str)
{
	size_t	len = ft_strlen(str);
	size_t	i = 0;
	char	*new = malloc(len + 1);
	if(!new)
		return NULL;

	while(i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return new;
}

<<<<<<< HEAD
=======
char	*extract_line(char **buffer)
{
	char	*temp;
	char	*line;
	size_t	i = 0;

	if(!*buffer || !**buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return NULL;
	}

	while((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if((*buffer)[i] == '\n')
		i++;
	line = ft_strdup(*buffer);
	line[i] = '\0';
	temp = ft_strdup(*buffer + i);
	free(*buffer);
	*buffer = temp;
	return line;
}

>>>>>>> c8413ff (ok)
char	*read_to_buffer(int fd, char *buffer)
{
	char	*chunk = malloc(BUFFER_SIZE + 1);
	ssize_t	i = 1;

	if(!chunk)
		return NULL;
	while(i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, chunk, BUFFER_SIZE);
		if(i < 0)
		{
			free(chunk);
			free(buffer);
			return NULL;
		}
		chunk[i] = '\0';
		buffer = ft_strjoin(buffer, chunk);
	}
	free(chunk);
	return buffer;
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t 	i = 0;

	if(!*buffer || !**buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return NULL;
	}
	while((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if((*buffer)[i] == '\n')
		i++;
	line = ft_strdup(*buffer);
	line[i] = '\0';
	temp = ft_strdup(*buffer + i);
	free(*buffer);
	*buffer = temp;
	return line;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_to_buffer(fd, buffer);
	if(!buffer)
		return NULL;
	line = extract_line(&buffer);
	return line;
}

int	main()
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;

	while((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);
	}
<<<<<<< HEAD
	close(fd);
=======
	close (fd);
	return 0;
>>>>>>> c8413ff (ok)
}
