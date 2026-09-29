
// read an array from user

#include <stdio.h>
#include <stdlib.h>

void sort() {
    int arr[5] ;
    printf("Enter an array of 5 elements: ");

    for(int i = 0 ; i < 5 ;i++)
    {
        scanf("%d", &arr[i]);
    }

    // print this array
    for(int i = 0; i < 5; i++) {
        printf("element %d is %d\n", i ,arr[i] );
    }
    printf("\n---------------------------\n");
    
    // sort these array
    for(int i = 0; i < 4; i++)
    {
        int num = 0;
        for(int j = i + 1; j < 5; j++)
        {
            if(arr[i] > arr[j]) {
                // swap
                num = arr[i];
                arr[i] = arr[j];
                arr[j] = num;
            }
        }
    }
    // print this array
    for(int i = 0; i < 5; i++) {
        printf("element %d is %d\n", i ,arr[i] );
    }   
}


int IsPrime2(int num){
      if (num <= 1)
        return 0;
    
    if(num == 2)
        return 1;

    int counter = num /2;

    while(counter > 1)
    {
        if (num % counter  == 0)
        {
            return 0;
        }
        counter --;
    }
    return 1;
}

int IsPrime3(int num){
   // by for loop and optimized
   for(int i = 2; i < (num / 2); i++)
   {
        if(num %i == 0)
            return 0;
   }
   return 1; 
}

int IsPrime1(int num) {
    // brute force
    if (num <= 1)
        return 0;
    
    if(num == 2)
        return 1;

    int counter = num -1 ;

    while(counter > 1)
    {
        if (num % counter  == 0)
        {
            return 0;
        }
        counter --;
    }
    return 1;
}


void prime_driver()
{
       for(int i = 0; i < 100; i++)
    {
        if(IsPrime3(i))
            printf("%d # ", i);
    }
    printf("\n");
}


typedef enum  {
    Saterday = 1, 
    Sunday , 
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday
}enDay;

void prob_day_of_week(){

    int dayNum;
    printf("Enter a day: ");
    scanf("%d", &dayNum);

    if(dayNum == Saterday)
    {
        printf("It's Saterday\n");
    }
    else if(dayNum == Sunday)
    {
        printf("It's Sunday\n");
    }
    else if(dayNum == Monday){
        printf("It's Monday\n");
    }
    else if(dayNum == Tuesday){
        printf("It's Thursday\n");
    }
    else if(dayNum == Wednesday){
        printf("It's Wednesday\n");
    }
    else if(dayNum == Thursday){
        printf("It's Monday\n");
    }
    else if(dayNum == Friday){
        printf("It's Friday\n");
    }
    else{
        printf("%s\n", "WrongDay");
    }
}

int main()
{
//  prime_driver();

/*
int numOfHours;
printf("Enter Number of Hours: ");
scanf("%d", &numOfHours); // assume that user enter valid num (int , greater than 1)

int numOfweeks;
int numOfdays;

if(numOfHours < 24*)
{
    printf("hours: %d\n", numOfHours);
}
else if(numOfHours < (24 * 7)) {
    numOfdays = numOfHours / 24;
    numOfHours = (numOfHours - numOfdays * 24 ); 
    printf("hours: %d\n", numOfHours);
    
}
*/

while(1)
{
    system("clear");
    prob_day_of_week();
    getchar();
    getchar();
}
    
    return 0;
}