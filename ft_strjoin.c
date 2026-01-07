/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <ltourbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:18:50 by ltourbe           #+#    #+#             */
/*   Updated: 2026/01/07 17:36:02 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

char	*ft_strjoinjoin(char *s3, char const *s2, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s3[j] = s2[i];
		j++;
		i++;
	}
	s3[j] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*s3;
	unsigned int		i;
	unsigned int		j;
	unsigned int		total;

	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(total * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	return (ft_strjoinjoin(s3, s2, j));
}
