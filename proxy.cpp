#include "proxy.h"
#include <pthread.h>

void proxy::initializeProxy(){
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);
    char buffer[1024] = { 0 };
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    if (setsockopt(this->server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(std::stoi(port));

    if (bind(this->server_fd, (struct sockaddr*)&addr,sizeof(addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}
void proxy::start(){
    initializeProxy();
    struct sockaddr_in addr;
    int addrsize = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(std::stoi(port));
    while(1){
        int client_fd = accept(server_fd, (struct sockaddr*)&addr,(socklen_t*)&addrsize);
        if (client_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        char buffer[1024] = { 0 };
        int val = read(client_fd, buffer, 1024);
        send(client_fd, "helloWorld", 11, 0);
        printf("%s\n",buffer);
        close(client_fd);
    } 
    close(this->server_fd);
}
void proxy::handleRequest(){}
int proxy::connectToClient(){
    return 0;
}
int proxy::connectToServer(){
    return 0;
}

