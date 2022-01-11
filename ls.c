#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

/* Pour aider à comprendre, voici la composition d'une structure dirent :
struct dirent {
    ino_t          d_ino;       --> inode number 
    off_t          d_off;       --> offset to the next dirent 
    unsigned short d_reclen;    --> length of this record 
    unsigned char  d_type;      --> type of file; not supported by all file system types 
    char           d_name[256]; --> filename 
    }; */


void ls_function(int argc,char *argv[]){
   DIR *dir;            // le receptacle temporaire du fichier
   struct dirent *dent;
   char temp[UCHAR_MAX];
   if(argv[1]!=NULL || argv[1][0]!="-"){
    dir = opendir(argv[1]);   // A changer si l'on veut rajouter les options car va prendre le 2e argument direct pour nom de rep
   }
   else{
    if (getcwd (temp, UCHAR_MAX) == NULL) {
        perror("failed to get current directory\n"); 
     }
       else{
          dir = opendir(temp);
   }
   }
   
   if(dir!=NULL){
      while((dent=readdir(dir))!=NULL){ //readdir renvoie donc un pointeur vers une structure dirent, donc un tableau de tous les éléments du ré
          if((strcmp(dent->d_name,".")==0 || strcmp(dent->d_name,"..")==0 || (*dent->d_name) == '.' )){   // le rep courant, rep père et fichiers cachés sont ignorés. 
                }
            else
                {
        printf(dent->d_name);
        printf("\n");
              }
                    }
       }
       close(dir);
     }
    
}
