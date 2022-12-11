/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:02:09 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:49:53 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bon voila hein t'as pas besoin d'aide pour celui la je pense ngl
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// ft_strlen modifié pour qu'il renvoie le nombre de char jusqu'à un '\0'
// OU ALORS (la partie importante) qu'il renvoie le nombre
// de character jusqu'à un certain char c
// (ft_strlen_UNTIL_CHAR) -> ft_strlen_uc
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

// compte combien de fois le char c apparait dans une chaine de character
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
