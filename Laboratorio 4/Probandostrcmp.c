#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[30] = "Andrea Coloma Espinosa";
	char str2[30] = "Andrea Coloma Espinoza";
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