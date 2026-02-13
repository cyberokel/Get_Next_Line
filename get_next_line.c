char	*read_and_join(char *stored, int fd)
{
	char	*buffer;
	char	*temp;
	int	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
	{
		free(buffer);
			return (NULL);
	}
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(stored, buffer);
	free(stored);
	stored = temp;
	if (ft_strchr(stored, '\n'))
		break;
	}
	free(buffer);
	return (stored);
}

char *get_next_line(int fd)
{
    static char *stored;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    stored = read_and_join(fd, stored);
    if (!stored)
        return (NULL);
    
    line = extract_line(stored);
    stored = update_stored(stored);
    
    return (line);
}
