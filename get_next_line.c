/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: focampo <focampo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:51 by focampo           #+#    #+#             */
/*   Updated: 2020/10/04 18:38:59 by focampo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Une fonction qui retourne une ligne lue depuis un file descriptor, sans le
** retour a la ligne.
** 1. le file descriptor sur lequel lire
** 2. la valeur de ce qui a ete lu
** Valeur de retour : Donc on aura "1" tant qu il y a qq chose a lire et si
** on arrive a la fin du fichier, on aura un retour "0" qui signifie qu il n y
** y a plus rien a lire. Par contre,s'il y a une erreur,on aura un retour "-1"
*/

#include "get_next_line.h"

/*
** Il va free et va mettre NULL le pointeur
*/

void	ft_free(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

/*
** Copie dans line ce qu'il y a dans str.
** Copie la string des qu il trouve '\n' dans str.
** Ce qui signifie qu'il y a encore une lecture.
*/

int		ft_str_to_line(char **line, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
	{
		tmp = ft_strdup(*str + i + 1);
		ft_free(str);
		*str = tmp;
		return (1);
	}
	ft_free(str);
	return (0);
}

/*
** Retourne la valeur de read()
*/

int		ft_value_of_return(char **line, char **str, int reader)
{
	if (reader < 0)
		return (-1);
	else if (reader == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		ft_free(str);
		return (0);
	}
	return (ft_str_to_line(line, str));
}

/*
** read() lit jusqu'a BUFFER_SIZE octets depuis le file descriptor fd dans
** le tampon pointe par buff.
** Elle renvoie le nb d'octets transferes, sinon elle retourne -1.
*/

int		get_next_line(int fd, char **line)
{
	static char	*str[FD_MAX];
	char		*buff;
	char		*tmp;
	int			reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(str[fd]))
		if (!(str[fd] = ft_strdup("")))
			return (-1);
	if (!(buff = malloc(sizeof(char*) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((reader = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[reader] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		ft_free(&str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	ft_free(&buff);
	return (ft_value_of_return(line, &(str[fd]), reader));
}
/*
**int		main()
**{
**	char	*line;
**	int		fd;
**	int		ret;
**
**	ret = 1;
**	fd = open("./text.txt", O_RDONLY);
**	if (fd)
**	{
**		printf("Lecture du fichier : \n");
**		while (ret == 1)
**		{
**			ret = get_next_line(fd, &line);
**			printf("res is %d output : |%s|\n", ret, line);
**		}
**	}
**	else
**		printf("NO FD\n");
**	close(fd);
**	return (0);
**}
*/
