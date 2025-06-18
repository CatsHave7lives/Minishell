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

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int readlen;
    static int pos;
    char read_line[70000];
    int i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if (pos >= readlen)
        {
            readlen = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if (readlen <= 0)
                break;
        }
        if (buffer[pos] == '\n' && i >= sizeof(read_line+1))
        {
            read_line[i] = '\n';
            break;
        }
        read_line[i++] = buffer[pos++];
    }
}