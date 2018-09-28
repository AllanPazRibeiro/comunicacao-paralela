#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Comunica.h"

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
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}

void main(){
	char msg[255];
	int acr = 0;
	char rsp[255];
	
	scanf("%s", msg);
	strcpy(rsp, "receive");
	
	palindromo_verifier("SAIPPUAKIVIKAUPPIAS"); 
	printf("aqui");
	
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
			char envia(rsp, acr);
		}
	}*/

}
