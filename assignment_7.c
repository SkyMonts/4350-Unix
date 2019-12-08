# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/*
NAME: Sky Monts     CS 4350 - Unix Systems Programming
Serial # : 20
Assignment Number : _____7______
Due	Date : 12 / 2 / 2019 @ 5:30 pm
*/

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
void* evenNumbers();
void* oddNumbers();
void* hailstoneSeq();
void* isArmstrong();
int choice;
int count  =  1;
int t1Done, t2Done, t3Done = 0;
 

int main(){
	printf("\n\nWelcome to Sky Mont's Thread app\n\n");
	printf("This program will do the following : \n\n");
	printf("Accepts an integer number X from the user ");
	printf("and then uses\n4 synchronized threads in order to do the following :\n\n");
	printf("5. The first thread prints all odd numbers between 1 and X.\n");
	printf("6. The second thread prints all the even numbers between 1 and X.\n");
	printf("7. The third thread print the hailstone sequence for the number X .\n");
	printf("8. The last thread determines whether or not X is an Armstrong number.\n\n");
	pthread_t thread1_id;
	pthread_t thread2_id; 
	pthread_t thread3_id; 
	pthread_t thread4_id; 
	printf("Enter an integer > 0 --- >     ");
  	if (scanf("%d", &choice) != 1 || choice <= 0) {
    	printf("\n***   Number must be greater than 0   ***\n");
    	goto End;
  	}

  
	pthread_create(&thread1_id, NULL, &evenNumbers, NULL);
	pthread_create(&thread2_id, NULL, &oddNumbers, NULL);
	pthread_create(&thread3_id, NULL, &hailstoneSeq, NULL);
	pthread_create(&thread4_id, NULL, &isArmstrong, NULL);
	pthread_join(thread1_id, NULL);
 	pthread_join(thread2_id, NULL);
 	t1Done = 1; 
 	t2Done = 1;
 	pthread_join(thread3_id, NULL);
 	t3Done = 1;
 	pthread_join(thread4_id, NULL);

 	End:
 	printf("\nProgram by Sky Monts\n12 - 2 - 2019\n");
	return 0;
}

void* oddNumbers(){
	while(count <= choice){
		pthread_mutex_lock(&lock);
		while(count % 2 != 0)
			pthread_cond_wait(&condition, &lock);

		if (count != choice + 1 )
			printf("Function 1: %d\n", count);

		count++;
		pthread_cond_signal(&condition);
		pthread_mutex_unlock(&lock);

		
	}
	return NULL;
}

void* evenNumbers(){
		while(count <= choice){
		pthread_mutex_lock(&lock);
		while(count % 2 == 0)
			pthread_cond_wait(&condition, &lock);

		if(count != choice + 1)
			printf("Function 2: %d\n", count);

		count++;
		pthread_cond_signal(&condition);
		pthread_mutex_unlock(&lock);

	
	}
	return NULL;
}

void* hailstoneSeq(){
	while(!t1Done && !t2Done);
	printf("\nFunction 3 - Hailstone Process Started\n");
	printf("Input Number %d\n", choice);
	printf("Hailstone sequence of %d is : ", choice);
	int i = choice;
	while(i > 1){
		
		if(i % 2 == 0){
			i = i/2;
		}
		else{
			i = (3*i) + 1;
		}
		printf("%d ", i );
	}
	printf("\n");
	
	return NULL;
}

void* isArmstrong(){
	while(!t3Done);
	int i = choice;
	int remainder, result;
	while (i != 0)
    {
        remainder = i%10;
        result += remainder*remainder*remainder;
        i /= 10;
    }
    if(result == choice){
        printf("\n%d is an Armstrong number.", choice);
    }
    else{
        printf("\n%d is not an Armstrong number.", choice);
    }
    printf("\n");
    return NULL;
}

