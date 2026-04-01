#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dup;

	if (! str)
	{
		return (NULL);
	}
	dup = malloc(ft_strlen(str) + 1);
	if (! dup)
	{
		return (NULL);
	}
	ft_strlcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}

size_t	ft_end(char	*received)
{
	size_t	i;

	i = 0;
	while (received[i] != '\n' && received[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	len_s;
	char	*cast;

	if (! s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	cast = (char *)s + start;
	if (ft_strlen(cast) < len)
		len_s = ft_strlen(cast) + 1;
	else
	{
		len_s = len + 1;
	}
	string = malloc(len_s);
	if (! string)
		return (NULL);
	ft_strlcpy(string, cast, len_s);
	return (string);
}

int	ft_clear(char **received, size_t end, int ex)
{
	char	*new;

	if (! ex)
	{
		if ((*received)[0] == '\0')
		{
			free(*received);
			*received = NULL;
			return (1);
		}
		return (0);
	}
	if (ft_strlen(*received) > end + 1)
	{
		new = ft_substr(*received, end + 1, ft_strlen(*received) - (end + 1));
		free(*received);
		*received = new;
	}
	else
	{
		free(*received);
		*received = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*received;
	size_t		result;
	char		buffer[BUFFER_SIZE + 1];
	char		*output;
	size_t		end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (! received)
		received = ft_strdup("");
	while (!ft_strchr(received, '\n'))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result <= 0)
			break ;
		buffer[result] = '\0';
		received = ft_strjoin(received, buffer);
	}
	if (ft_clear(&received, 0, 0) == 1)
		return (NULL);
	end = ft_end(received);
	output = ft_substr(received, 0, end + (received[end] == '\n'));
	ft_clear(&received, end, 1);
	return (output);
}
