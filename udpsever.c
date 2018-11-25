//这是一个简单的udp服务端
//八个头文件
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>



int main()
{
	//创建套接字
	int sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd<0)

		perror("creat error");
     
		//绑定

        struct sockaddr_in  addr;
		addr.sin_family=AF_INET;
		addr.sin_port=htons(9000);                              //ntohs
		addr.sin_addr.s_addr=inet_addr("10.10.31.119");                          //10.10.31.119   inet_ntoa
        socklen_t len=sizeof(addr);
		int ret=bind(sockfd,  (struct sockaddr*)&addr   ,len  );
		if(ret<0)
		{	perror("bind error");
		    close (sockfd);
			return -1;

		}
		
		//接收
			
			char buff[1024]={ };

			while(1)
			{
				memset(buff,0x00,1024);
                 struct sockaddr_in client;
                 len=sizeof(client); 
				ssize_t rlen=recvfrom(sockfd,buff,1023,0,(struct sockaddr*)&client, &len     );
				if(len<=0)
					perror("recvfm error");
				else
					printf("client[%s %d ]   say:[%s]",
					           inet_ntoa(addr.sin_addr) ,ntohs(addr.sin_port) ,buff );
				memset(buff,0x00,1024);
				scanf("%s",buff);
			    	sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&client,len      );  
				
					}
	
      close (sockfd);
	
	return 0;
	}
