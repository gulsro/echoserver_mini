#ifndef TIMESERV_HPP
#define TIMESERV_HPP


#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <iostream>

#define BUF_SIZE 100

#define EXIT_IF_FAILS(__value, __failure_value, __failure_message, __exit_code) \
            do {                                                                \
                if (__value == __failure_value) {                               \
                    std::cout << "Failed: " << __failure_message << std::endl;   \
                    exit(__exit_code);                                          \
                }                                                               \
            } while(0);                                                         \


#endif