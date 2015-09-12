#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// function files being included
/*#include "booking.c"
#include "cancel.c"
#include "status.c"
#include "addition.c"*/


/*void bookRoom(void);
void canBook(void);
void status(void);
void addRoom(void);*/
void reverse(char *ptr)
{
     char temp;
     int i, j;
     for( i = 0, j = (strlen(ptr) - 1); i < j; i++, j-- )
     {
          temp = ptr[i];
          ptr[i] = ptr[j];
          ptr[j] = temp;          
     }
}
void errorMessage(void)
{
     printf("Error in creating database. Contact your application programmer.");
     printf("Press \"Enter\" to exit...");
     getch();
     exit(0);
}
int main()
{
  FILE *fp = fopen("Data\\dbinfo.bin", "rb");
  int choice, rooms, i, j, temp, rem;
  char *filename = (char *) malloc(11), *str = (char *) malloc(6);
  
  /* Creation of database folder */
  if( fp == NULL )
  {
      system("md Data");
      fp = fopen("Data\\dbinfo.bin", "wb");
      if( fp == NULL )
      {
          errorMessage();
      }
  }
  fclose(fp);
  
  /* Creation database of rooms */
  printf("Please enter the total number of rooms in you Hotel: ");
  scanf("%d", &rooms);
  printf("\nPlease wait while database is being created...");
  for( i = 1; i <= rooms; i++)
  {
       temp = i;
       j = 0;
       strcpy(filename, "Data\\");
       strcat(filename, "r");
       while( temp != 0 )
       {
              rem = temp % 10;
              str[j++] = '0' + rem;
              temp = temp / 10;
       }
       str[j] = '\0';
       reverse(str);
       strcat(filename, str);
       strcat(filename, ".dat");
       fp = fopen(filename, "wb");
       if( fp == NULL )
       {
           errorMessage();
       }
       fclose(fp);
  }
  printf("Done!\n");
  printf("Press \"Enter\" to continue...");
  getch();
  
  /* Menu presentation */
  while(1)
  {
   system("cls");
   printf("Enter a number and press \"Enter\"\n\n");
   printf("1. Book Room\n");
   printf("2. Cancel Booking\n");
   printf("3. Room Status\n");
   printf("4. Add new room\n");
   printf("5. Exit\n\n");
   printf("You choice: ");
   scanf("%d", &choice);
   switch(choice)
   {
     case 1 :
               system("cls");
              //bookRoom();
     break;
    
     case 2 : system("cls");
              //canBook();
     break;
    
     case 3 : system("cls");
              // status();
     break;
    
     case 4 : system("cls");
              //addRoom();
     break;
    
     case 5 : 
              system("cls");
              printf("\nTHANK YOU for using this application! :)");
              printf("\nPress \"Enter\" to exit...");
              getch();
              exit(0);
     break;
    
     default :
              system("cls");
              printf("Wrong choice! Press \"Enter\" to make a choice again...");
              getch();
   }
  }
  return 0;
}
