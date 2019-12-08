# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
void patternOne(int size);
void patternTwo(int size);
void patternThree(int size);
void patternFour(int size);



int main(int argc, char const *argv[])
{
	int size, choice;
	size_t bufferSize = 5;
	char *buffer;
	char c = '0';
	buffer = (char *)malloc(bufferSize * sizeof(char));
	printf("\n\t\t\tWelcome to My Pattern Program\n\n");
	printf("This program is written by (Sky Monts). The purpose of this program is"); 
	printf(" to \ncreate four different patterns of different sizes. The size of each");
	printf(" pattern \nis determined by the number of columns or rows. For example, a");
	printf(" pattern of \nsize 5 has 5 columns and 5 rows. Each pattern is made up of");
	printf(" character P \nand a digit, which shows the size. The size must be between");
	printf(" 2 and 9.\n");
	do
	{
		printf("\nMenu\n1.\tPattern one\n2.\tPattern Two\n");
		printf("3.\tPattern Three\n4.\tPattern Four\n15.\tQuit\n\n");
		Input:
		printf("Choose an option (between 1 and 4 or 15 to end program): ");
		getline(&buffer, &bufferSize, stdin);
		choice = strtol(buffer, NULL, 10);
		switch(choice){
			case 1:
				printf("Choose a pattern size (between 2 and 9): ");
				scanf("%d", &size);
				while(!(size >=2 && size <= 9)){
					printf("Your size is incorrect. Please try again\n");
					printf("Choose a pattern size (between 2 and 9): ");
					scanf("%d", &size);
				}
				patternOne(size);
				break;
			case 2:
				printf("Choose a pattern size (between 2 and 9): ");
				scanf("%d", &size);
				while(!(size >=2 && size <= 9)){
					printf("Your size is incorrect. Please try again\n");
					printf("Choose a pattern size (between 2 and 9): ");
					scanf("%d", &size);
				}
				patternTwo(size);
				break;
			case 3:
				printf("Choose a pattern size (between 2 and 9): ");
				scanf("%d", &size);
				while(!(size >=2 && size <= 9)){
					printf("Your size is incorrect. Please try again\n");
					printf("Choose a pattern size (between 2 and 9): ");
					scanf("%d", &size);
				}
				patternThree(size);
				break;
			case 4:
				printf("Choose a pattern size (between 2 and 9): ");
				scanf("%d", &size);
				while(!(size >=2 && size <= 9)){
					printf("Your size is incorrect. Please try again\n");
					printf("Choose a pattern size (between 2 and 9): ");
					scanf("%d", &size);
				}
				patternFour(size);
				break;

			case 15:
				goto End;

			default:
				printf("Your option is incorrect. Please try again\n");
				goto Input;
		}
		while ((getchar()) != '\n');
	}while(1);
	End:
	printf("\nPattern Program By: Sky Monts–10–18-2019\n");
	return 0;
}

void patternOne(int size){
	printf("\nPattern 1 is displayed\n\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i == j) {
				printf("%d", size);
			}
			else {
				printf("P");
			}
		}
		printf("\n");	
	}
}
void patternTwo(int size){
	printf("\nPattern 2 is displayed\n\n");
	for(int i = size; i > 0; --i){
		for(int j = size; j > 0; --j){
			if((i + j) - 1 == size) {
				printf("%d", size);
			}
			else {
				printf("P");
			}
		}
		printf("\n");	
	}
}
void patternThree(int size){
	printf("\nPattern 3 is displayed\n\n");
for(int i = size; i > 0; --i){
		for(int j = size; j > 0; --j){
			if((i + j) <= size) {
				printf("%d", size);
			}
			else {
				printf("P");
			}
		}
		printf("\n");	
	}
}
	
void patternFour(int size){
	printf("\nPattern 4 is displayed\n\n");
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i>j) {
				printf("%d", size);
			}
			else {
				printf("P");
			}
		}
		printf("\n");	
	}
}
