#include "../mylibc.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	free_mysplit(char **split, char *s_trimmed, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		i++;
	}
	free(s_trimmed);
	free(split);
}

static char	*count_split(const char *s, char * set, size_t *sub_str_count)
{
	char	*s_trimmed;
	size_t	i;

	i = 0;
	*sub_str_count = 1;
	s_trimmed = ft_strtrim(s, set);
	if (!s_trimmed)
		return (NULL);
	if (*s_trimmed == 0)
		(*sub_str_count)--;
	while (s_trimmed[i])
	{
		if (ft_isinset(s_trimmed[i], set) && !ft_isinset(s_trimmed[i+1],set))
			(*sub_str_count)++;
		i++;
	}
	return (s_trimmed);
}

static char	**make_split(char **split, char *s_trimmed, char * set)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s_trimmed[i])
	{
		start = i;
		while (!ft_isinset(s_trimmed[i], set) && s_trimmed[i])
			i++;
		split[j] = ft_substr(s_trimmed, start, i - start);
		if (!split[j])
		{
			free_mysplit(split, s_trimmed, j + 1);
			return (NULL);
		}
		j++;
		while (ft_isinset(s_trimmed[i], set))
			i++;
	}
	split[j] = NULL;
	free(s_trimmed);
	return (split);
}

char	**ft_mysplit(char const *s, char * set)
{
	size_t	sub_str_count;
	char	**split;
	char	*s_trimmed;

	s_trimmed = count_split(s, set, &sub_str_count);
	split = malloc(sizeof(char *) * (sub_str_count + 1));
	if (!split)
	{
		free(s_trimmed);
		return (NULL);
	}
	return (make_split(split, s_trimmed, set));
}

