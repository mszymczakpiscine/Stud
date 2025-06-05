/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:46 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 14:09:13 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char *str)
{
	int i =0;
	int len = 0;
	int tmp;
	
	while (str[len])
		len++;
	while (1 < len -1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}
int	main(void)
{
	char s[] = "chat le chat";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}