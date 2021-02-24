#include "sockets.h"


/*===========================================================================*/
int Socket_ServerCreate( uint16_t port, size_t MaxClients ){
    int listenfd = -1;
    struct sockaddr_in serv_addr; 

    if( ( listenfd = socket(AF_INET, SOCK_STREAM, 0) )  > 0 ){
        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons( port ); 

        bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

        listen( listenfd, (int)MaxClients ); 
    }

    return listenfd;
}
/*===========================================================================*/
int Socket_ServerAccept( int SocketServer, time_t timeout ){
    int connfd = 0;
    struct timeval tv = {0 , 0};
    tv.tv_sec = timeout;        // 30 Secs Timeout
    
    connfd = accept( SocketServer, (struct sockaddr*)NULL, NULL); 
    setsockopt( connfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv,sizeof(struct timeval));

    return connfd;
}
/*===========================================================================*/