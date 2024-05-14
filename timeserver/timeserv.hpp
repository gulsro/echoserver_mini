# pragma once

#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <iostream.h>

#define BUF_SIZE 100

#define EXIT_IF_FAILS(__value, __failure_value, __failure_message, __exit_code) \
            do {                                                                \
                if (__value == __failure_value) {                               \
                    std::err << "Failed: " << __failure_message << std::endl;   \
                    exit(__exit_code);                                          \
                }                                                               \
            } while(0);                                                         \

#endif

struct sockaddr_in sockaddr{
    sa_family_t sin_family = AF_INET;
    struct in_addr sin_addr.s_addr = INADDR_ANY;
    in_port_t sin_port = htons(8080);
}


