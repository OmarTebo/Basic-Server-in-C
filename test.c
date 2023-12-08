#include <stdio.h>
#include "Server.h"

void launch(struct Server *server)
{
    printf("===== WAITING FOR CONNECTION =====");
    int addrlen = sizeof(server.address)
    int new_socket = accept(server.socket, (struct sockaddr*)&server.address, (socklen_t *)&addrlen);
}

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10);
}
