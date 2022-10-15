/* Ryan Reddoch
   CS-1714-B1
   Exercise 5 */



// HEADERS //
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   

// CONSTANTS //
#define ERROR_TRAP_BUFFER 1024
#define MAX_YEAR 2022
#define MIN_YEAR 1475
#define AUTHOR_CHAR_LIMIT 32
#define CITY_CHAR_LIMIT 64
#define MAX_COUNTER 3



// buffer //
char buffer[ERROR_TRAP_BUFFER];

// global variables:

// Author Name //
char authorName[MAX_COUNTER][AUTHOR_CHAR_LIMIT];
//Publicatiuon Year
unsigned int pubYear[MAX_COUNTER];
// Publication City //
char pubCity[MAX_COUNTER][CITY_CHAR_LIMIT];

// String Check Function
int stringCheck(char str[ERROR_TRAP_BUFFER], size_t maxSize) 
{
    int strReturnSize = (int)(strlen(str)-maxSize);

    (strReturnSize <= 0) ? strReturnSize = 0 : printf("Input size is too big, you are %d over, please try again \n", strReturnSize);
    
    return strReturnSize;

}
 
int main() {


  // main boolean variable for do while loop //
  bool isGood;
  
  int idx=0;
  for(;idx <= MAX_COUNTER;idx++){


      do {

        isGood = false;
      //////////////// AURHOR LAST NAME ////////////
        
        printf("What is the author's last name? \n");
        scanf(" %[^\n]s", buffer);

       

      } while (stringCheck(buffer, AUTHOR_CHAR_LIMIT) > 0);

      strcpy(authorName[idx], buffer);
      memset(buffer, '\0', ERROR_TRAP_BUFFER);

      ///////////// PUBLICATION YEAR  //////////////////////
      do {
        isGood = false;

        printf("What is the publication year?\n");
        scanf("%u", &pubYear[idx]);
        getchar();

        if ((pubYear[idx] < MIN_YEAR) || (pubYear[idx] > MAX_YEAR)) {
          printf("Publication year must be between 1475 and 2022\n");
          isGood = true;
        }

      } while (isGood);
      /////////// PUBLICATION CITY //////////////////////
      do {
        isGood = false;

        printf("What is the publication city?\n");
        scanf(" %[^\n]s", buffer);

      

      } while ( stringCheck(buffer, CITY_CHAR_LIMIT) > 0);

      strcpy(pubCity[idx], buffer);
      memset(buffer, '\0', ERROR_TRAP_BUFFER);
    
    if (idx == MAX_COUNTER){

      break;
    }
      printf("Would you like to continue?\n Y/N\n");
      scanf("%s", buffer);
      getchar();
      char ans = toupper(buffer[0]);
      if (ans != 'Y'){
       break;
        }
        }
    
  int i=0;
        for(i=0; i <= idx; i++){
          printf("\nAuthor's Last Name: %s \nPublication Year: %u \nPublication City: %s\n",authorName[i],pubYear[i],pubCity[i]);
         
          }
 
  return 0;
}
