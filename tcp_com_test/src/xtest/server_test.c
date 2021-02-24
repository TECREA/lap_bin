
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sockets.h"


int Server, Client;


char *respFrame[2] = { "$LAP:ACK,1,OUT0,0*7D\r\n", "$LAP:ACK,1,OUT0,1*7C\r\n"};
int outValue = 0;
char IncommingData[1024] = {0};

void SignalHandler( int signum ){
    switch( signum ){
        case SIGPIPE:
            puts("SIGPIPE");
            close( Client );
            break;
        default:
            break;
    }
}


int main(int argc, char** argv) {   
    signal( SIGPIPE, SignalHandler );
    uint16_t xPort = 2000;
    if( argc > 1 ){
        xPort = (uint16_t)atoi( argv[1] );
    }     

    printf("> Listing TCP port %d\r\n", xPort );
    Server = Socket_ServerCreate( xPort, 1 );
    if( Server < 0 ){
        perror("> Server socket cant be created\r\n");
        return EXIT_SUCCESS;
    }
    
    for(;;){
        printf("> Accepting client...\r\n");
        Client = Socket_ServerAccept( Server , 4 );
        if( Client > 0 ){
            printf("> Client connected\r\n");
            printf("> Reading incomming...\r\n");
            memset( IncommingData, 0, sizeof(IncommingData) ) ;
            read( Client, IncommingData, sizeof(IncommingData) );
            printf("Received: %s\r\n", IncommingData ); 
            printf("Writing response %s", respFrame[outValue] );
            write( Client, respFrame[outValue], strlen( respFrame[outValue] ) );
        }
        else{
            printf(">Error connecting client\r\n");
        }
        close( Client );
        sleep(1);  

        outValue = !outValue;/*change output*/
    }
    
    

    return EXIT_SUCCESS;
}
