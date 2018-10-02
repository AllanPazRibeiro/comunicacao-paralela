#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_LENFI 5001

void isPalindrome(char str[]);


int main(int argc, char *argv[])
{
   FILE* f;

	f = fopen("Palindromos.txt", "r");

  char line[sizeof(f)];

  

  while (fgets(line,MAX_LENFI,f))
    {
    	/*E VEM A PERGUNTINHA*/
    	isPalindrome(line);
    }
  fclose( f );
  return 0;
}

// função pra checar se eh palindromosossssss
void isPalindrome(char str[])
{
	// começa da direita pra esquerda
	int l = 0;
	int h = strlen(str) - 1;

	// compara a merda ate que sejam iguais
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			printf("\n%s palindro\n", str);
			return;
		}
	}
	
}