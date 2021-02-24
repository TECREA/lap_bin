#ifndef SOCKETS_H
    #define SOCKETS_H

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <time.h> 
    #include <stdint.h>

    int Socket_ServerCreate( uint16_t port, size_t MaxClients );
    int Socket_ServerAccept( int SocketServer, time_t timeout );


#endif