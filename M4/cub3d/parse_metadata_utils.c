/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metadata_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:16:02 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/09 01:16:02 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

t_err	parse_image(t_rlx *rlx, t_img *out, char *source)
{
	char	*str;

	str = ft_strndup(source, ft_strlen(source) - 1);
	*out = rlx_load_image(rlx, str);
	free(str);
	if (out->data == NULL)
		return (ERR_FAILED);
	return (ERR_OK);
}

static t_err	parse_color_component(unsigned long *out, char *from, char *to)
{
	char	*s;

	if (!to)
		return (ERR_SYSTEM);
	s = ft_strndup(from, to - from);
	if (!str_isdigit(s))
		return (ERR_FAILED);
	*out = ft_atoul(s);
	free(s);
	return (ERR_OK);
}

t_err	parse_color(t_color *out, char *source)
{
	char			*from;
	char			*to;
	unsigned long	rgb[3];

	from = source;
	to = ft_strchr(from, ',');
	if (parse_color_component(&rgb[0], from, to))
		return (ERR_FAILED);
	from = to + 1;
	to = ft_strchr(from, ',');
	if (parse_color_component(&rgb[1], from, to))
		return (ERR_FAILED);
	from = to + 1;
	to = ft_strchr(from, '\n');
	if (parse_color_component(&rgb[2], from, to))
		return (ERR_FAILED);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (ERR_FAILED);
	*out = rlx_color_rgb(rgb[0], rgb[1], rgb[2]);
	return (ERR_OK);
}
