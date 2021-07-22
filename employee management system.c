#include<stdio.h>
struct employeedetails
{
 int sno;
 char name[40], department[50];
 int age,salary,joiningyear;
}details;
//    FUNCTION TO ADD DETAILS TO THE FILE
void add()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Sequence no : ");
 scanf("%d", &details.sno);
 
 printf("Enter the Name : ");
 scanf("%s", &details.name);
 
  printf("Enter the age : ");
 scanf("%d", &details.age);
 
 printf("Enter the department : ");
 scanf("%s", &details.department);
 
 printf("Enter the salary : ");
 scanf("%d", &details.salary);
 
 printf("Enter the year of joining : ");
 scanf("%d", &details.joiningyear);
 
 fwrite(&details, sizeof(details), 1, fp);
 fclose(fp);
}
//    FUNCTION TO SHOW DETAILS
void show()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nS.No\tName\tage\tdepartment\tsalary\tyear of joining\n\n");
 while (fread(&details, sizeof(details), 1, fp1))
 printf("  %d\t%s\t%d\t%s\t%d\t%d\n", details.sno, details.name, details.age, details.department, details.salary, details.joiningyear);
 fclose(fp1);
}

//    FUNCTION TO DELETE DETAILS


void delete()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Sequence no you want to delete : ");
 scanf("%d", &r);
 if (avlsno(r) == 0)
  printf("Sequence no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&details, sizeof(details), 1, fpo))
  {
   s = details.sno;
   if (s != r)
    fwrite(&details, sizeof(details), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&details, sizeof(details), 1, fpt))
   fwrite(&details, sizeof(details), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO EDIT DETAILS
void edit()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter sequence number to update : ");
 scanf("%d", &r);
 avl = avlsno(r);
 if (avl == 0)
 {
  printf("sequence number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&details, sizeof(details), 1, fpo))
  {
   s = details.sno;
   if (s != r)
    fwrite(&details, sizeof(details), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of sequence Number %d", r);
     printf("\n\t2. Update department of sequence Number %d", r);
    printf("\n\t3. Update age of sequence Number %d", r);
     printf("\n\t4. Update salary of sequence Number %d", r);
      printf("\n\t5. Update year of joining of sequence Number %d", r);
    printf("\n\t6. Update all Name department age salary and date of joining of sequence Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name: ");
     scanf("%s", &details.name);
     break;
   
     case 2:
     printf("Enter age: ");
     scanf("%d", &details.age);
     break;
     
      case 3:
     printf("Enter department: ");
     scanf("%s", &details.department);
     break;
     
     case 4:
     printf("Enter salary: ");
     scanf("%d", &details.salary);
     break;
     
     case 5:
     printf("Enter year of joining: ");
     scanf("%d", &details.joiningyear);
     break;
     
    case 6:
     printf("Enter Name: ");
     scanf("%s", &details.name);
      printf("Enter age: ");
     scanf("%d", &details.age);
     printf("Enter department: ");
     scanf("%s", &details.department);
      printf("Enter salary: ");
     scanf("%d", &details.salary);
      printf("Enter year of joining: ");
     scanf("%d", &details.joiningyear);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&details, sizeof(details), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&details, sizeof(details), 1, fpt))
  {
   fwrite(&details, sizeof(details), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

//    FUNCTION TO CHECK GIVEN SEQUENCE NO IS AVAILABLE //
int avlsno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&details, sizeof(details), 1, fp);

  if (rno == details.sno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&details, sizeof(details), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
void main()
{
 int c, emp;
 printf("\n\t--------------------EMPLOYEE MANAGEMENT SYSTEM--------------------\n\t");
 do
 {
  printf("\n\t-----Select your choice-----\n");
  printf("\n\t1. ADD DETAILS\n\t2. SHOW DETAILS\n\t");
  printf("3. DELETE DETAILS\n\t4. EDIT DETAILS\n");
  printf("\t5. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice: ");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   add();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    show();
   break;
  case 3:
   delete();
   break;
  case 4:
   edit();
   break;
  
  case 5:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 5);
}
