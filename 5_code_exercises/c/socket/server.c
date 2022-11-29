#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

int main(const int argc, const char** argv){
  struct sockaddr_in server_info = {0};
  server_info.sin_family = AF_INET;
  server_info.sin_port = htons(1337);

  socklen_t server_info_len = sizeof(server_info);

  struct sockaddr client_info = {0};
  socklen_t client_info_len = sizeof(client_info);

  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (0 > sfd){
    perror("socket");
    return -1;
  }
  
  if (0 > bind(sfd, (struct sockaddr*)&server_info, server_info_len)){
    perror("bind");
    return -1;
  }

  if (0 > listen(sfd, 0)){
    perror("listen");
    return -1;
  }
  
  int cfd = accept(sfd, &client_info, &client_info_len);
  if (0 > cfd){
    perror("accept");
    return -1;
  }
  
  char *hello = "Hello World!\n";
  ssize_t sent = send(cfd, (void *)hello, strlen(hello), 0);
  close(cfd);
}
