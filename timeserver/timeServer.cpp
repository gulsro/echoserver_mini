#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include <time.h>
#include <iostream.h>

int main(int argc, std::string argv) {
    int clientfd, serverfd;
    struct sockaddr_in sockaddr;
    char buff[BUF_SIZE];
    time_t ticks;
    int byte_read;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    EXIT_IF_FAILS(serverfd, -1, "Socket()", 1);

    // Since address structure is inited as global, we dont need to call bzero or
    // memset. It ll initially assigned as 0

    int bind_successful = bind(listen_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(bind_successful, -1, "Bind()", 1);

    int listen_succesful = listen(serverfd, 10);
    EXIT_IF_FAILS(listen_succesful, -1. "Listen()", 1);

    while (1) {

    }
}