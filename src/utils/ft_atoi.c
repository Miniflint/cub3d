/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:49:39 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:49:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// atoi des plus classic nothing to see around here ngl
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

