#include <stdio.h>
#include <string.h>

typedef struct {                            //Define struct student
  char type;
  char name[50];
  int age;
  double average;
} Student;

#define TOTAL_STUDENTS 3

int main(void){
  FILE *file;                               //File pointer variable

  file = fopen("file.csv", "w");            //Open file.csv in write mode

  if (file == NULL){
    printf("Error opening file\n");
    return 1;
  }

  Student students[TOTAL_STUDENTS];           //create array of structs
  students[0].type = 'U';
  strcpy(students[0].name, "Nageeb");
  students[0].age = 20;
  students[0].average = 90;
  
  students[1].type = 'U';
  strcpy(students[1].name, "Mary");
  students[1].age = 19;
  students[1].average = 95;
  
  students[2].type = 'G';
  strcpy(students[2].name, "Kulvinder");
  students[2].age = 21;
  students[2].average = 85;
 
  for (int i = 0; i < TOTAL_STUDENTS; i++){     //print array of structs to file.csv
    fprintf(file, 
            "%c, %s, %d, %.2f\n",
            students[i].type,  
            students[i].name,  
            students[i].age,  
            students[i].average
          );

    if(ferror(file)){
      printf("Error writing to file.\n");
      return 1;
    }
  }
  fclose(file);

  printf("\n%d records written\n",
         TOTAL_STUDENTS);

  return 0;
}