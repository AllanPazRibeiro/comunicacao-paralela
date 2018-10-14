#include <stdio.h>
#include <math.h>   // ceil()
#include <stdlib.h> // exit()

int main(int argc, char *argv[]) {
	char splitAParadaToda();
	
	FILE *ptr_source, *ptr_part, *ptr_combinations;
	size_t parts, i;
	unsigned long int part_size, written_bytes;
	int byte;
	int bytes[byte];
	char cr;
	char ch;

	ptr_source = fopen("sequencia.txt", "rb");
	ptr_combinations = fopen("padroes.txt", "rb");
	
	
	fseek(ptr_source, 0, SEEK_END);
	part_size = (52428800/8);

	parts = (size_t) ceil((double) ftell(ptr_source) / part_size);
	rewind(ptr_source);

	for (i = 0; i < parts; i++) {
			
		ptr_part = fopen("sequenciaParte.txt", "wb");
		

		for (written_bytes = 0; written_bytes < part_size &&
		    (byte = fgetc(ptr_source)) != EOF; written_bytes++)
		{
			fscanf(ptr_part,"%c",&cr);
			if(cr!=(fgetc(ptr_combinations)!=EOF)){
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
