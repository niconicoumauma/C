#include<stdio.h>
#include<stdlib.h>
#define S 83
#define T 84
#define A 65
#define P 80

int main(void)
{
	int randNum;
	int i;
	int string[4];
	int now;
	//initialization
	for(i=0; i<4; i++){
		string[i] = 0;
	}
	srand(1);
	while(1){
		string[0] = string[1];
		string[1] = string[2];
		string[2] = string[3];
		string[3] = rand()%26 + 65;
		printf("%c", string[3]);
		if(string[0]==S && string[1]==T && string[2]==A && string[3]==P){
			printf("[END]\n<STAP細胞はあります！>\n");
			break;
		}
	}
	return 0;
}
