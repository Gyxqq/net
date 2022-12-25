#include<winsock.h>
#ifdef LINUX
class myread_write{
  private:
  int sock;
public:
   void  myread_write(int sock1){
        sock=sock1;
    };
   int  mywrite(char *buf,int len){
      int g=write(sock,buf,len);
      return g;
    }
   int  myread(char *buff.int len){
      int g=read(sock,buf,len);
      return g;
    }
}
#endif
#ifndef LINUX
class myread_write{
  private:
  SOCKET sock;
  public:
  void int myread_write(SOCKET sock1){
    sock=sock1;
  }
  int mywrite(char *buff,int len){
    int g=send(sock,buff,len,0);
    return g;
  }
  int myread(char *buff,int len){
    int g=recv(sock,buff,len,0);
  }
}
