/**
 * @author  Hasan Onuralp AGCA
 * @date    06.06.2024
 *
 * @brief   Reverse string algorithm
 *
 */

#include <stdio.h>

int main()
{
	char str[] = "istanbul";

	int len;
	int temp;

	for(len = 0; str[len] != '\0'; ++len)
		;

	for(int i = 0; i < len / 2; ++i){
		temp = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = temp;
	}

	printf("%s\n", str);
}