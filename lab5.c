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
struct hostent *hen;
char *IPaddr;
s=socket(AF_INET, SOCK_DGRAM, 0);
server.sin_family=AF_INET;
server.sin_port=5000;
server.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(s,(struct sockaddr *)&server, sizeof(server));
n=sizeof(client);
printf("DNS is ready......");
while(1)
{
strcpy(b2,"");
recvfrom(s,b1,sizeof b1, 0, (struct sockaddr*)&client,&n);
hen=gethostbyname(b1);
printf("\nClient request for Domain name : %s\n",hen->h_name);
IPaddr=inet_ntoa(*((struct in_addr*)hen->h_addr));
printf("DNS IP Address is : %s\n", IPaddr);
strcpy(b2,IPaddr);
sendto(s,b2,sizeof b2,0,(struct sockaddr*)&client,n);
}
return 0;
}

