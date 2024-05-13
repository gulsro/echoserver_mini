#include "echo_server.h"

/*
    Create a socket.

    Construct the address structure for the server’s socket and connect to the socket at that address.

    Execute a loop that copies its standard input to the socket connection.
    Upon encountering end-of-file in its standard input,
    the client terminates, with the result that its socket is closed
    and the server sees end-of-file when reading from the socket on the other end of the connection.

*/

int main()
{
    int client_fd;
    int byte_read;
    int call_successful;
    const char *socket_pathname = "/tmp/mysock";
    struct sockaddr addr;
    char buf[BUF_SIZE];

    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    EXIT_IF_FAILS(client_fd, -1, "Failed to create client socket", 1);

    memset(&addr, 0, sizeof(struct sockaddr));
    addr.sa_family = AF_UNIX;
    strncpy(addr.sa_data, socket_pathname, sizeof(addr.sa_data) - 1);
    call_successful = connect(client_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr));
    EXIT_IF_FAILS(call_successful, -1, "Failed to connect to server", 1);

    while ((byte_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
    {
        if (byte_read != write(client_fd, buf, BUF_SIZE))
            exit(1);
    }
    exit(1);
}




