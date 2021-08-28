#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	u;
	size_t	temp_i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		u = 0;
		if (big[i] == little[u])
		{
			temp_i = i;
			while (big[temp_i] == little[u])
			{
				u++;
				temp_i++;
				if (little[u] == '\0')
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
