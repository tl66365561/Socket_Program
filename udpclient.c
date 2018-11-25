
//这是一个简单的udpk客户端
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	
	int sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd<0)
		perror("create error");
		//client need not bind;

   struct sockaddr_in severaddr;
   severaddr.sin_family=AF_INET;
   severaddr.sin_port=htons(9000);
   severaddr.sin_addr.s_addr=inet_addr("10.10.31.119");
   socklen_t len=sizeof(severaddr);

		while(1)
		{
			//after sendto,you can recvfrom
             char buff[1024]={};

			scanf("%s",buff);
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr *)&severaddr,len);
		    memset(buff,0x00,1024);
			//怎么复制粘贴？指定行内容
			//怎么打开多个文件窗口？
			//取消防火墙的命令？
           //  makefile 的编写？
           ssize_t rlen=recvfrom(sockfd,buff,1023,0,(struct sockaddr*)&severaddr,&len);
		   if(rlen<=0)
		   {
			   perror("recv error");
			   
			 return -1;
			 }

              printf("sever say [%s]",buff);

			}
      close(sockfd);	
	
	return 0;
	}
