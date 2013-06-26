#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 64

int str[N];
int i = 0;

int fib(int n)
{
    if ((n==0) || (n==1)) 
			return n;
	else
		return fib(n-1)+fib(n-2);
}

void find_fib(int a, int b, int M)
{
    if (b >= M)
        return;
    printf("%d ", b);
	str[i++] = b;
    find_fib(b, a + b, M);
}

int main()
{
	int M, sum, i = 0, j;
	char p[N], *s;
	clock_t begin, end;
	FILE *fin = fopen("1.txt","w");
	printf("Enter number: ");
	scanf("%d", &M);
	begin = clock();
	fib(M - 1);
	end = clock();
	find_fib(0, 1, M);
	printf("\n\n\nTime for testing : %lf s\n",(end-begin)/(double)CLOCKS_PER_SEC);
	for( i = 0; i < M - 1; i++)
		fputs(itoa(str[i], p , 10), fin);
	fclose(fin);
	return 0;
}