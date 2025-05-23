
size_t	ft_strlen(const char *str)
{
	size_t i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t len = ft_strlen(s1);
	char *s2 = (char *)malloc(len + 1);
	size_t i = 0;

	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *string_1, const char *string_2)
{
	size_t len_1 = ft_strlen(string_1);
	size_t len_2 = ft_strlen(string_2);
	char *new_str = (char *)malloc(len_1 + len_2 + 1);
	size_t i = 0;
	size_t j = 0;

	if (!new_str)
		return (NULL);
	while (i < len_1)
	{
		new_str[j] = string_1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len_2)
	{
		new_str[j] = string_2[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


char	*extract_line(char **raw)
{
	char	*line;
	char	*end;
	char	*rem;
	size_t	i;

	if (!raw || !*raw || !**raw)
		return (NULL);
	end = ft_strchr(*raw, '\n');
	if (end)
		i = end - *raw + 1;
	else
		i = ft_strlen(*raw);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, *raw, i);
	line[i] = '\0';
	if (end && *(end + 1))
	{
		rem = ft_strdup(end + 1);
		if (!rem)
		{
			free(line);
			line = NULL;
		}
		free(*raw);
		*raw = rem;
	}
	else
	{
		free(*raw);
		*raw = NULL;
	}
	return (line);
}

char	*read_and_update(int fd, char *raw)
{
	char	*buf;
	char	*new_raw;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		free(buf);
		return (raw);
	}
	buf[bytes_read] = '\0';
	if (!raw)
		new_raw = ft_strdup(buf);
	else
		new_raw = ft_strjoin(raw, buf);
	free(buf);
	free(raw);
	return (new_raw);
}

char	*get_next_line_reader(int fd, char *raw)
{
	char	*tmp;

	while (!raw || !ft_strchr(raw, '\n'))
	{
		tmp = read_and_update(fd, raw);
		if (!tmp)
		{
			if (raw)
				free(raw);
			raw = NULL;
			return (NULL);
		}
		if (tmp == raw && !ft_strchr(raw, '\n'))
			break;
		raw = tmp;
	}
	return (raw);
}

char	*get_next_line(int fd)
{
	static char	*raw;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw = get_next_line_reader(fd, raw);
	if (!raw || !*raw)
	{
		if (raw)
		{
			free(raw);
			raw = NULL;
		}
		return (NULL);
	}
	line = extract_line(&raw);
	return (line);
}
