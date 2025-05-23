/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:44:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/05/23 16:44:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int ft_strlen(const char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char *ft_strchr(const char *s, int c)
{
	int i = 0;

	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

static char *ft_strdup(const char *s)
{
	int i = 0;
	int len = ft_strlen(s);
	char *copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char *ft_strjoin(char *s1, char *s2)
{
	int i = 0, j = 0;
	int len = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *joined = malloc(len + len2 + 1);
	if (!joined)
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

static char *free_and_null(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char *ft_substr(const char *s, int start, int length)
{
	int i = 0;
	int str_len = ft_strlen(s);

	if (!s || start >= str_len)
		return (ft_strdup(""));

	if (start + length > str_len)
		length = str_len - start;

	char *sub = malloc(length + 1);
	if (!sub)
		return (NULL);
	while (i < length)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char *extract(char **storage)
{
	size_t	i;
	char	*line;
	char	*remaining;

	if (!*storage || **storage == '\0')
		return (NULL);

	i = 0;
	while ((*storage)[i] && (*storage)[i] != '\n')
		i++;

	if ((*storage)[i] == '\n')
		line = ft_substr(*storage, 0, i + 1);
	else
		line = ft_substr(*storage, 0, i);

	if (!line)
		return (NULL);

	if ((*storage)[i] == '\n')
		remaining = ft_strdup(*storage + i + 1);
	else
		remaining = NULL;

	free(*storage);
	*storage = remaining;
	return (line);
}

char *get_next_line(int fd)
{
	static char *storage;
	char *buffer, *temp;
	ssize_t read_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	read_count = 1;
	while (!ft_strchr(storage, '\n') && read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free(buffer), free_and_null(&storage));
		buffer[read_count] = '\0';
		temp = ft_strjoin(storage, buffer);
		if (!temp)
			return (free(buffer), free_and_null(&storage));
		free(storage);
		storage = temp;
	}
	free(buffer);
	return (extract(&storage));
}


#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int     fd;
	char    *line;

	if (argc != 2)
	{
		printf("Usage: %s <file_path>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// x compilare --> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c main.c

