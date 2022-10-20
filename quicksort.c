/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:37:55 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/14 17:50:08 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapab(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	*ft_quick(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = low - 1;
	j = low;
	if (high <= j)
		return (0);
	pivot = array[high -1];
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			ft_swapab(&array[i], &array[j]);
		}
		j++;
	}
	ft_quick(array, low, i);
	ft_quick(array, i + 1, high);
	return (array);
}

