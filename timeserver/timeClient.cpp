#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include <time.h>
#include <iostream.h>

int main(int argc, std::string argv) {
    int clientfd;
    struct sockaddr_in sockaddr;
    char buff[BUF_SIZE];
    time_t ticks;
    int byte_read;

    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    EXIT_IF_FAILS(clientfd, -1, "Socket()", 1);

    int connect_succes = connect(clientfd, (struct sockaddr *) &addr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(connect_success, -1, "Connect()", 1);

}