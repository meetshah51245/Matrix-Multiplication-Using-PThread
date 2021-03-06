#include<stdio.h>
#include<stdlib.h>
#include <string.h>
 
//initializing globals 
double **Matrix = NULL;
int Matrix_Size = 0;

void GetNumbers(char fileName[])
{

  int j;
  int i;
  char *token;
  size_t len = 0;
  ssize_t read;
  char *line = NULL;
  int lineCount = 0;
  char lineStr[1000000];
  int numbersCount = 0;
  const char delim[2] = ",";
  FILE* fp = fopen(fileName, "rb");

  // Check for file pointer
  if(fp == NULL)
  {
    printf("\nError reading file");
    exit(-1);
  }
  
  while ((read = getline(&line, &len, fp)) != -1) 
  {
    sprintf(lineStr, "%s", line);
	
	numbersCount = 0;
	
    if(lineCount == 0)
    {
		// allocate the memory
		Matrix_Size = atoi(line);
		  
		Matrix = (double **)malloc(Matrix_Size * sizeof(double*));
		if (Matrix == NULL)
		{
			printf("mallloc failed");
			
			break;
		}
	  
		for(i = 0; i < Matrix_Size; i++)
		{
		  Matrix[i] = (double *)malloc(Matrix_Size * sizeof(double));
		  if (NULL == Matrix[i])
		  {
			printf("mallloc failed");
			
			break;
		  }
		}
	}
    else if(lineCount > Matrix_Size)
    {
      break;
    }
    else
    {
	  token =  strtok(lineStr, delim);
  
      while(token != NULL) 
      {
        sscanf(token, "%lf", &Matrix[lineCount - 1 ][numbersCount]);
        numbersCount++;
        token = strtok(NULL, delim);
      }
      
	 }
	
	// free the memory allocated by getline
	if (line != NULL)
	{
	  free(line);
	  line = NULL;
	}
	
    lineCount++;
  }

  //close fle pointer
  fclose(fp);

}