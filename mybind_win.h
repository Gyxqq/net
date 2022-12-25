#include <winsock.h>
#include <iostream>
#include <String>
#include <string.h>
#ifdef LINUX
#define SOCKET int
#endif
class mybind
{
public:
  struct sockaddr_in serv_addr;
  int mybind(char ip[], int port, SOCKET sock)
  {
    memset(serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // ipv4
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    int g = bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    return g;
  }
  int mybind(std::string ip, int port, SOCKET sock)
  {
    char c[ip.size() + 1] = {};
    c = ip;
    mybind(c, port, sock);
  }
};

class myconnect
{
public:
  struct sockaddr_in serv_addr;
  int myconnect(char ip[], int port, SOCKET sock)
  {
    memset(serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // ipv4
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    int g = connnect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    return g;
  }
  int myconnect(std::string ip, int port, SOCKET sock)
  {
    char c[ip.size() + 1] = {};
    c = ip;
    myconnect(c, port, sock);
  }
}
