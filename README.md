# net
Windows，Linux网络通信相关
class mysocket 
构造函数：
win 
SOCKET mysocket(string s)//s=tcp||udp
linux
int mysocket(string s)//s=tcp||udp


class mybind
构造函数：
win 
int mybind(char ip[],int port,SOCKET socket);//server
linux
int mybind(char ip[],int port,int socket);


class myconnect
win 
int myconnect(char ip[],int port, SOCKET socket);
linux
int myconnect(char ip[],int port,int socket);//client

listen//使套接字进入监听状态 backlog为请求队列的最大长度
int listen(int sock, int backlog);  //Linux
int listen(SOCKET sock, int backlog);  //Windows

accept
int accept(int sock,struct sockaddr *addr,socklen_t *addrlen);//linux
SOCKET accept(SOCKET sock,struct sockaddr *addr,socklen_t *addrlen);//windows
int/SOCKET sock 服务器端的套接字
addr保存客户端的IP地址和端口号
addrlen是addrd的长度
返回一个新的套接字用于和客户端通信

READ&&WRITE
ssize_t write(int sock, const void *buf, size_t nbytes);//linux
linux下不区分套接字和普通文件,直接用write||read读写
buf为缓冲区地址,nbytes为写入的字节数
ssize_t read(int sock, void *buf, size_t nbytes);//同write

int send(SOCKET sock, const char *buf, int len, int flags);
int recv(SOCKET sock, char *buf, int len, int flags);
封装myread_write类
构造函数
myread_write(int sock)//linux
myread_write(SOCKET sock)//windows
成员函数
mywrite(char *buff,int len)//linux&&windows
myread(char *buff,int len)//linux&&windows

thread//需要加入编译指令 -std=c++11
std::thread
构造函数 thread_object()
允许传参方式
1.函数指针传参
int g(int c);
ep. std::thread(g,c);
2.可调用对象
ep.
class g{
  public:
  void operator()(int c){

  }//重载（）运算
}
std::thread(opreater(),c);
成员函数
thread.join()//等待线程同步


