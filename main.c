/* main.c - main function file
 * Copyright (C) 2014 Adrian Alonso <aalonso00@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with self library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>


int
main(int argc, char **argv)
{
    int fd;
    char *file = NULL;
    unsigned char buff[16];

    if(argc != 2)
    {
        printf ("Usage: %s <file>\n", argv[0]);
        exit (1);
    }

    file = argv[1];

    fd = open(file, O_RDONLY);

    if(fd < 0)
    {
        printf ("Error");
        exit(1);
    }
    
    /* od -A x -t x1z -v file.dat */
#define BUF_SIZE 16
    ssize_t numread;
    char buf[1];
    char bufstring[BUF_SIZE];
    int count = 0;
    char bandera = 0;
    while( (read(fd,buf,1)) > 0 )
    {
	bandera =1;
	printf("%02x ",(unsigned int) (buf[0]));
        bufstring[count]=buf[0];
	count ++;
	if (count == 16)
	{
		int index;
		count =0;
		printf(" ");
		for(index = 0;index<16;index++)
		{
			if (bufstring[index]=='\n')
			{
				bufstring[index]='.';
			}
			printf("%c",bufstring[index] );
		}
		//printf(" >%s>",bufstring);
		printf("\n");
		for(index = 0;index<16;index++)
		{
			bufstring[index]='\0';
		}
		bandera = 0;
	}
    }
	if(bandera = 1)
	{
		int index;
		printf(" ");
                for (index = count;index<16;index++)
		{
			printf("   ");
	
		}
			for(index = 0;index<count;index++)
		{
			if (bufstring[index]=='\n')
			{
				bufstring[index]='.';
			}
		printf("%c",bufstring[index] );
		}
		printf("\n");
	}
    /* Print complete file content following od       hex format */
    close (fd);

    return 0;
}
