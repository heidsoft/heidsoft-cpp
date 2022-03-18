#include<stdio.h> 
int counterFunction() 
{ 
  //static int count = 0;
  int count = 0; 
  count++; 
  return count; 
} 

int main() 
{   
    int index = 0;
    printf("First Counter Output = %d\n", counterFunction()); 
    printf("Second Counter Output = %d\n", counterFunction()); 
    while(1) {
        index++;
        printf("%d Counter Output = %d \n",index, counterFunction()); 
        if (index > 100){
            break;
        }
    }
  return 0; 
}