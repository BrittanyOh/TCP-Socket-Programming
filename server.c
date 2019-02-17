#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

/* Global constants */
#define PORT 2002
#define MAX_LINE 1000
#define LISTENQ 1024

int main(){
  int list_s;
  int conn_s;
  struct sockaddr_in servaddr;
  char buffer[MAX_LINE];

  // create and check listening Socket
  list_s = socket(AF_INET, SOCK_STREAM, 0);
  if(list_s < 0){
    fprintf(stderr, "ECHOSERV: Error creating listening socket\n");
    exit(EXIT_FAILURE);
  }
  else
    printf("Socket was successfully created! \n");

    //set byes in socket address to 0, assign IP and PORT
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    //bind socket address to listening Socket
    if(bind(list_s, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
      fprintf(stderr, "ECHOSERV: Error calling bind()\n");
      exit(EXIT_FAILURE);
    }
    else
      printf("Socket was successfully binded! \n");
}
