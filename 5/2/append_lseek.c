#include "../../lib/tlpi_hdr.h"
#include "../../lib/error_functions.h"
#include <fcntl.h>


int
main(int argc, char *argv[])
{
		char *data = "data to write";
		int fd;
		fd = open("./test_file", O_APPEND | O_CREAT | O_RDWR );
		if(fd == -1)
				errExit("open");

		ssize_t written; 
		written = write(fd,data,12);

		if(written == -1)
				errExit("write");

		lseek(fd, 0, SEEK_SET);


		write(fd,"QWERTYU", 7);

		printf("%zd bytes written\n", written);

		close(fd);

}

