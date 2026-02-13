int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	 if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while(s[i])
	{
		if (s[i] == (char)c)
			return (char *)(&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	if(!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(!str)
		return (NULL);
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *sub;
	size_t  i;

	if (!s)
		return (NULL);

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
