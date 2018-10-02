#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_LENFI 1024

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
			printf("\n%s p\n", str);
			return;
		}
	}
	
}

int main(int argc, char *argv[])
{
   FILE* f;
  char line[MAX_LENFI];

  f = fopen("Palindromos.txt", "r");

  while (fgets(line,MAX_LENFI,f))
    {
    	/*E VEM A PERGUNTINHA*/
    	isPalindrome(line);
    }
  fclose( f );
  return 0;
}
