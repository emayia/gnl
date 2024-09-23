/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:40:46 by mayyildi          #+#    #+#             */
/*   Updated: 2022/06/03 14:34:18 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*	This function parses our storage and copies its value to the	*/
/*	char *clean_line string, \n and \0 included (hence the +2 at	*/
/*	malloc()).														*/
/*	RETURN VALUE:													*/
/*	(clean_line): our read line, displayed until the end of line.	*/
char	*put_line(char *str)
{
	int		i;
	char	*clean_line;

	i = 0;
	clean_line = malloc(sizeof(char) * ft_strlengnl(str) + 2);
	while (str[i] != '\n')
	{
		clean_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		clean_line[i] = str[i];
		i++;
	}
	clean_line[i] = '\0';
	return (clean_line);
}

/*	This function concatenates our buffer(*s2) to our storage(*s1). */
/*	tmp becomes our new storage(*s1), and we add the contents of	*/
/*	our buf(*s2) to it, before freeing our s1.						*/
/*	RETURN VALUE:													*/
/*	(fstr): our new, expanded (filled str) version of storage to 	*/
/*	which we've added our buf.										*/
char	*fill_storage(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*fstr;

	i = 0;
	j = 0;
	fstr = malloc(sizeof(char) * (ft_strlengnl (s1) + ft_strlengnl (s2) + 1));
	while (s1[i])
	{
		fstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		fstr[i] = s2[j];
		i++;
		j++;
	}
	fstr[i] = '\0';
	free (s1);
	return (fstr);
}

/*	This function updates our storage str. It parses our storage	*/
/*	str and counts the n_bytes it moved (int i). This value is		*/
/*	going to determine how much characters are before the \n.		*/
/*	This is going to help us create an updated storage (ustr).		*/
/*	RETURN VALUE:													*/
/*	(ustr): our updated storage str, after removing the characters	*/
/*	preceding the \n character.										*/
char	*update_storage(char *str)
{
	int		i;
	int		j;
	char	*ustr;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ustr = malloc(sizeof(char) * (ft_strlengnl (str) - i + 1));
	if (!ustr)
		return (NULL);
	while (str[i])
	{
		ustr[j] = str[i];
		j++;
		i++;
	}
	ustr[j] = '\0';
	free(str);
	return (ustr);
}

/*	We pass the address of storage in get_next_line() to this	*/
/*	function. It does two things:								*/
/*	1) if storage has \n:										*/
/*		• line = create a clean_line going until \n;			*/
/*		• update storage, so that it can start after \n.		*/
/*	2) else if storage is filled and doesn't have \n:			*/
/*		• line gets the value of storage;						*/
/*		• storage is freed and gets a value of NULL.			*/
char	*final_line(char **storage)
{
	char	*line;

	line = NULL;
	if (check_nl(*storage) == 1)
	{
		line = put_line(*storage);
		*storage = update_storage(*storage);
	}
	else if (*storage && check_nl(*storage) == 0)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

/*	The basis of our project.									*/
/*	• r_bytes:	counts the number of bytes returned by read();	*/
/*	• buf:		stores the bytes read by the read() function;	*/
/*	• storage:	keeps our current line in an orderly manner.	*/
/*	We set r_bytes to 1 so that we can get in our while loop.	*/
/*	We have 3 conditions that will define how we proceed:		*/
/*	• 1) if nothing is read or storage is empty:				*/
/*		- free storage;											*/
/*		- set its value to NULL and return NULL.				*/
/*	• 2) if storage is NULL:									*/
/*		- we fill it with the contents of our buffer.			*/
/*		This works for assigning the value of storage for the	*/
/*		first time we get into the while loop.					*/
/*	•3) else													*/
/*		- we concatenate our storage and our buf together.		*/
/*		This is valid for the cases in which our fd isn't fully	*/
/*		read yet. So we just keep on going at that point.		*/
/*	RETURN VALUE:												*/
/*	(final_line(&storage)): we send our storage to final_line()	*/
/*	so that we return the appropriate line.						*/
char	*get_next_line(int fd)
{
	int			r_bytes;
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;

	r_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	while (r_bytes >= 1 && check_nl(storage) != 1)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		buf[r_bytes] = '\0';
		if ((r_bytes == 0 && !storage) || (r_bytes == 0 && storage[0] == '\0'))
		{
			free(storage);
			storage = NULL;
			return (NULL);
		}
		if (storage == NULL)
			storage = ft_strdup(buf);
		else
			storage = fill_storage(storage, buf);
	}
	return (final_line(&storage));
}
