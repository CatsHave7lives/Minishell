// static bool	echo_flag_check(int ac, char **av, size_t *row)
// {
// 	size_t	col;
// 	bool	check;

// 	*row = 1;
// 	check = false;
// 	while (*row < ac && av[*row][0] == '-' && av[*row][1] == 'n')
// 	{
// 		col = 2;
// 		while (av[*row][col] == 'n')
// 			col++;
// 		if (av[*row][col] == '\0')
// 			check = true;
// 		else
// 			break ;
// 		(*row)++;
// 	}
// 	return (check);
// }

// int	msh_echo(int ac, char **av)
// {
// 	size_t	row;
// 	bool	flag_n;
// 	bool	is_first;

// 	flag_n = echo_flag_check(ac, av, &row);
// 	is_first = true;
// 	while (row < ac)
// 	{
// 		if (!is_first)
// 			ft_putchar(' ');
// 		ft_putstr(av[row]);
// 		is_first = false;
// 		row++;
// 	}
// 	if (!flag_n)
// 		ft_putchar('\n');
// 	return (0);
// }
