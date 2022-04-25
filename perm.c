#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define filemode1 (S_IRUSR |  S_IWUSR)
#define filemode2 (S_IROTH | S_IWOTH)

int main(int  argc, char* argv[]){

        if(argc!=2){
        printf("need to enter file name.");
        exit(-1);
        }
int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,filemode1);
char buf[]="Only Furkan Diyar Kokum can read and write this file";
write(fd,buf,sizeof(buf)-1);
close(fd);
fd=open(argv[1],O_WRONLY|O_APPEND);
fchmod(fd,filemode1|filemode2);
char buf2[]="The Other can read and write this file anymore";
write(fd,buf2,sizeof(buf2)-1);
close(fd);
return 0;
}
