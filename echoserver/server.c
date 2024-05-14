#include "echo_server.h"

/*
    Create a socket.

    Remove any existing file with the same pathname as that to which we want to bind the socket.
    (calling memset)

    Construct the address structure for the server’s socket . (by calling strncpy)

    Connect to the socket at that address.

    Execute an infinite loop to handle incoming client requests. Each loop iteration performs the following steps:

    Accept a connection, obtaining a new socket, cfd, for the connection.

    Read all of the data from the connected socket and write it to standard output.

    Close the connected socket client fd.

    The server must be terminated manually (e.g., by sending it a signal).

*/

/*

struct sockaddr_un {
    sa_family_t sun_family;          Always AF_UNIX 
    char sun_path[108];              Null-terminated socket pathname 
}

*/

int main()
{
    int server_fd, client_fd;
    int byte_read;
    int call_successful;

    const char *socket_pathname = "/tmp/mysock";
    struct sockaddr addr;
    char buf[BUF_SIZE];

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    EXIT_IF_FAILS(server_fd, -1, "Socket creation failed", 1);

    memset(&addr, 0, sizeof(struct sockaddr));
    addr.sa_family = AF_UNIX;
    strncpy(addr.sa_data, socket_pathname, sizeof(addr.sa_data) - 1);

    call_successful = bind(server_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(call_successful, -1, "Bind Failed", 1);

    call_successful = listen(server_fd, 5);
    EXIT_IF_FAILS(call_successful, -1, "Listen Failed", 1);

    while (1)
    {
        client_fd = accept(server_fd, NULL, NULL);
        EXIT_IF_FAILS(client_fd, -1, "Accept failed", 1);

        while ((byte_read = read(client_fd, &buf, BUF_SIZE)) > 0)
        {
            if (byte_read != write(STDOUT_FILENO, buf, byte_read))
                exit(1);
        }
        if (close(client_fd) == -1)
            exit(1);
    }
    unlink(socket_pathname);
}
