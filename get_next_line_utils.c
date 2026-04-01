#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (! str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)chr)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (chr == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] && dest_len + i < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (! s1 || ! s2)
	{
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (! str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	free(s1);
	return (str);
}
