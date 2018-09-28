#ifndef COMUNICA_H
#define COMUNICA_H

int envia_arquivo(char *psArquivo, unsigned char *psLinha, int tamanho, int adiciona);
int recebe_arquivo(char *psArquivo, unsigned char *psLinha, int tamanho);
int envia_udp(char *psIp, int porta, unsigned char *psLinha, int tamanho);
int recebe_udp(char *psIp, int porta, unsigned char *psLinha, int tamanho);
void carregaDll(void);
unsigned char calcBCC(char* psLinha, int qtde);
char envia_coisas(int acr, char rsp[255]);
char recebe_coisas(char msg[255], int acr);
void isPalindrome(char str[]);

#endif
