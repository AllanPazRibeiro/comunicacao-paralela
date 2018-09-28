#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "Comunica.h"

typedef struct
{
	char header;
	char end_origem;
	char end_destino;
	char msg[255];
	char footer;
	char cks;
}SProtoSimples;


char envia_coisas(int acr, char rsp[255], char msg[255]){
	if(acr != ""  && sizeof(rsp) !=0 && sizeof(msg) !=0){
		SProtoSimples Mensagem;

		memset(&Mensagem, 0, sizeof(SProtoSimples));

		Mensagem.header = 0x02;
		Mensagem.end_origem = 1;
		Mensagem.end_destino = 2;
		strcpy(Mensagem.msg, msg);
		Mensagem.footer = 0x03;
		Mensagem.cks = calcBCC((char*)&Mensagem, sizeof(SProtoSimples) - 1);

		envia_udp("127.0.0.1", 8000, (unsigned char*)&Mensagem, sizeof(SProtoSimples) - 1);
		return acr;
	}
	return 0;
	
}

// A function to check if a string str is palindrome
void isPalindrome(char str[])
{
	// Start from leftmost and rightmost corners of str
	int l = 0;
	int h = strlen(str) - 1;

	// Keep comparing characters while they are same
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			printf("%s is Not Palindrome\n", str);
			return;
		}
	}
	printf("%s is palindrome\n", str);
}

int main(int argc, char *argv[]) 
{
	
	char msg[255];
	int acr = 0;
	char rsp[255];

	scanf("%s", msg);
	strcpy(rsp, "receive");

	isPalindrome("SAIPPUAKIVIKAUPPIAS");
	system("pause");

	/*while(1){
	if(sizeof(msg)!=0){
	acr = 0x06;
	char envia_coisas(acr, msg);
	}
	if(acr = 0x06){
	char recebe_coisas(msg, acr);
	char envia_coisas(acr, rsp);
	}
	if(sizeof(rsp)!=0){
	char envia_coisas(rsp, acr);
	}
	}*/


	envia_coisas(555,"OI","BATATA");
	
	return 0;
}
