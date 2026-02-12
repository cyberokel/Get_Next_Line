int	check_buff(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
void	copy_str(char *a, char *b)
{
	int	i;
	static int	j;

	i = 0;
	j = 0;
	while(a)
	{
		a[i] = b[i + j];
		i++;
		j++;
	}
}
char	*result(char *c, char *d,static char e)
{
	int	i;

	i = 0;
	while (c[i] != '\n')
	{
		c[i] = d[i];
		i++;
	}
	c[i] = d[i];
	i++;
	while (c[i + j])
	{
		c[i + j] = e[j];
		j++;
	}
	return(d);
}
	
char *get_next_line(int fd)
{
	static char	*box;
	char	temp;
	char	buff;
	int	i;

	while(!check_buff(temp))
	{
		read(fd, buff, nbyte);
		copy_str(buff, temp);
		if(check_buff(temp))
		return (result(temp, nline, box));
	}
	return (result(temp, nline, box));
} 
