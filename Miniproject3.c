// C program to print the month by month
// calendar for the given year
#include<string.h>  
#include<stdio.h>
#include<stdlib.h>
#define BUF_SIZE 20

char* one[] = { "", "One ", "Two ", "Three ", "Four ",
                "Five ", "Six ", "Seven ", "Eight ",
                "Nine ", "Ten ", "Eleven ", "Twelve ",
                "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ",
                "Nineteen "
              };
// strings at index 0 and 1 are not used, they is to
// make array indexing simple
char* ten[] = { "", "", "Twenty ", "Thirty ", "Forty ",
                "Fifty ", "Sixty ", "Seventy ", "Eighty ",
                "Ninety "
              };
 
 char * numToWords(int n, char* s, char *str, int len)
{
    memset(str,0,len);
    // if n is more than 19, divide it
    if (n > 19)
    {
        strcat(str,ten[n / 10]);
        strcat(str,one[n % 10]);
    }
    else
    {
        strcat(str,one[n]);
    }
    // if n is non-zero
    if (n)
    {
        strcat(str,s);
    }
    return str;
}
// Function to print a given number in words
char* convertToWords(long n, char *out)
{
    char str[BUF_SIZE] = {0};
    // handles digits at thousands and tens thousands
    // places (if any)
    strcat(out, numToWords(((n / 1000) % 100), "Thousand ",str,BUF_SIZE));
    // handles digit at hundreds places (if any)
    strcat(out, numToWords(((n / 100) % 10), "Hundred ",str,BUF_SIZE));
    //Increase code readability
    if (n > 100 && n % 100)
    {
        strcat(out, "And ");
    }
    // handles digits at ones and tens places (if any)
    strcat(out, numToWords((n % 100), "",str,BUF_SIZE));
    return out;
}
// Function that returns the index of the
// day for date DD/MM/YYYY
int dayNumber(int day, int month, int year)
{
  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
  
// Function that returns the name of the
// month for the given month Number
// January - 0, February - 1 and so on
char* getMonthName(int monthNumber)
{
    char* month;
  
    switch (monthNumber) 
    {
    case 0:month = "January";
            break;
    case 1:month = "February";
            break;
    case 2:month = "March";
            break;
    case 3:month = "April";
            break;
    case 4:month = "May";
            break;
    case 5:month = "June";
            break;
    case 6:month = "July";
        break;
    case 7:month = "August";
            break;
    case 8:month = "September";
            break;
    case 9:month = "October";
            break;
    case 10:month = "November";
            break;
    case 11:month = "December";
            break;
    }
    return month;
}
  
// Function to return the number of days
// in a month
int numberOfDays(int monthNumber, int year)
{
    // January
    if (monthNumber == 0)
        return (31);
  
    // February
    if (monthNumber == 1) 
    {
        // If the year is leap then Feb
        // has 29 days
        if (year % 400 == 0|| (year % 4 == 0&& year % 100 != 0))
            return (29);
        else
            return (28);
    }
  
    // March
    if (monthNumber == 2)
        return (31);
  
    // April
    if (monthNumber == 3)
        return (30);
  
    // May
    if (monthNumber == 4)
        return (31);
  
    // June
    if (monthNumber == 5)
        return (30);
  
    // July
    if (monthNumber == 6)
        return (31);
  
    // August
    if (monthNumber == 7)
        return (31);
  
    // September
    if (monthNumber == 8)
        return (30);
  
    // October
    if (monthNumber == 9)
        return (31);
  
    // November
    if (monthNumber == 10)
        return (30);
  
    // December
    if (monthNumber == 11)
        return (31);
}
  
// Function to print the calendar of
// the given year
void printCalendar(int year)
{
    printf("     Calendar - %d\n\n", year);
    int days;
  
    // Index of the day from 0 to 6
    int current = dayNumber(1, 1, year);
  
    // i for Iterate through months
    // j for Iterate through days
    // of the month - i
    for (int i = 0; i < 12; i++) 
    {
        days = numberOfDays(i, year);
  
        // Print the current month name
        printf("\n ------------%s-------------\n",
               getMonthName(i));
  
        // Print the columns
        printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");
  
        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");
  
        for (int j = 1; j <= days; j++) 
        {
            printf("%5d", j);
  
            if (++k > 6) 
            {
                k = 0;
                printf("\n");
            }
        }
  
        if (k)
            printf("\n");
  
        current = k;
    }
  
    return;
}
//Day of the week
void datey() 
{ 
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    char week[7][10], mast[13][10]; 
    int date, mon, i, r, s = 0 ; 
    long year;
    char str[60] = {0};
  //day cpy
    strcpy(week[0], "Sunday") ; 
    strcpy(week[1], "Monday") ; 
    strcpy(week[2], "Tuesday") ; 
    strcpy(week[3], "Wednesday") ; 
    strcpy(week[4], "Thursday") ; 
    strcpy(week[5], "Friday") ; 
    strcpy(week[6], "Saturday") ; 
    printf("Enter a valid date (dd/mm/yyyy) : ") ; 
    scanf("%d / %d / %ld", &date, &mon, &year) ; 
    if((date>31)||(mon>12)||(year>9999))
    {
        printf("\nEnter the dates correctly!!!!\n");
        return;
    }
    if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) ) 
        month[1] = 29 ; 
    for(i = 0 ; i < mon - 1 ; i++)
    
        s = s + month[i] ; 
        s = s + (date + year + (year / 4) - 2) ; 
        s = s % 7 ; 
    
    //month cpy
    strcpy(mast[1],"January");
    strcpy(mast[2],"February");
    strcpy(mast[3],"March");
    strcpy(mast[4],"April");
    strcpy(mast[5],"May");
    strcpy(mast[6],"June");
    strcpy(mast[7],"July");
    strcpy(mast[8],"August");
    strcpy(mast[9],"September");
    strcpy(mast[10],"October");
    strcpy(mast[11],"November");
    strcpy(mast[12],"December");
    printf("\nThe day is : %s\n The Month is: %s\n", week[s],mast[mon]) ; 
    printf("And the year is: %s\n",convertToWords(year,str));
 }
 
void leapu() 
{
   int year;
   printf("\nEnter a year: ");
   scanf("%d", &year);
   if(year>=9999||year<=0)
   {
       printf("\n Enter the years within four digits, positive integer number\n");
       return;
   }

   // leap year if perfectly divisible by 400
   if (year % 400 == 0) 
   {
      printf("\n%d is a leap year.\n", year);
   }
   // not a leap year if divisible by 100
   // but not divisible by 400
   else if (year % 100 == 0) 
   {
      printf("\n%d is not a leap year.\n", year);
   }
   // leap year if not divisible by 100
   // but divisible by 4
   else if (year % 4 == 0) 
   {
      printf("\n%d is a leap year.\n", year);
   }
   // all other years are not leap years
   else 
   {
      printf("\n%d is not a leap year.\n", year);
   }

   return;
}

// Driver Code
int main()
{
    int year,ch;
    while(1)
    {
        printf("\n MENU \n");
        printf("\n 1.See the calendar for a particular year");
        printf("\n 2.View your day in which you were born");
        printf("\n 3.To check if it is leap year or not");
        printf("\n 4.Exit");
        printf("\n Enter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Enter the year:\t");
                scanf("%d",&year);
                printCalendar(year);
                break;
            case 2:datey();
                break;
            case 3:leapu();
                break;
            case 4:exit(0);
            default:printf("\n Enter the appropriate number!!!");
        }
    }
    // Function Call
}






