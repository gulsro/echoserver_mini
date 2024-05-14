#include "timeserv.hpp"
#include <unistd.h>
#include <string>
#include <sys/socket.h>


#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    int clientfd;
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(8080);
    char buf[BUF_SIZE];
    time_t ticks;
    int byte_read;

    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    EXIT_IF_FAILS(clientfd, -1, "Socket()", 1);

    int connect_success = connect(clientfd, (struct sockaddr *) &sockaddr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(connect_success, -1, "Connect()", 1);

    while (true) {
        byte_read = read(clientfd, buf, BUF_SIZE);
        if (byte_read <= 0) {
            // Either an error occurred or the connection was closed
            break;
        }
        if (write(STDOUT_FILENO, buf, byte_read) != byte_read)
            std::cout << "Write() failed" << std::endl;
            exit(1);

        // OR below;
        //std::cout << "The current time: " << std::string(buf, byte_read);
        //std::cout << std::endl;
    }
    // I had to comment-out because i closed that fd in server first
    //close(clientfd);
    exit(0);
}