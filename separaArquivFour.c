#include <stdio.h>
#include <math.h>   
#include <stdlib.h>
#include <pthread.h>
int separaAPorraToda(){
	char splitAParadaToda();
	
	FILE *ptr_source, *ptr_part, *ptr_combinations; // Ponteiros para os arquivos
	size_t parts, i; //Quantidade inteira para as partes do arquivos
	unsigned long int part_size, written_bytes; // long int para o tamanho em bytes e bytes escritos nos arquivos
	int byte; 
	int bytes[byte];
	int combinacoes[255]; //Carriage return, vulgo enter space meu brother

	ptr_source = fopen("sequencia.txt", "rb"); //Arquivo randomico do teacher PC bolsominion
	ptr_combinations = fopen("padroes.txt", "rb"); // Arquivo das sequencias do teacher PC bolsominion
	
	
	fseek(ptr_source, 0, SEEK_END); // fseek varre o arquivo till the end ma freeend
	part_size = (52428800/8); // Tamanho das partições chumbadinha

	parts = (size_t) ceil((double) ftell(ptr_source) / part_size); // Mesmo sendo chumbada o tamanho da parte, achei mais elengante criar uma variavel para quant de partes
	rewind(ptr_source); // Estabelece como ponto de inicio, o inicio do arquivo, bem loco

	for (i = 0; i < parts; i++) {
		//Cria o arquivo para as partes, melhoria seria colocar um nome dinamico, tipo sequencia1 ou sequencia2 e assim em diante	
		ptr_part = fopen("sequenciaParte.txt", "wb");
		
		//Forzin de lei, para escrever o texto inteiro até o seu fim, considerando o tamanho das partes do part_size
		for (written_bytes = 0; written_bytes < part_size &&
		    (byte = fgetc(ptr_source)) != EOF; written_bytes++)
		{
			//File sca, para alimentar os caraquiteres de combinacoes e usa-los para combinar
			fscanf(ptr_combinations,"%c",&combinacoes);
			//Pega as combinacoes e coloca nessa variavel abaixo
			combinacoes == (fgetc(ptr_combinations)!=EOF);
			//Se os written bytes for dif de zero e as combinacoes forem diferentes do final do arquivo, AI QUE FICA A DUVIDA
			if(written_bytes != 0 && ptr_part != combinacoes[written_bytes]){
				fputc(byte, ptr_part);
			}
			
		}

		printf("(%lu bytes)", written_bytes);
		fclose(ptr_part);
	}

	printf("\n\nDone!\n");
	fclose(ptr_source);
	
	return byte;
}

int main(int argc, char *argv[]) {
	int i; 
    pthread_t tid; 
   
    for (i = 0; i < 4; i++){
    	pthread_create(&tid, NULL, separaAPorraToda, NULL);  
	} 
        
	
	pthread_join(tid, NULL); 
	pthread_exit(NULL); 
    return 0;
}
