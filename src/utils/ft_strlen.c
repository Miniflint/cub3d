/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:02:09 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/07 03:02:47 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_uc(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_occurence(char *str, char c)
{
	int	i;
	int	occurence;

	i = -1;
	occurence = 0;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			occurence++;
	return (occurence);
}
