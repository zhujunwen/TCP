# TCP
Base on C lang,make a function to easy to program TCP

/************************For TCP server**********************************/
int zje_TcpSer_socket(int port,int listen_num) //For TCP serverenter the port and the listen num，return the socket fd which is                                                    //created in the function输入端口号和监听的数目，返回创建的socket套接字

int zje_accept(int sockfd)  //waitting for the TCP client connect，if have a client connect，return a new socket fd which is                                   //represent the client。等待TCP客户端的连接，如果有客户端连接，则返回代表客户端的socket套接字。

/************************For TCP server**********************************/


/************************For TCP client**********************************/
int zje_TcpCli_socket(int port,char *server_ip) //For TCP client，enter the port and TCP server ip as args，return socket fd                                                      //represent the TCP server 用于TCP客户端，输入端口号和服务端主机IP作为参数，返回代表服务                                                //端的socket套接字
/************************For TCP client**********************************/

int zje_close(int sockfd) //shut down the  socket fd。关闭socket套接字
