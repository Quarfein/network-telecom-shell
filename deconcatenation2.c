#include <stdio.h>
#include <string.h>
void deconca( char* Dc[]){
  int i,j,k;
  char d[]=" ";
  int len = strlen(Dc);
  k=0;
  for (i=0;i<strln(Dc);i++) // nombre de parametres
  {
    if (Dc[i]=' ')
      {
        k++
      } 
   }
  str=(char*)malloc(size of(char)*k); // tableau des parametres
  // extraire les parametres
  for (i=0;i<len);i++) 
  {
    char *p = strtok(Dc, d);
    while(p != NULL)
    {
     str[i]=p;
     p = strtok(NULL, d);
    }
  }
int main(){
  deconca(Dc[])
  return(0);
}
