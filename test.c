#include <stdio.h>
#include "Server.h"
#include <unistd.h>
#include <string.h>

void serve_html(int client_socket, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[30000];
    int bytesRead;

    // Send HTTP response header
    const char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    write(client_socket, response_header, strlen(response_header));

    // Send the content of the HTML file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (write(client_socket, buffer, bytesRead) < 0) {
            perror("Error writing to socket");
            break;
        }
    }

    fclose(file);
}

void launch(struct Server *server)
{
   char buffer[30000] = {0};

    while (1)
    {
        printf("===== WAITING FOR CONNECTION =====\n");
        int addrlen = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr*)&server->address, (socklen_t *)&addrlen);
        read(new_socket, buffer, sizeof(buffer));
        printf("%s\n", buffer);

        // Assume a simple GET request, check for "GET" in the request
        if (strstr(buffer, "GET") != NULL) {
            // Serve the HTML file
            serve_html(new_socket, "home.html");
        }

        close(new_socket);
    }
}


int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);

    server.launch(&server);


}
