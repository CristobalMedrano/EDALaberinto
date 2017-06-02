#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{

	char str1[60] = "Aela mundo como estan todos, yo bien";
	char str2[60] = "Adios";
	int quienesMayor = strcmp(str1, str2);
	if(quienesMayor < 0)
   {
      printf("%s viene antes que %s", str1, str2);
   }
   else if(quienesMayor > 0) 
   {
      printf("%s viene antes que %s", str2, str1);
   }
   else 
   {
      printf("%s es igual que %s", str1, str2);
   }

	return 0;
}