// xvsh shell
#include "types.h"
#include "fcntl.h"
#include "user.h"

//the function strncpy is referened from the file sting.c 
char * strncpy(char *s, const char *t, int n)
{         char *os;
	  os = s;
	  while(n-- > 0 && (*s++ = *t++) != 0);
	  while(n-- > 0) *s++ = 0;
          return os;
}

int show_prompt(char *buff, int size)
{
  printf(2, "xvsh> ");
  memset(buff, 0, size);
  gets(buff,size);
  return 1;
}

char * r[2];
char ** my_strtok(char * s, int size){
	int z=0;
	for(int i=0;i<size;i++){
		if (s[i] != ' ' && s[i] !='\n')	z++;
		else break;
	}
	char r1[z];
	char r2[size-z];
	for(int i=0;i<size;i++){
		if (s[i] == ' '){
	            strncpy(r1, s, i);
		    r1[i]=0;
		    strncpy(r2, s+i+1, size-z-1);
                    r2[size-z-2]=0;
	            break;
		}
		if(i == size-1){
	            strncpy(r1,s,i);	
	            r1[i]=0;
		    strncpy(r2,s+i+1,0);
		    r2[size-z-1]=0;
		}
	}
	r[0]=r1;
		int ind = 0;
                if(r1[0] == '.' && r1[1] == 0) ind++;
                if(r1[0] == '.' && r1[1] == '.' && r1[2] == 0) ind++;
                if(r1[0] == 'R' && r1[1] == 'E' && r1[2] == 'A' && r1[3] == 'D' && r1[4] == 'M' && r1[5] == 'E' && r1[6] == 0) ind++;
                if(r1[0] == 'l' && r1[1] == 's' && r1[2] == 0) ind++;
		if(r1[0] == 'l' && r1[1] == 'n' && r1[2] == 0) ind++;
		if(r1[0] == 'l' && r1[1] == 'n' && r1[2] == 0) ind++;
		if(r1[0] == 'r' && r1[1] == 'm' && r1[2] == 0) ind++;
                if(r1[0] == 's' && r1[1] == 'h' && r1[2] == 0) ind++;
                if(r1[0] == 'c' && r1[1] == 'a' && r1[2] == 't' && r1[3]== 0) ind++;
                if(r1[0] == 'e' && r1[1] == 'c' && r1[2] == 'h' && r1[3] == 'o' && r1[4] == 0) ind++;
                if(r1[0] == 'g' && r1[1] == 'r' && r1[2] == 'e' && r1[3] == 'p' && r1[4] == 0) ind++;
                if(r1[0] == 'i' && r1[1] == 'n' && r1[2] == 'i' && r1[3] == 't' && r1[4] == 0) ind++;
                if(r1[0] == 'k' && r1[1] == 'i' && r1[2] == 'l' && r1[3] == 'l' && r1[4] == 0) ind++;
                if(r1[0] == 'x' && r1[1] == 'v' && r1[2] == 's' && r1[3] == 'h' && r1[4] == 0) ind++;
                if(r1[0] == 'm' && r1[1] == 'k' && r1[2] == 'd' && r1[3] == 'i' && r1[4] == 'r' && r1[5] == 0) ind++;
                if(r1[0] == 'z' && r1[1] == 'o' && r1[2] == 'm' && r1[3] == 'b' && r1[4] == 'i' && r1[5] == 'e' && r1[6] == 0) ind++;
                if(r1[0] == 's' && r1[1] == 'h' && r1[2] == 'u' && r1[3] == 't' && r1[4] == 'd' && r1[5] == 'o' && r1[6] == 'w' && r1[7] == 'n' && r1[8] == 0) ind++;
                if(r1[0] == 'c' && r1[1] == 'o' && r1[2] == 'n' && r1[3] == 's' && r1[4] == 'o' && r1[5] == 'l' && r1[6] == 'e' && r1[7] == 0) ind++;
                if(r1[0] == 'f' && r1[1] == 'o' && r1[2] == 'r' && r1[3] == 'k' && r1[4] == 't' && r1[5] == 'e' && r1[6] == 's' && r1[7] == 't' && r1[8] == 0) ind++;
                if(r1[0] == 's' && r1[1] == 't' && r1[2] == 'r' && r1[3] == 'e' && r1[4] == 's' && r1[5] == 's' && r1[6] == 'f' && r1[7] == 's' && r1[8] == 0) ind++;
                if(r1[0] == 'u' && r1[1] == 's' && r1[2] == 'e' && r1[3] == 'r' && r1[4] == 't' && r1[5] == 'e' && r1[6] == 's' && r1[7] == 't' && r1[8] == 's' && r[9] == 0) ind++;
		if(ind != 1) printf(2,"Cannot run this command %s\n",r1);
	r[1]=r2;
	return r;
}
int num_zombies = 0;
int main(void){
  static char buff[100]; 
  while(1){
    show_prompt(buff, sizeof(buff)); 
    while(strlen(buff)==1) show_prompt(buff,sizeof(buff));
    if(buff[0] == 'e' && buff[1] == 'x' && buff[2] == 'i' && buff[3] == 't' && buff[4] == '\n'){
	   for(int i=0;i<=num_zombies+2;i++){ wait();num_zombies--;}
	   exit();
    }
    if(buff[strlen(buff)-2] == '&'){
    int p = fork(); num_zombies++; 
    if(p > 0) printf(2,"[pid %d] runs as a background process\n",p);
    if(p == 0){
            int size = strlen(buff);
	    char buff1[size-1];
	    strncpy(buff1,buff,size-1);
	    buff1[size-2] = '\n';

	    char ** token = my_strtok(buff1,size-1);
	    char *args[]={token[0],token[1]};
            exec(args[0],args);
	    exit();	 
	  }
   }
   else{
	int pid = fork(); num_zombies++; 
	if (pid > 0) sleep(8); // short sleep to always show the prompt first
        if(pid == 0){
	    int size = strlen(buff);
	    char ** token = my_strtok(buff,size);
	    char *args[]={token[0],token[1]};
            exec(args[0],args);
	    exit();
	} 
       wait();
   }
}
  exit();
}
