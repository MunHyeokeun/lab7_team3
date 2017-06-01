#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	pid_t pid;
	char buffer[1000], buf[1000];
        FILE *ffile = fopen("list", "rt");
        if(ffile!=NULL){              
                while(NULL!=(fgets(buffer, 1000, ffile))){
			buffer[strlen(buffer)-1] = '\0';
			if(fork()==0){
				execl("/bin/gzip", "gzip", "-d", buffer, NULL);
				exit(0);
			}
		}
	}
	printf("Done\n");
	exit(0);
}
