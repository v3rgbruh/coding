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
  server_info.sin_addr.s_addr = htonl(0x7f000001);
  server_info.sin_port = htons(1337);
  socklen_t server_info_len = sizeof(server_info);

  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (0 > sfd){
    perror("socket");
    return -1;
  }

  if (0 > connect(sfd, (struct sockaddr*)&server_info, server_info_len)){
    perror("connect");
    return -1;
  }

  char buffer[1024];
  ssize_t recvd = recv(sfd, buffer, 1024-1, 0);
  printf("%1024s\n", buffer);

  close(sfd);

  return 0;
}
