int	ft_atoi(char *str)
{
	int num;
	int i;

	i = 0;
	num = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i] <= ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

