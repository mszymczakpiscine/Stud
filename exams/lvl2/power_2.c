/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:55:37 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 14:57:29 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}

#include <stdio.h>
int main()
{
	printf("%d", is_power_of_2(2));
}
