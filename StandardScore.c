#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define BUFF_LEN 20

FILE *fp;
char *filename = "sample.dat";
char line[BUFF_LEN];
int data_size = 0;
double *data = NULL;

void ReadData();
double MeanA();	//算術平均
double Variance(double mean_a);	//分散
double Abs(double x);

int main(void)
{
	int i;
	double point = 0;
	ReadData();
	printf("%f点の偏差値 : %f\n", point, (point - MeanA()) / sqrt(Variance(MeanA())) * 10 + 50 );
	return 0;
}

void ReadData()
{
	fp = fopen(filename, "r");
	while(fgets(line, BUFF_LEN, fp) != NULL){
		data_size++;
	}
	fp = fopen(filename, "r");

	data = (double *)malloc(data_size);
	if(data == NULL){
		printf("メモリの確保に失敗した.\n");
		exit(1);
	}
	data_size = 0;
	while(fgets(line, BUFF_LEN, fp) != NULL){
		sscanf(line, "%lf", &data[data_size++]);
		//printf("%f\n", data[data_size-1]);
	}
}

double MeanA()
{
	int i;
	double sum = 0.0;
	for(i=0; i<data_size; i++){
		sum += data[i];
	}
	return sum / (double)data_size;
}

double Variance(double mean_a)
{
	int i;
	double sum = 0.0;
	for(i=0; i<data_size; i++){
		sum += (data[i] - mean_a) * (data[i] - mean_a);
	}
	return sum / (double)data_size;
}

double Abs(double x)
{
	if(x>=0.0){
		return x;
	}else{
		return -x;
	}
}
