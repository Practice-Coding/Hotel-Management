#include<stdio.h>
#include<conio.h>

typedef struct
{
  int rollno;
  int marks;
} Data; // naya data type bnane ka. Data naam ka.


void main()
{
  // variable declaration
  FILE *fp;
  Data sarr;
  
  // file mein data save krne ka bhidu
  fp = fopen("Data.bin", "wb");
  scanf("%d", &sarr.rollno);
  scanf("%d", &sarr.marks);
  fwrite(&sarr, 1, sizeof(sarr), fp);
  fclose(fp); // file close krne kaa baap
  
  // file mein se data read krne ka bhailog aur use output console se chipkane ka
  fp = fopen("Data.bin", "rb");
  fread(&sarr, 1, sizeof(sarr), fp);
  printf("The data saved in the file is:\n");
  printf("Roll No.: %d\n", sarr.rollno);
  printf("Marks: %d", sarr.marks);
  fclose(fp); // file close krne ka
  
  getch();
}
