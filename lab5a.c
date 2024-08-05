#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
int main()
{
struct sockaddr_in server, client;
int s,n;
char b1[100], b2[100];
s=socket(AF_INET, SOCK_DGRAM, 0);
server.sin_family=AF_INET;
server.sin_port=5000;
server.sin_addr.s_addr=inet_addr("127.0.0.1");
n=sizeof(server);
while(1){
printf("\nEnter canonical Domain name : ");
scanf("%s",b2);
sendto(s,b2,sizeof(b2),0,(struct sockaddr*)&server,n);
recvfrom(s,b1,sizeof(b1),0,NULL,NULL);
printf("%s\n",b1);
}
return 0;
}
