#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LMC 3064894
 
int main(int argc, char const *argv[]) {
    char str[LMC], key[LMC];
    fflush(stdin);
    strcpy(key, argv[2]);
    printf("Input: ");
    fgets(str, sizeof(str), stdin);
    int inLen = strlen(str), keyLen = strlen(key), i, j;
    char newKey[inLen], encrypted[inLen], decrypted[inLen];

    //generating new key
    for(i = 0, j = 0; i < inLen; ++i, ++j){
        if (str[i] == ' ') {
          newKey[i] = ' ';
          --j;
        } else {
          if(j == keyLen)
            j = 0;
          newKey[i] = toupper(key[j]);
        }
    }
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < inLen - 1; ++i) {
      if (str[i] == ' '){
        encrypted[i] = ' ';
      } else {
        encrypted[i] = ((toupper(str[i]) + newKey[i]) % 26) + 'A';
      }
    }
    encrypted[i] = '\0';
 
    //decryption
    for(i = 0; i < inLen - 1; ++i) {
      if (str[i] == ' ') {
        decrypted[i] = ' ';
      } else {
        decrypted[i] = ((toupper(str[i]) - newKey[i] + 26) % 26) + 'A';
      }
    }
    decrypted[i] = '\0';
 
    if (strcmp(argv[1], "e") == 0) {
        printf("Encrypted: %s\n", encrypted);
    } else {
        printf("Decrypted: %s\n", decrypted);
    }

	return 0;
}