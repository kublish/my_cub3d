
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "cub3d.h"

void	write_header(t_data *d, int output)
{
	char	header[54];
	int		tmp;
	int		sixfour = 16;

	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	tmp = 54 + 3 * d->res.x * d->res.y;
	fprintf(stderr, "size:%d\n", tmp);
	//fprintf(stderr, "size of int:%d\n", sizeof(int));
	ft_memmove(header + 2, &tmp, sizeof(int));
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40; 
	ft_memcpy(header + 18, &(d->res.x), 4);
	ft_memcpy(header + 22, &(d->res.y), 4);
	header[27] = (unsigned char)1;
	header[28] = (unsigned char)24;
	tmp = 3 * d->res.x * d->res.y;
	ft_memcpy(header + 34, &tmp, 4);
	tmp = 1;
	ft_memcpy(header + 38, &(tmp), 4);
	ft_memcpy(header + 42, &(tmp), 4);
	write(output, header, 54);
}

void	write_body(t_data *d, int output)
{
	char		buffer[3 * SS_BUF];
	int		limit;
	int		i;
	long int	pix_count;

	pix_count = (long)d->res.x * (long)d->res.y;
	limit = d->res.x * d->res.y;
	i = 0;
	while (i < limit)
	{
		buffer[3 * (i % SS_BUF) + 0] = ((char *)(d->screen.adr))
				[4 * (i % d->res.x + pix_count - (i / d->res.x + 1) * d->res.y) + 0];
		buffer[3 * (i % SS_BUF) + 1] = ((char *)(d->screen.adr))
				[4 * (i % d->res.x + pix_count - (i / d->res.x + 1) * d->res.y) + 1];
		buffer[3 * (i % SS_BUF) + 2] = ((char *)(d->screen.adr))
				[4 * (i % d->res.x + pix_count - (i / d->res.x + 1) * d->res.y) + 2];
		if (++i % SS_BUF == 0)
			write(output, buffer, 3 * SS_BUF);
	}
	write(output, buffer, (i % SS_BUF) * 3);
}

void	screenshot(t_data *d)
{
	int 	fd;
	
	if (!(fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)))
		   return (-1 + 0 * ft_printf("failed to screenshot\ncontinuing...\n"));
	fprintf(stderr, "screenshot initiated =====================================\n");
	write_header(d, fd);
	char fillchar = (char)(0x00);
	write_body(d, fd);
	for (int i = 0; i < 64*64 * 3; i++)
		write (fd, &fillchar, 1);
	close(fd);
}
