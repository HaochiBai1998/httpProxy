#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

class proxy{
    //cache cache;
    const char * port;
    int server_fd;
public:
    proxy(const char * port):port(port){}
    void start();
    void initializeProxy();
    void handleRequest();
    int connectToClient();
    int connectToServer();
};