#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <locale>
#include <mem.h>

void makear(int *ar, int a, int b, int size)
{int i;
        for(i = 0; i < size; i++) // заполнение массива
        { ar[i]=a+(b-a)*rand()/RAND_MAX; }
}

void copyar(int *ar, int *br, int size)
{int i;
    for(i = 0; i < size; i++) // копирование массива
        { br[i] = ar[i];  }
}
void printar(int *ar, int k, int m)
 { int i;
     for(i = k; i < m;i++)
       { printf(" %d",ar[i]); }
     printf("\n");
}

void mmerge(int *a, int *b, int l, int m, int r)
 { int i,j,k;
    i = l;
    j = m+1;
    k = l;
    while ((i<=m)&&(j<=r)){
     if (a[i]<=a[j])
         b[k++] = a[i++];
     else
         b[k++] = a[j++]; }
    while (i<=m) {
      b[k++] = a[i++]; }
    while (j<=r) {
      b[k++] = a[j++]; }
    for (k=l; k<=r; k++){
        a[k] = b[k]; }
}

void msort(int *a, int *b, int l, int r)
{
int m;
    if (l<r){
    m = ((l+r)>>1);
    msort(a,b,l,m);
    msort(a,b,m+1,r);
    mmerge(a,b,l,m,r);
    } }

#define LeftChild( i ) ( 2 * (i) +1 )
#define GE( a,b ) ( a >= b )
#define LT( a,b ) ( a < b )

void SWAP(int &a, int &b)
{ int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void QSORTB(int * A, int l, int r)
{   int loc;
    if (l < r) {
        int i = l, j = r;
        int tmp,  pivot = A[l];
        for (;;) {
            while ((GE(A[j], pivot)) && (j > l))
                j--;
            while ((LT(A[i], pivot)) && (i < r))
                i++;
            if (i < j) {
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            } else {
                loc = j;
                break; }
}       QSORTB(A, l, loc);
        QSORTB(A, loc + 1, r); }
}

#define LeftChild( i ) ( 2 * (i) +1 )
#define GT( a,b ) ( a > b )
#define LT( a,b ) ( a < b )

void INSERTTWO(int *array)
{
    if (GT(array[0], array[1]))
    SWAP(array[0], array[1]);
    return;
}
void INSERTTHREE(int *array)
{
    if (LT(array[0], array[1])) {
    if (LT(array[1], array[2]))
    return;
        else if (LT(array[0], array[2]))
        SWAP(array[1], array[2]);
        else {
            int   Tmp = array[0];
            array[0] = array[2];
            array[2] = array[1];
            array[1] = Tmp; }
    } else {
        if (LT(array[0], array[2]))
        SWAP(array[0], array[1]);
        else if (LT(array[1], array[2])) {
           int Tmp = array[0];
            array[0] = array[1];
            array[1] = array[2];
            array[2] = Tmp;
        } else
        SWAP(array[0], array[2]); }
    return;
}
void INSERTFOUR(int *array)
{   int temp;
    if (GT(array[0], array[1])) {
        temp = array[0];
        array[0] = array[1];
        array[1] = temp; }
    if (GT(array[2], array[3])) {
        temp = array[2];
        array[2] = array[3];
        array[3] = temp; }
    if (GT(array[1], array[2])) {
        if (GT(array[0], array[3])) {
            temp = array[0];
            array[0] = array[2];
            array[2] = temp;
            temp = array[1];
            array[1] = array[3];
            array[3] = temp;
        } else {
            temp = array[1];
            array[1] = array[2];
            array[2] = temp;
            if (GT(array[0], array[1])) {
                temp = array[0];
                array[0] = array[1];
                array[1] = temp; }
            if (GT(array[2], array[3])) {
                temp = array[2];
                array[2] = array[3];
                array[3] = temp; }  }  }
}
#ifdef MY_CACHE_IS_ENORMOUS
#include "sort5.h"
#endif

void  INSERTIONSORT(int *array, unsigned long count)
{
    unsigned long   partition;
    long beg, ipg, end;
    int temp;

    switch (count) {
    case 0:
    case 1:
        return;
    case 2:
        INSERTTWO(array);
        return;
    case 3:
        INSERTTHREE(array);
        return;
    case 4:
        INSERTFOUR(array);
        return;
#ifdef MY_CACHE_IS_ENORMOUS
    case 5:
        InsertFive(array);
        return;
#endif
  default:
   for (partition = 1; partition < count; partition++) {
            beg = ipg = 0;
            end = partition - 1;
             while (end >= beg) {
                ipg = ((end + beg) >> 1);
                if (GT(array[ipg], array[partition]))
                    end = ipg - 1;
                else
                    beg = ++ipg; }
            if (partition != (unsigned long) ipg) {
                temp = array[partition];
                memmove(&array[ipg + 1], &array[ipg], (partition - ipg) * sizeof(int));
                array[ipg] = temp;      }  }  }
    return;
}

void Do(int *arr, int n)
{
	size_t i = 1;
	while (i < n) {
		if (i == 0) {
			i = 1; }
		if (arr[i-1] <= arr[i]) {
			++i;
		} else {
			long tmp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = tmp;
			--i; }  }
}

int main(int argc, char *argv[])
{   setlocale (LC_ALL, "RUS");
int c;
printf("Выберите метод сортировки\n1) Сортировка слиянием  \n2) Быстрая сортировка \n3) Двоичные вставки  \n4) Гномья сортировка\n");
scanf ("%d", &c);
switch (c) {
case 1: {
    int *ar=NULL;
    int *br=NULL;
    int size,a,b,j,N;
        printf("Введите количество элементов массива N:", N);
        scanf ("%d", &size);
           a = -5; b = 5; j = 0;
           ar=new int[size];
           br=new int[size];
           makear(ar,a,b,size);
           printf("Последние 10 элементов\n");
           printar(ar,size-10,size);
           clock_t start = clock();
           msort(ar,br,0,size);
           clock_t end = clock();
           double seconds = (double)(end - start) / CLOCKS_PER_SEC;
           getchar();
           printf("Последние 10 элементов после сортировки\n");
           printar(ar,size-10,size);
           printf("The time: %f seconds\n", seconds);
           delete []ar; delete []br;
           getchar();
           return (0); } break;

case 2:
   {  int *ar=NULL;
      int i,size,a,b,N;
      printf("Введите количество элементов массива N:", N);
        scanf ("%d", &size);
            a = 0; b = 8;
               ar=new int[size];
                  makear(ar,a,b,size);
               printf("Последние 10 элементов\n");
                  printar(ar,size- 10,size);
                  clock_t start = clock();
               QSORTB(ar,0,size);
               clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
     getchar();
               printf("Последние 10 элементов после сортировки\n");
                  printar(ar,size-10,size);
                   printf("The time: %f seconds\n", seconds);
            return (0); } break;

case 3: {
        int *ar=NULL;
        int i,size,a,b,N;
        printf("Введите количество элементов массива N:", N);
        scanf ("%d", &size);
               a = 0; b = 8;
               ar=new int[size];
                  makear(ar,a,b,size);
               printf("Последние 10 элементов\n");
                  printar(ar,size-10,size);
                  clock_t start = clock();
               INSERTIONSORT(ar, size);
               clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
               printf("Последние 10 элементов после сортировки\n");
                  printar(ar,size-10,size);
                   printf("The time: %f seconds\n", seconds);
                  delete []ar;}
              break;

              case 4:
		{
			int *ar=NULL;
        	int i,size,a,b;
			a = 0; b = 8;
			printf ("Введите количество элементов: N=");
    		scanf ("%d",&size);
            ar=new int[size];
            makear(ar,a,b,size);
            printf("Последние 10 элементов\n");
            printar(ar,size-10,size);
            clock_t start = clock();
			Do(ar,size);
			clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
           	printf("Последние 10 элементов после сортировки\n");
            printar(ar,size-10,size);
            printf("The time: %f seconds\n", seconds);
            delete []ar;
		}
			break;
		}
              getchar();
    return (0);}
