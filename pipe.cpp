#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()  {
    int fd;
    char * myfifo = new char [12];
    strcpy(myfifo, "./tmp/myfifo1");

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);
    /* write "Hi" to the FIFO */
    fd = open("./tmp/myfifo1", O_WRONLY ); //open(myfifo, O_WRONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    } 
    printf("File open\n");
    write(fd, "entry [1]", sizeof("entry [1]"));
    sleep(1);
    write(fd, "entry [2]", sizeof("entry [2]"));
    sleep(2);
    write(fd, "entry [3]", sizeof("entry [3]"));
    printf("Content written\n");
    close(fd);
    printf("Connection closed\n");
    /* remove the FIFO */
    unlink(myfifo);
    return 0;
}