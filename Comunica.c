#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOWS
#ifdef WINDOWS
  #include <winsock.h>
  #pragma comment(lib,"Ws2_32.lib")
  WSADATA wsa_data;

#else
  #include<sys/socket.h> 
  #include<arpa/inet.h> //inet_addr

  #define INVALID_SOCKET -1
  #define SOCKET_ERROR INVALID_SOCKET
  typedef struct sockaddr SOCKADDR;
#endif

#include "Comunica.h"

int envia_arquivo(char *psArquivo, unsigned char *psLinha, int tamanho, int adiciona)
{
 FILE *fp = NULL;
 int ret = 1;
 char chAbreTipo[3] = { " b" };
 
 if(adiciona)
 {
 	chAbreTipo[0] = 'a';
 }
 else
 {
 	chAbreTipo[0] = 'w';
 }
 
 if((fp=fopen(psArquivo,chAbreTipo)) != NULL)
 {
  fwrite(psLinha,tamanho,1,fp);
  fclose(fp);
 }
 else 
   ret = 0;
 
 return ret;
}

int recebe_arquivo(char *psArquivo, unsigned char *psLinha, int tamanho)
{
 FILE *fp;
 int ret = 0;

 if((fp=fopen(psArquivo,"rb")) != NULL)
 {
  ret = fread(psLinha,tamanho,1,fp);
  fclose(fp);
 }
 
 return ret;
}

int envia_udp(char *psIp, int porta, unsigned char *psLinha, int tamanho)
{
    int ret=1, remote_socket = 0;
    struct sockaddr_in remote_address;

#ifdef WINDOWS
    carregaDll();
#endif

    remote_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (remote_socket == INVALID_SOCKET) 
    {
        ret = 0;
    }
    else
    {
        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(psIp);
        remote_address.sin_port = htons(porta);
        if(sendto(remote_socket,(char *)psLinha, tamanho, 0, (SOCKADDR *) &remote_address, sizeof(remote_address)) == SOCKET_ERROR) 
    	{
           ret = 0;
        }
	#ifdef WINDOWS
        closesocket(remote_socket);
	#else
	close(remote_socket);
	#endif
    }

#ifdef WINDOWS
  WSACleanup();
#endif

  return ret;
}

int recebe_udp(char *psIp, int porta, unsigned char *psLinha, int tamanho)
{
    int ret=1, local_socket = 0;
 	struct sockaddr_in remote_address;
 	int SenderAddrSize = sizeof (remote_address);
	 
#ifdef WINDOWS
    carregaDll();
#endif
  
    local_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (local_socket == INVALID_SOCKET) 
    {
        ret = 0;
    }
    else
    {
        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = htonl(INADDR_ANY);
        remote_address.sin_port = htons(porta);
        bind(local_socket,(struct sockaddr *) &remote_address, sizeof(remote_address));
        if((ret = recvfrom(local_socket,(char *)psLinha, tamanho, 0, (SOCKADDR *) &remote_address, &SenderAddrSize)) == SOCKET_ERROR) 
    	{
           ret = 0;
        }
        else
        {
        	strcpy(psIp,inet_ntoa(remote_address.sin_addr));
        }
	#ifdef WINDOWS
        closesocket(local_socket);
	#else
		close(local_socket);
	#endif
    }
    
#ifdef WINDOWS
WSACleanup();
#endif

return ret;
}

#ifdef WINDOWS
void carregaDll(void)
{
 WSAStartup(MAKEWORD(2, 0), &wsa_data);
}
#endif

unsigned char calcBCC(char* psLinha, int qtde)
{
	unsigned char uchBcc = 0;
	int contador;

	for (contador = 0; contador < qtde; contador++)
	{
		uchBcc ^= psLinha[contador];
	}

	return uchBcc;
}

