//chat_server.c
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
#include<unistd.h>
#define NAME "ROSHU"
typedef struct{
        int datastatus;
        int exitstatus;
        char message[128];
}shared_area;

int main()
{
        int fd;
        char message[128];
        shared_area*sharedBuffer;
        fd=shm_open(NAME,O_CREAT|O_RDWR,0666);
        ftruncate(fd,sizeof(shared_area));
        sharedBuffer=(shared_area*)mmap(0,sizeof(shared_area),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

         sharedBuffer->datastatus=0;
        sharedBuffer->exitstatus=0;
        while(1){
          if(sharedBuffer->exitstatus==1)
        {
                exit(1);
        }
        if(sharedBuffer->datastatus==0){
          if(strcmp(sharedBuffer->message,"STOP")==0)
        {
                sharedBuffer->exitstatus=1;
                break;

        }
        /*if(sharedBuffer->exitstatus==1)
        {
                break;
        }*/
        //sharedBuffer->datastatus=0;
        //sharedBuffer->exitstatus=0;

        printf("user2 says :%s",sharedBuffer->message);
        printf("\nenter a message for user 2(enter STOP for exiting):\n");
        scanf("%s",message);

        strcpy(sharedBuffer->message,message);
        sharedBuffer->datastatus=1;
        if(strcmp(message,"STOP")==0)
        {
                sharedBuffer->exitstatus=1;
                break;

        }
        while(sharedBuffer->datastatus==1);


        }}

        close(fd);
        munmap(sharedBuffer,sizeof(shared_area));
        shm_unlink(NAME);

        return 0;
}



//chat_server2.c

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
#include<unistd.h>
#define NAME "ROSHU"

typedef struct{

        int datastatus;
        int exitstatus;
        char message[128];
}shared_area;
int main()
{
        int fd;
        char message[128];
        shared_area*sharedBuffer;
        fd=shm_open(NAME,O_RDWR,0666);
        //ftruncate(fd,sizeof(shared_area));
        sharedBuffer=(shared_area*)mmap(0,sizeof(shared_area),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

        //sharedBuffer->datastatus=1;
        //sharedBuffer->exitstatus=0;
        while(1)
        {


                        if(sharedBuffer->exitstatus==1)
                        {
                                exit(1);
                        }
                if(sharedBuffer->datastatus==1)
                {

                         if(strcmp(sharedBuffer->message,"STOP")==0)
                        {
                                sharedBuffer->exitstatus=1;
                                break;
                        }

                        if(sharedBuffer->exitstatus==1)
                        {
                                break;
                        }
                        printf("%s",sharedBuffer->message);
                        printf("\n enter  a message for user1(STOP for exiting): ");
                        scanf("%s",message);
                        strcpy(sharedBuffer->message,message);
                        sharedBuffer->datastatus=0;

                        if(strcmp(message,"STOP")==0)
                        {
                                sharedBuffer->exitstatus=1;
                                break;
                        }
                        while(sharedBuffer->datastatus==0);

                }
        }

        munmap(sharedBuffer,sizeof(shared_area));
        close(fd);

//shm_unlink(NAME);
}
