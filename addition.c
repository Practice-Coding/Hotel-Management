void errorMessage(void)
{
     printf("Error in creating database. Contact your application programmer.");
     printf("Press \"Enter\" to exit...");
     getch();
     exit(0);
}
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
void prepStr(int num, char *filename)
{
     int rem, i = 0;
     char *str = (char *) malloc(7);
     strcpy(filename, "Data\\");
     strcat(filename, "r");
     while( num != 0 )
     {
            rem = num % 10;
            str[i++] = '0' + rem;
            num = num / 10;
     }
     str[i] = '\0';
     reverse(str);
     strcat(filename, str);
     strcat(filename, ".dat");
}
void addRoom( int num )
{
     FILE *fp;
     char *filename = (char *) malloc(20);
     int rooms, i = 1;
     
     if( num )
     {
         printf("Please enter the total number of rooms to be added: ");
         scanf("%d", &rooms);
         printf("\nPlease wait while database is being modified...");
         while( fp != NULL )
         {
                if( i != 1 )
                    fclose(fp);
                prepStr(i, filename);
                fp = fopen(filename, "rb");
                i++;
         }
         i--;
         rooms += (i-1);
     }
     else
     {
         printf("Please enter the total number of rooms in your hotel: ");
         scanf("%d", &rooms);
         printf("\nPlease wait while database is being created...");
     }
     for(; i <= rooms; i++ )
     {
          prepStr(i, filename);
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
}
