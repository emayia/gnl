/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:49:35 by mayyildi          #+#    #+#             */
/*   Updated: 2022/06/03 14:34:31 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*	This is a slightly modified ft_strlen, so that it can handle empty	*/
/*	strings by returning (0).											*/
/*	RETURN VALUES:														*/
/*	• (0): if str is empty.												*/
/*	• (len): if str is filled											*/
int	ft_strlengnl(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

/*	This function checks if there is a nl character within the str. */
/*	RETURN VALUES:													*/
/*	• (1): found nl													*/
/*	• (0): nl not found												*/
int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*	If our storage str is empty, we allocate the necessary memory based on	*/
/*	the length of buf. We then copy the contents of buf into storage and	*/
/*	we return a pointer to storage.											*/
/*	RETURN VALUE:															*/
/*	(dst): our first instance of filled storage str.						*/
char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc((sizeof(char)) * (ft_strlengnl (s1) + 1));
	while (s1[i])
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
