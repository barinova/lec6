#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int tradSum(int *arr, int N)
{
	int i = 0, sum = 0;
	for(; i < N; i++)
		sum += arr[i];
	return sum;
}

int recSum(int *arr, int N)
{
	if(N==1)
	return *arr;
	else
	return *arr+recSum(arr+1,N-1);
}


int main()
{
	//recommended to enter 11, 12
	int M, N, *arr, i = 0, tr, rec;
	clock_t beginTr,endTr, beginRec, endRec;
	printf("Enter pow: ");
	scanf("%d", &M);
	N = (int)pow((double)2, M);
	arr =(int *)malloc(N*sizeof(int));

	for(; i < N; i++)
		arr[i] = rand()%1000;

	for(i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
		printf(" ");
	}

	beginTr = clock();
	tr = tradSum(arr, N);
	endTr = clock();

	beginRec = clock();
	rec = recSum(arr, N);
	endRec = clock();

	free(arr);
	printf("\n\n\nTime for testing 'Tradition algorithm': %lf s\n",(endTr-beginTr)/(double)CLOCKS_PER_SEC);
	printf("Time for testing 'Recursion algorithm': %lf s\n",(endRec-beginRec)/(double)CLOCKS_PER_SEC);
	return 0;
}