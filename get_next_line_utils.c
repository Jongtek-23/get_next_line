/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: focampo <focampo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:40 by focampo           #+#    #+#             */
/*   Updated: 2020/10/02 12:47:57 by focampo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Calcule la longueur de la chaine de caracteres 's', sans compter '\0'.
** Renvoie le nombre de caracteres dans la chaine 's'.
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** Renvoie un pointeur sur la 1er occurrence du caractere 'c' dans la chaine
** 's', ou null si le caractere n'a pas ete trouve
*/

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

/*
** Renvoie un pointeur sur une nouvelle chaine de caracteres sui est
** du^pliquee depuis s. La memoire occupee par cette nouvelle chaine est
** obtenu en appelant malloc.
** Renvoie un pointeur sur la chaine dupliquee, ou null s'il n'y a pas assez
** de memoire.
*/

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
** Alloue(avec malloc()) et retourne une nouvelle chaine, resultat de la
** cancatenation de s1 et s2.
** #1. La chaine de caracteres prefixe
** #2. La chaine de caracteres suffixe
** Retourne la nouvelle chaine de caracteres. NULL si l'allocation echoue.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/*
** Alloue(avec malloc()) et retourne une chaine de caracteres issue de la
** chaine 's'. Cette nouvelle chaine commence a l'index 'start' et a pour
** taille maximale 'len'.
** #1. La chaine de laquelle extraire la nouvelle chaine
** #2. L'index de debut de la nouvelle chaine dans la chaine 's'
** #3. La taille maximale de la nouvelle chaine
** Retourne la nouvelle chaine de caracteres. NULL si l'allocation echoue.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (0);
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		dst[i] = '\0';
		return (dst);
	}
	while (len > 0 && s[start] != '\0')
	{
		dst[i] = s[start];
		i++;
		start++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
