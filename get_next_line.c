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
	
char *get_next_line(int fd)
{
	static char	*box;
	char	temp;
	char	buff;
	int	i;
	int	nbyte;


	while(check_buff(buff))
	{
		read(fd, buff, nbyte);
		copy_str(buff, temp);
	}
		
}
