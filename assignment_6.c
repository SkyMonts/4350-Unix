#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
NAME: Sky Monts
Serial Number: 20
Assignment Number: 6
Due Date 11/18/2019
*/


int main(){
	printf("\nFile Manipulation Program\n\n");
	FILE *f;
	char c;
	// Creates file zp6in.txt and writes to it
	f = fopen("zp6in.txt", "w+r");
	fputs("Texas State University\n601 University Drive\nSan Marcos, Texas 78666\nUSA\n", f);

	// Displays the number of lines in input file
	printf("\n");
	printf("File\n------------------------------\n");
	int lineCount = 0; 
	rewind(f);
	for(c = getc(f); c != EOF; c = getc(f)){
		if(c == '\n'){
			lineCount++;
		}
		printf("%c", c);
	}
	printf("\n------------------------------\n");
	printf("File Line Count: %d\n", lineCount);
	printf("------------------------------\n\n");

	// Displays the number of words in input file
	rewind(f);
	int wordCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(c == ' ' || c == '\n'){
			wordCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Word Count: %d\n", wordCount);
	printf("------------------------------\n\n");

	// Displays the number of lower case letters in input file
	rewind(f);
	int small_LetterCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(islower(c)){
			small_LetterCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Small Letter Count: %d\n", small_LetterCount);
	printf("------------------------------\n\n");

	// Displays the number of capital letters in input file
	rewind(f);
	int big_LetterCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(isupper(c)){
			big_LetterCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Capital Letter Count: %d\n", big_LetterCount);
	printf("------------------------------\n\n");

	// Displays the number of digits in input file
	rewind(f);
	int digitCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(isdigit(c)){
			digitCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Digit Count: %d\n", digitCount);
	printf("------------------------------\n\n");

	// Displays the number of spaces in input file
	rewind(f);
	int spaceCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(c == ' '){
			spaceCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Space Count: %d\n", spaceCount);
	printf("------------------------------\n\n");

	// Displays the number of special characters in input file
	rewind(f);
	int specialCharCount = 0; 
	for(c = getc(f); c != EOF; c = getc(f)){
		if(!isdigit(c) && !isalpha(c) && c != ' ' && c != '\n'){
			specialCharCount++;
		}
		//printf("%c", c);
	}
	printf("------------------------------\n");
	printf("File Special Character Count: %d\n", specialCharCount);
	printf("------------------------------\n\n");

	// Copies the content of the input file without any spaces, 
	// changing all small letters to capital letters and vice versa to a new file
	rewind(f);
	FILE *f2;
	f2 = fopen("zp6out1.txt", "w+r");
	for(c = getc(f); c != EOF; c = getc(f)){
		Conditions:
		if(isupper(c)){
			c = tolower(c);
			
		}
		else if(islower(c)){
			c = toupper(c);
			
		}
		else if(c == ' '){
			c = getc(f);
			goto Conditions;
		}
		fputc(c, f2);
	}
	
	// Reads the input file one line at a time, and writes these lines to a second file 
	// (zp6out2.txt). Adds a line number for each line in the new file.
	rewind(f);
	FILE *f3;
	f3 = fopen("zp6out2.txt", "w+r");
	int line = 1; 
	fprintf(f3, "%d", line);
	fprintf(f3, ": ");
	for(c = getc(f); c != EOF; c = getc(f)){
		if(c == '\n' && line < lineCount){
			line++;
			fputc(c, f3);
			c = getc(f);
			fprintf(f3, "%d", line);
			fprintf(f3, ": ");

		}
		fputc(c, f3);
	}
	

	fclose(f);
	fclose(f2);
	fclose(f3);

	// Displays zp6out1.txt and zp6out2.
	system("echo zp6out1.txt");
	printf("------------------------------\n");
	system("cat zp6out1.txt");
	system("echo");
	system("echo zp6out2.txt");
	printf("------------------------------\n");
	system("cat zp6out2.txt");
	printf("\n");
	system("echo Implemented by Sky Monts");
	system("echo November - 18 - 2019");
	system("echo");


	







	return 0;
}