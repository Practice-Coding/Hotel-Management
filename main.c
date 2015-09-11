#include<stdio.h>
#include<conio.h>

// function files being included
/*#include "booking.c"
#include "cancel.c"
#include "status.c"
#include "addition.c"*/


/*void bookRoom(void);
void canBook(void);
void status(void);
void addRoom(void);*/
int main()
{
  int choice;
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
