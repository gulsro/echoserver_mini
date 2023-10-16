#ifndef ECHO_SERVER_H
# define ECHO_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUF_SIZE 100

// typedef struct sockaddr {
//     sa_family_t sa_family;          /* Address family (AF_* constant) */
//     char        sa_data[14];        /* Socket address (size varies
//                                        according to socket domain)*/
// } addr;


//
// EXIT_IF_FAILS a macro to check return values and exit with a message.
// do-while-(0) looks strange but:
// creates a inner scope that executes only once and guards variables in its own scope.
//

#define EXIT_IF_FAILS(__value, __failure_value, __failure_message, __exit_code) \
            do {                                                                \
                if (__value == __failure_value) {                               \
                    printf("%s\n", __failure_message);                          \
                    exit(__exit_code);                                          \
                }                                                               \
            } while(0);                                                         \

#endif