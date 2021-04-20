/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:27:38 by xinwang           #+#    #+#             */
/*   Updated: 2019/10/18 04:06:48 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_three.h"

char	*ft_strdup(const char *s)
{
	size_t	lens;
	size_t	i;
	char	*str;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	lens = ft_strlen(s1);
	str = (char *)malloc(lens + 1);
	if (!str)
		return (NULL);
	while (i < lens)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		total_lens;
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return ((!s1) ? ft_strdup(s2) : ft_strdup(s1));
	total_lens = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc((total_lens + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[total_lens] = '\0';
	while ((char)s1[++i])
		str[i] = (char)s1[i];
	while ((char)s2[++j])
		str[i++] = (char)s2[j];
	return (str);
}
