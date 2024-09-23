/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:50:36 by mayyildi          #+#    #+#             */
/*   Updated: 2022/06/03 14:08:41 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/*		Manual definition of BUFFER_SIZE	*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*      Main functions      */
char	*put_line(char *str);
char	*fill_storage(char *s1, char *s2);
char	*update_storage(char *str);
char	*final_line(char **storage);
char	*get_next_line(int fd);

/*      Utilities           */
int		ft_strlengnl(const char *str);
int		check_nl(char *str);
char	*ft_strdup(const char *s1);

#endif
