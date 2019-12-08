#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void passGenerator(char *password);
void checkPass(char *p);

int main(int argc, char const *argv[])
{
	int choice;
	size_t bufferSize = 5;
	char *buffer;
	buffer = (char *)malloc(bufferSize * sizeof(char));
	char password[4];
	char strPass[5];
	printf("\nPassword Generator\n");
	printf("This program will:-\n");
	printf("\n\t\u2022 Generate a password\n");
	printf("\t\u2022 Guesses the password\n");
	printf("\t\u2022 Displays the Generated Password and Terminates the Program\n");
	do{
		printf("\n\n\nSelect one of the following : \n\n");
		printf("\t1. Generate a password\n");
		printf("\t2. Guesses the password\n");
		printf("\t9. Displays the Generated Password and Terminates the Program  ");
		getline(&buffer, &bufferSize, stdin);
		choice = strtol(buffer, NULL, 10);

			switch(choice){
				case 1:
					printf("\nPassword is Generated: ");
					passGenerator(password);
					strncpy(strPass, password, 4);
					printf("%s\n\n", strPass);
					break;
				case 2:
					checkPass(strPass);
					break;
				case 9:
					printf("\nThe Generated Password: %s\n\n", strPass);
					break;
				default:
					printf("\nInvalid selection");
					break;

			}
			
	}while((choice != 1 || choice != 2) && choice != 9);
	printf("This Algorithm is designed and Implemented by\n");
	printf("Sky Monts - Security Group Inc\n");
	printf("October - 29 - 2019\n\n");
	return 0;
}

void passGenerator(char password[]){
	char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
	char specialSymbols[] = {'!', '$', '%', '&', '\'', '(', ')', '*', '+',',','-', '.',
							'/', ';', '<', '=', '>', '?', '@', '[', ']', '}', 
							'{', '^', '~', '#', '`', ':'};
	char captlAlp[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
					'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',};
	char smallAlph[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 
						'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
	srand(time(0));
	password[0] = numbers[rand() % 10]; 
	password[1] = specialSymbols[rand() % 28];
	password[2] = captlAlp[rand() % 26];
	password[3] = smallAlph[rand() % 26];
	return;

}

void checkPass(char *p){
	char str[20];
	printf("\nEnter password: ");
	scanf("%s", str);
	if (strcmp(str, p) == 0){
		printf("\nPassword is correct\n");
	}
	else printf("\nIncorrect password\n");
	while ((getchar()) != '\n');
	return;
}
