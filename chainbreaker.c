#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <vector>
#include <cstring>

using namespace std;
void encrypt(char input[])
{
    char fname[20], ch;
	FILE *fpts, *fptt;
	
	printf("\n\n Encrypt a text file :\n");
	printf("--------------------------\n"); 	
	// printf(" Input the name of file to encrypt : ");
	// scanf("%s",fname);	

	fpts=fopen(input, "r");
	if(fpts==NULL)
	{
		cout << input << "this didnt work 1\n";
	}
	fptt=fopen("temp.txt", "w");
	if(fptt==NULL)
	{
		cout << input << "this didnt work 2\n";
		fclose(fpts);
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
		cout << input << "this didnt work 3\n";
	}
	fptt=fopen("temp.txt", "r");
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
	printf(" File %s successfully encrypted ..!!\n\n", input);
	fclose(fpts);
	fclose(fptt);
}

int main(void) {
   DIR *dr;
   struct dirent *en;
   string temp;
   dr = opendir("."); //open all file
   if (dr) {
      while ((en = readdir(dr)) != NULL) {
        encrypt(en->d_name); //print all file name
      }
      closedir(dr); //close all directory
   }
   return(0);
}
//https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-13.php
//https://www.tutorialspoint.com/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-cplusplus
