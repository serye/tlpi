#include "../../lib/tlpi_hdr.h"
#include "../../lib/error_functions.h"
#include <fcntl.h>


int
main(int argc, char *argv[])
{
	int fd1 = open("./test_file", O_RDWR);

	if(fd1 == -1)
			errExit("open");

	int offset = 4;

	if(lseek(fd1, offset, SEEK_CUR) == -1)
		errExit("lseek");

	int fd2 = dup(fd1);

	if(lseek(fd2, 0, SEEK_CUR)== offset)
		printf("offset realy matches\n");	
	else
		printf("no\n");
}
