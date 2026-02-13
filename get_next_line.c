/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidi <akhalidi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 23:30:14 by akhalidi          #+#    #+#             */
/*   Updated: 2026/02/13 23:36:07 by akhalidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*read_and_join(char *stored, int fd)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stored, '\n'))
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
	}
	free(buffer);
	return (stored);
}

char	*extract_line(char *stored)
{
	char	*indice;
	int		position;

	if (!stored)
		return (NULL);
	indice = ft_strchr(stored, '\n');
	if (indice)
	{
		position = indice - stored;
		return (ft_substr(stored, 0, position + 1));
	}
	return (ft_substr(stored, 0, ft_strlen(stored)));
}

char	*update_stored(char *stored)
{
	char	*new_stored;
	char	*newline_ptr;
	int		position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stored, '\n'))
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
	}
	free(buffer);
	return (stored);
}

char	*update_stored(char *stored)
{
	char	*new_stored;
	char	*newline_ptr;
	int		position;
	int		bytes;

	if (!stored)
		return (NULL);
	newline_ptr = ft_strchr(stored, '\n');
	if (!newline_ptr)
	{
		free(stored);
		return (NULL);
	}
	position = newline_ptr - stored;
	bytes = ft_strlen(stored - poition - 1);
	new_stored = ft_substr(stored, position + 1, bytes);
	free(stored);
	return (new_stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;

	stored = read_and_join(fd, stored);
	if (!stored)
		return (NULL);
	line = extract_line(stored);
	stored = update_stored(stored);
	return (line);
}
