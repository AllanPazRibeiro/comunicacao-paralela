#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Comunica.h"
char recebe_coisas(char msg[255], char acr){
	char stTemp[255];
	char stIp[16];
	int Porta = 0;
	if(sizeof(msg)!= 0 && acr !=""){
		printf("Digite a porta no servidor: ");
		fflush(stdin);
		scanf("%d", &Porta);
		printf("\nAguardando mensagens ...\n");
	
		while(1)
		{
			memset(&stTemp, 0, sizeof(stTemp));
			memset(&stIp, 0, sizeof(stIp));
			recebe_udp(stIp, Porta, stTemp, sizeof(stTemp));
			printf("%s>%s\n", stIp, stTemp);
		}
		return 
	}
	
}
int main(int argc, char *argv[]) 
{
	char recebe_coisas();
	return 0;
}
