/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: focampo <focampo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:48:04 by focampo           #+#    #+#             */
/*   Updated: 2020/10/02 12:48:06 by focampo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_str_to_line(char **line, char **str);
int		ft_value_of_return(char **line, char **str, int reader);

/*
** Fonctions UTILS
*/

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif
