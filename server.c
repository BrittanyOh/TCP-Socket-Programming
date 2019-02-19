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
  /* SETTING UP */

  int list_s;
  int conn_s;
  int cli_length;
  struct sockaddr_in servaddr;
  struct sockaddr_in cli_addr;
  char buffer[MAX_LINE];
  char temp_buffer[MAX_LINE];
  int i = 0;

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

    //prepare server to listen
    if( listen(list_s, LISTENQ) < 0){
      fprintf(stderr, "ECHOSERV: Error calling listen() \n");
      exit(EXIT_FAILURE);
    }
    else
      printf("Server is listening...\n");

      /* LISTENING */

      // infinite loop to response to client requests

      while (1) {
        // wait and accept connection
        cli_length = sizeof(cli_addr);
        conn_s = accept(list_s,(struct sockaddr *) &cli_addr, &cli_length);
        if( conn_s < 0){
          fprintf(stderr, "ECHOSERV: Error calling accept() \n");
          exit(EXIT_FAILURE);
        }
        else
          printf("Server accept successful \n");

          memset(buffer, 0, MAX_LINE);
          read(conn_s, buffer, sizeof(buffer));

          // capitalized
          memcpy(temp_buffer, buffer, 3 * sizeof(char));
          if( strstr(temp_buffer, "CAP") != NULL){ //check if firsrt 3 chars include CAP
            memset(temp_buffer, 0, MAX_LINE);
            memcpy(temp_buffer, &buffer[5], 100 *sizeof(char));
            while(temp_buffer[i]){ //capitilize each char in array
              putchar (toupper(temp_buffer[i]));
              i++;
            }
            printf("%s", temp_buffer);
            memset(buffer, 0, MAX_LINE);
          }
          //quit program
          if( *buffer == 'q'){
            break;
          }
      }

      close(list_s);
}
