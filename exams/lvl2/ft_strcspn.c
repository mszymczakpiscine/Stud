/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:33:51 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 13:45:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;

	while (s[i++])
	{
		while (reject[j])
		{
			if (s[i] == reject[j++])
				return (i);
		}
	}
	return i;
}
int main()
{
	char *s = "hello";
	const char *reject = "jfkhpell";
	printf("%zu\n", ft_strcspn(s, reject));
}