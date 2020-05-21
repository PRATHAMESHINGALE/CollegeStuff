#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void quicksort(int number[2000],int first,int last){
   int i, j, pivot, temp;

if(first<last)
{
      pivot=first;
      i=first;
      j=last;

while(i<j)
{
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];

            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
#pragma omp parallel sections
      {
	#pragma omp section
      quicksort(number,first,j-1);
	#pragma omp section
      quicksort(number,j+1,last);
}
      
   }
}

int main(){
   int i, number[2000];

   for(i=0;i<999;i++){
      number[i]=rand();
}
   quicksort(number,0,999);

   printf("Order of Sorted elements: ");
   for(i=0;i<999;i++)
      printf(" %d",number[i]);

   return 0;
}
