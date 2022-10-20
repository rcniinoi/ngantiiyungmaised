#include "../push_swap.h"

int	ft_wordcountall(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 && ft_isdigit(argv[i][j + 1]) != 1)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

char	**ft_argumontobuffer(int argc, char **argv, int count)
{
	int		i;
	int		j;
	int		k;
	char	**suffer;
	char	**splited;

	suffer = calloc(count, sizeof(char *));
	k = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		splited = ft_split(argv[i], ' ');
		while (splited[j])
		{
			suffer[k] = ft_strdup(splited[j]);
			k++;
			j++;
		}
		ft_freestrstr (splited);
		j = 0;
		i++;
	}
	return (suffer);
}

void	ft_printlst(t_stk *stk)
{
	while (stk != NULL)
	{
		ft_dprintf(1, "index = %d lek = %d\n", stk->index, stk->lek);
		stk = stk->next;
	}
	ft_putendl_fd("", 1);
	stk = ft_lstfirst(stk);
}

void	ft_printintarray(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_dprintf(1, "[%d] ", array[i]);
		i++;
	}
	ft_putendl_fd("", 1);
}

int	*ft_atoisembe(char **str, int count)
{
	int	i;
	int	*intsuffer;

	intsuffer = calloc((count + 1), sizeof(int *));
	i = 0;
	while (i < count)
	{
		intsuffer[i] = ft_atoi(str[i]);
		i++;
	}
	// ft_freestrstr(str);
	return (intsuffer);
}
