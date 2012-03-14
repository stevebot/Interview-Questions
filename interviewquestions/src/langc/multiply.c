#include <stdio.h>
#include <math.h>
/*
Write an algorithm/code in C to do integer multiplication  without using multiplication nor division operators. 
 */
void main()
{
  int n;
  int m;
  int result;
  printf("Please enter numbers to multiplye\n");  
  printf("First number\n");  
  int multiple1 = getNumberFromUser();
  printf("\nSecond number\n");
  int multiple2 = getNumberFromUser();
  result = doMultiplication(multiple1,multiple2);
  printf("Result of multiplication = %d\n", result);
}

int getNumberFromUser()
{
  char arg1[10]; 
  int retry = 0;
  int multiple;
  while(retry == 0)
  { 
    printf("Please enter a number:");
    scanf("%s", arg1);
    if(isNumericInput(arg1) != 0)
    {
      char * strEnd;
      multiple = strtol(arg1,&strEnd, 10);
      retry = 1;
    } else {
      printf("Bzzz wrong answer genius try a number \n");
    }
  }

  return multiple;

}

int isNumericInput(char arg[]){
  char * strEnd;
  int userInput = strtol(arg, &strEnd, 10);
  return userInput;
}

int doMultiplication(int n, int m)
{
  int result = 0;
  while(m != 0)
  {
    if((m & 1) != 0)
    {
      result = result + n;
    }
    n = n << 1;
    m = m >> 1;
  }
  return result;
}
