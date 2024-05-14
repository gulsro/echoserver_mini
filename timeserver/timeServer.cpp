#include "timeserv.hpp"
#include <unistd.h>
#include <string>
#include <sys/socket.h>

#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    int clientfd, serverfd;
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(8080);
    char buf[BUF_SIZE];
    time_t ticks;
    int byte_read;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    EXIT_IF_FAILS(serverfd, -1, "Socket()", 1);

    // Since address structure is inited as global, we dont need to call bzero or
    // memset. It ll initially assigned as 0

    int bind_successful = bind(serverfd, (struct sockaddr *) &sockaddr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(bind_successful, -1, "Bind()", 1);

    int listen_succesful = listen(serverfd, 10);
    EXIT_IF_FAILS(listen_succesful, -1, "Listen()", 1);

    while (1) {
        socklen_t client_addr_size = sizeof(sockaddr);
        clientfd = accept(serverfd, (struct sockaddr*)&sockaddr, &client_addr_size);
        if (clientfd < 0) {
            std::cout << "Accept() failed" << std::endl;
            exit(1);
        }

        //get time
        ticks = time(nullptr);
        std::string time_string = ctime(&ticks);

        //send time value to client
        if (write(clientfd, time_string.c_str(), time_string.size()) < 0) {
            std::cout << "Write() failed" << std::endl;
                 exit(1);
        }
        // while (byte_read == read(clientfd, buf, BUF_SIZE) > 0) {
        //     if (write(STDOUT_FILENO, buf, byte_read) != byte_read) {
        //         std::cout << "Write() failed" << std::endl;
        //         exit(1);
        //     }
        if (close(clientfd) == -1) {
            std::cout << "Accept() failed" << std::endl;
            exit(1);
        }
    }
}