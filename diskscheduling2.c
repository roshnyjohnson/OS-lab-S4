#include<stdio.h>
#include<stdlib.h>
int n,i,j,initial,final,temp,r[30],finish[30];


void sstf()
{
        printf("\n");
        int index;
        int count=0;
        int current=initial;
        int phead=0;
        //int minimum=1000000;
        for(i=0;i<n;i++)
        {
                finish[i]=0;
        }
        while(count<n){
        int minimum=10000000;
        for(i=0;i<n;i++)
        {
                if(abs(current-r[i])<minimum&&finish[i]==0)
                {
                        minimum=abs(current-r[i]);
                        index=i;

                }
        }
        phead+=abs(current-r[index]);
        current=r[index];
        printf("%d->",r[index]);
        finish[index]=1;
        count++;
        }
        printf("\ntotal head movements is %d",phead);
}
void scan()
{
        printf("\nscan\n");
        int index,current;
        int phead=0;
        current=initial;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1;j++)
                {
                        if(r[j]>r[j+1])
                        {
                                temp=r[j];
                                r[j]=r[j+1];
                                r[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(r[i]>current)
                {
                        index=i;
                        //current=r[i]
                        break;
                }
        }
        //phead+=abs(current-r[index]);
        for(i=index;i<n;i++)
        {
                phead+=abs(current-r[i]);
                current=r[i];
                printf("%d->",r[i]);
        }
        phead+=abs(current-final);
         printf("%d->",final);
        current=final;
        for(i=(index-1);i>=0;i--)
        {
                //current=r[i];
                phead+=abs(current-r[i]);
                current=r[i];
                printf("%d->",r[i]);
        }
        printf("Total headmovements is %d",phead);
}

void cscan()
{
        printf("\ncscan\n");
        int index,current;
        int phead=0;
        current=initial;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1;j++)
                {
                        if(r[j]>r[j+1])
                        {
                                temp=r[j];
                                r[j]=r[j+1];
                                r[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(r[i]>current)
                {
                        index=i;
                        //current=r[i]
                        break;
                }
        }
        //phead+=abs(current-r[index]);
        for(i=index;i<n;i++)
        {
                phead+=abs(current-r[i]);
                current=r[i];
                //printf("\n");
                printf("%d->",r[i]);
        }
        phead+=abs(current-final);
         printf("%d->",final);
        current=final;
        phead+=abs(current-0);
        printf("%d->",0);
        current=0;
        for(i=0;i<index;i++)
        {
                //current=r[i];
                phead+=abs(current-r[i]);
                current=r[i];
                printf("%d->",r[i]);
        }
        printf("Total headmovements is %d",phead);
}


void fcfs()
{
        int current;
        int phead=0;
        current=initial;
        for(i=0;i<n;i++)
        {
                phead+=abs(current-r[i]);
                current=r[i];
                printf("%d->",r[i]);
        }
        printf("Total head movements is %d",phead);
}
int main()
{
        printf("enter the number of requests");
        scanf("%d",&n);
        printf("enter the initial head position");
        scanf("%d",&initial);
        printf("enter the final position");
        scanf("%d",&final);
        printf("enter the request");
        for(i=0;i<n;i++)
        {
                scanf("%d",&r[i]);
        }
        fcfs();
        scan();
        cscan();
        sstf();
        return 0;
}



