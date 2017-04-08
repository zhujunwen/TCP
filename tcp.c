#include "zje.h"

/*TCP服务端初始化配置*/
int zje_TcpSer_socket(int port,int listen_num)
{
	int sockfd; 
	int size;  
	int on = 1;
	int ret;
	
	struct sockaddr_in saddr;  
	struct sockaddr_in caddr; 

	size = sizeof(struct sockaddr_in); 
	bzero(&saddr,sizeof(saddr)); 
	saddr.sin_family = AF_INET;     //AF_INET表示IPv4的类型  
    saddr.sin_port = htons(port);   //绑定8888端口  
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);   //绑定本机端口  

    sockfd = socket(AF_INET,SOCK_STREAM,0);//返回-1表示失败；  
    if(sockfd<0)
    {
    	perror("failed to socket");
    	return -1;
    }

    ret=setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)); 
    if(ret<0)
    {
    	perror("failed to setsockopt");
    	return -1;
    }

    ret=bind(sockfd,(struct sockaddr*)&saddr,size);//返回-1表示失败  
    if(ret==-1)
    {
    	perror("failed to bind");
    	return -1;
    }

    ret=listen(sockfd,listen_num); 
    if(ret==-1)
    {
    	perror("failed to listen");
    	return -1;
    }

    return sockfd;
}

/*TCP accept*/
int zje_accept(int sockfd)
{
	int new_sockfd;

	new_sockfd = accept(sockfd,(struct sockaddr*)&caddr,&size);//返回-1表示失败  
	if(new_sockfd == -1)
	{
		perror("failed to accept");
		return -1;
	}
	return new_sockfd;
}

/*TCP客户端连接客户端*/
/*返回连接服务端的sockfd*/
int zje_TcpCli_socket(int port,char *server_ip)
{
	int sockfd; 
	int size;  
	int on = 1;
	int ret ;
	
	struct sockaddr_in saddr;  
	struct sockaddr_in caddr; 

	size = sizeof(struct sockaddr_in); 
	bzero(&saddr,sizeof(saddr)); 
	saddr.sin_family = AF_INET;     //AF_INET表示IPv4的类型  
    saddr.sin_port = htons(port);   //绑定8888端口  
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);   
    inet_pton(AF_INET, server_ip, &saddr.sin_addr.s_addr);

    sockfd = socket(AF_INET,SOCK_STREAM,0);//返回-1表示失败；  
    if(sockfd<0)
    {
    	perror("failed to socket");
    	return -1;
    }

    ret=connect(sockfd,(struct sockaddr*)&saddr,size);
    if(ret<0)
    {
    	perror("failed to connect");
    	return -1;
    }
    printf("connect OK\n");
    return sockfd;
}

/*关闭socket套接字*/
int zje_close(int sockfd)
{
	close(sockfd);
	return 0;
}
