/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <nipollin@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:58:25 by nipollin          #+#    #+#             */
/*   Updated: 2024/03/29 22:37:52 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int	ft_strstrlen(int size, char **strstr)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (idx < size)
	{
		len += ft_strlen(strstr[idx]);
		idx++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		if (i + j < size - 1)
		{
			dest[i + j] = src[j];
		}
		j++;
	}
	if (i + j < size - 1)
		dest[i + j] = '\0';
	else
		dest[size - 1] = '\0';
	return (i + j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx;
	int		join_size;
	char	*join;

	join_size = ft_strstrlen(size, strs);
	join_size += ft_strlen(sep) * size + 1;
	join = (char *) malloc(join_size * sizeof(char));
	if (join == NULL)
	{
		return (NULL);
	}
	idx = 0;
	join[0] = '\0';
	while (idx < size)
	{
		ft_strlcat(join, strs[idx], join_size);
		if (idx < size - 1)
			ft_strlcat(join, sep, join_size);
		idx++;
	}
	return (join);
}

/*int	main(int argc, char *argv[])
{
	char	*join;

	if (argc < 2)
	{
		return (1);
	}
	join = ft_strjoin(argc - 2, argv + 2, argv[1]);
	printf("%s\n", join);
	free(join);
	return (0);
}*/
