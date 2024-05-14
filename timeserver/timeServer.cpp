#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#include <time.h>
#include <iostream.h>

int main(int argc, std::string argv) {
    int listen fd, serverfd;
    struct sockaddr_in servaddr;
    char buff[BUF_SIZE];
    time_t ticks;

    listed_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    EXIT_IF_FAILS(listed_fd, -1, "Socket() failed", 1);

    bzeros(&servaddr, sizeof(servaddr));

}