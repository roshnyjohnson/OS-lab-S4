#include<stdio.h>
#include<stdlib.h>
int p,n,i,j,f,pages[30],recent[30],time[30],freq[30],frames[30];
void printframes()
{
        for(j=0;j<f;j++)
        {
                if(frames[j]==-1)
                {
                        printf("|-|");
                }
                else{
                printf("|%d|",frames[j]);}
        }
        printf("\n");
}
void fifo()
{
        int k=0;
        int fault=0;
        for(i=0;i<f;i++)
        {
                frames[i]=-1;

        }
        for(i=0;i<n;i++)
        {
                p=pages[i];
                int flag=0;
                for(j=0;j<f;j++)
                {
                        if(p==frames[j])
                        {
                        flag=1;
                        break;
                        }
                }
                if(!flag)
                {
                        fault++;
                        frames[k]=p;
                        k=(k+1)%f;
                }
                printframes();
        }
        printf("the number of faults is %d ",fault);
        printf("the number of hit is %d",n-fault);
}

void lru()
{
        int i,j;
        int k=0;
        int fault=0;
        for(i=0;i<f;i++)
        {
                frames[i]=-1;
                recent[i]=-1;

        }
        for(i=0;i<n;i++)
        {
                p=pages[i];
                int flag=0;
                for(j=0;j<f;j++)
                {
                        if(p==frames[j])
                        {
                        flag=1;
                        recent[j]=k;
                        k++;
                        break;
                        }
                }
                if(!flag)
                {
                        int minimum=0;
                        for(j=1;j<f;j++){

                                if(recent[j]<recent[minimum])
                                {
                                        minimum=j;
                                }
                        }
                        fault++;
                        frames[minimum]=p;
                        recent[minimum]=k;
                        k++;
                }
                printframes();
        }
        printf("the number of faults is %d ",fault);
        printf("the number of hit is %d ",n-fault);
}


void lfu()
{
       // int i,j;
        int global_freq[100] = {0};
        int minFreq,minindex,earliesttime;
        int k=0;
        int fault=0;
        for(i=0;i<f;i++)
        {
                frames[i]=-1;
                time[i]=-1;
                freq[i]=0;

        }
        for(i=0;i<n;i++)
        {
                p=pages[i];
                int flag=0;
                for(j=0;j<f;j++)
                {
                        if(p==frames[j])
                        {
                        flag=1;
                        global_freq[p]++;

                        freq[j]=global_freq[p];
                        break;
                        }
                }
                if(!flag)
                {
                        int minFreq=freq[0];
                        earliesttime=time[0];
                        minindex=0;
                        for(j=0;j<f;j++){

                                if(freq[j]<minFreq)
                                {
                                        minFreq=freq[j];
                                        earliesttime=time[j];
                                        minindex=j;
                                }
                                else if(freq[j]==minFreq&&time[j]<earliesttime)
                                {
                                        //minFreq=freq[j];
                                        earliesttime=time[j];
                                        minindex=j;
                                }
                        }
                        fault++;
                        frames[minindex]=p;
                        global_freq[p]++;
                        freq[minindex]= global_freq[p];
                        time[minindex]=k;
                        k++;
                }
                printframes();
        }
        printf("the number of faults is %d ",fault);
        printf("the number of hit is %d ",n-fault);
}
int main()
{
    int ch;
    printf("enter the number of pages");
    scanf("%d",&n);
    printf("enter the number of frames");
    scanf("%d",&f);
    printf("enter the pages");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);

    }
    while(1)
    {
        printf("which do you want\n1.fifo\n2.lru\n3.lfu\n4.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            fifo();
            break;

            case 2:
            lru();
            break;

            case 3:
            lfu();
            break;

            case 4:
            exit(0);

            default:
            printf("INVALID CHOICE\n");


        }

    }


}





























