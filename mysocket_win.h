#include <winsock.h>
#include <iostream>
#include <String>
#include <string.h>
#ifndef LINUX
#define SOCKET int
#endif
class mysocket
{
private:
  std::string a;
  int i = 0;

public:
  SOCKET creat();
  SOCKET creattcp();
  SOCKET creatudp();
void  mysocket(std::string g)
  {
    if (!strcmp(a, "tcp") || !strcmp(a, "TCP") || !strcmp(a, "Tcp"))
    {
      i = 0;
    }
    if (!strcmp(a, "udp") || !strcmp(a, "UDP") || !strcmp(a, "Udp"))
    {
      i = 0;
    }
    else
    {
      i = -1;
      std::cout << "put right format,use ***.ch(string) to change format\n";
    }
  }
  void ch(std::string s)
  {
    if (!strcmp(s, "tcp") || !strcmp(s, "TCP") || !strcmp(s, "Tcp"))
    {
      i = 0;
    }
    if (!strcmp(s, "udp") || !strcmp(s, "UDP") || !strcmp(s, "Udp"))
    {
      i = 0;
    }
    else
    {
      i = -1;
      std::cout << "put right format,ep:tcp,TCP,Tcp||udp,UDP,Udp\n";
    }
  }
  SOCKET creat()
  {
    if (i == 1)
    {
      SOCKET g = creattcp();
      return g;
    }
    if (i == 0)
    {
      SOCKET g = creatudp();
      return g;
    }
    else
    {

      std::cout << "put right format,ep:  tcp,TCP,Tcp||udp,UDP,Udp\n";
      std::cout << "use ***.ch(string) to change format\n";
    }
  }

  SOCKET creattcp()
  {

    return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  }
  SOCKET creatudp()
  {

    return socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  }
};
