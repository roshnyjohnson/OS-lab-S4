#include<stdio.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                allocation.c *                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #include<stdio.h>
#include<stdlib.h>


void firstfit(int n,int m,int blksize[],int prosize[])
{
    int i,j,allocation[20];
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blksize[j]>=prosize[i])
            {
                allocation[i]=j;
                blksize[j]-=prosize[i];
                break;
            }
        }

    }
    printf("process no\tprocess size\tblock no\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",prosize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
            printf("\n");

        }
        else{
            printf("not allocated");
        }

    }

}

void bestfit(int n,int m,int blksize[],int prosize[])
{
    int i,j,allocation[20],best;
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;

    }
    for(i=0;i<n;i++)

    {
        best=-1;
        for(j=0;j<m;j++)
        {
            if(blksize[j]>=prosize[i])
            {
                if(best==-1)
                {
                    best=j;
                }
                else if (blksize[best]>blksize[j])
                {
                    best=j;
                }
                if(best!=-1)
                {

                     allocation[i]=best;
                     blksize[best]-=prosize[i];
                }
            }
        }

    }
    printf("process no\tprocess size\tblock no\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",prosize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
            printf("\n");

        }
        else{
            printf("not allocated");
        }

    }

}

void worstfit(int n,int m,int blksize[],int prosize[])
{
    int i,j,allocation[20],worst;
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;

    }
    for(i=0;i<n;i++)

    {
        worst=-1;
        for(j=0;j<m;j++)
        {
            if(blksize[j]>=prosize[i])
            {
                if(worst==-1)
                {
                    worst=j;
                }
                else if (blksize[worst]<blksize[j])
                {
                    worst=j;
                }
                if(worst!=-1)
                {

                     allocation[i]=worst;
                     blksize[worst]-=prosize[i];
                }
            }
        }

    }
    printf("process no\tprocess size\tblock no\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",prosize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
            printf("\n");

        }
        else{
            printf("not allocated");
        }

    }

}
int main()
{
    int i,j,n,m,prosize[20],blksize[20],s;
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter the no of blocks");
    scanf("%d",&m);
    printf("enter the processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&prosize[i]);
    }
    printf("enter the block sizes\n");
    for(j=0;j<m;j++)
    {
        scanf("%d",&blksize[j]);

    }
    while(1){
    printf("which do you want?\n1.first fit\n2.bestfit\n3.worstfit\n4.exit");
    scanf("%d",&s);
    switch(s)
    {
        case 1:
        firstfit(n,m,blksize,prosize);
        break;

        case 2:
        bestfit(n,m,blksize,prosize);
        break;

        case 3:
        worstfit(n,m,blksize,prosize);
        break;

        case 4:
        exit(0);

    }}


}

