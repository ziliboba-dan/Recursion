#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int kol)
{
	if (kol > 2) {
		printf("mass[%d] = mass[%d] + mass[%d]\n", kol-1, kol - 2, kol - 3);
	}
	else printf("mass[%d] = mass[%d]\n", kol-1, kol-1);
}

/* Sum_array recursion */
int sum_array(int arr[], int count)
{	
	count--;
	if (count == 0) {
		return arr[count];	
	}
	
	return (arr[count] + sum_array(arr, count)); 
}

/* Sum_array_iter */
int sum_array_iter(int arr[], int product, int num, int count)
{	
	int max = count - 1;
	if (num > max) {
		return product;
	}
	return 	sum_array_iter(arr, product + arr[num], num + 1,count);	
}

/* Fib recursion*/
int fib(int *first, int kol)
{
	if (kol <= 2) {
		print(kol);
		return *(first + (kol - 1));
	}
	print(kol);
	return fib(first, kol - 2) + fib(first, kol - 1); 
}

/* Fib_iter */
int fib_iter(int first, int second, int n, int tr)
{
	//printf("fib(%d,%d,%d,%d)\n", first, second, n, tr);
	if (tr == n) {
		return second;
	}
	tr++;
	return fib_iter(second, first + second, n, tr); 
}

char *IntToStr(int value, char *str, int base)
{  	
	int count = 0;
	do {
		int digit = value % base;
		str[count++] = (digit > 9) ? digit - 10 +'A' : digit + '0';
	} while ((value /= base) != 0);

	str[count] = '\0';
	int i;
	printf("%d\n", count);
	for (i = 0; i < count / 2; i++) {
		char symbol = str[i];
		str[i] = str[count - i - 1];
		str[count - i - 1] = symbol;
	}
	return str;
}

int main() 
{
	int count;
	scanf("%d", &count);
	if (count == 0) {
		return 0;
	}
	int arr[count];
	for (int i = 0; i < count; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Sum recur = %d\n", sum_array(arr, count));

	printf("Sum iter = %d\n", sum_array_iter(arr, arr[0], 1, count));
	
	int kol;
	printf("Input for fibonachi\n");
	scanf("%d", &kol);
	if (kol < 3) {
		printf("Input kol > 2\n");
		return 0;
	}	
	int mass[kol];
	printf("Input 2 fist fibonachi number\n");
	scanf("%d", &mass[0]);
	scanf("%d", &mass[1]);
	int tr = 2;
	printf("Recursion fib: %d\n", fib(&mass[0], kol));
	printf("Iter,fib %d\n", fib_iter(mass[0], mass[1], kol, tr));
	scanf("%d", &kol);
	int base;
	scanf("%d", &base);
	char str[20];
	printf("%s\n", IntToStr(kol, str, base));

	return 0;
}
