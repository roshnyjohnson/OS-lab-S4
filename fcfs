#include<stdio.h>
struct process{
    int at;
    int ct;
    int bt;
    int id;
    int wt;
    int rt;
    int tt;

}p[10];
void fcfs(int n,struct process p[])
{
    int i,j;
    int tot_tt,tot_ct,tot_wt;
    tot_tt=tot_wt=tot_ct=0;
    struct process temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    p[0].ct=p[0].bt;
    p[0].tt=p[0].ct-p[0].at;
    p[0].wt=p[0].tt-p[0].bt;
    tot_ct +=p[0].ct;
    tot_tt +=p[0].tt;
    tot_wt +=p[0].wt;

    for(i=1;i<n;i++)
    {
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        tot_ct +=p[i].ct;
        tot_tt +=p[i].tt;
        tot_wt +=p[i].wt;

    }
    printf("gnatt chart\n");
    printf("0");
    for(i=0;i<n;i++)
   
    {
        
        printf("|%d|%d",p[i].id,p[i].ct);
        
    }
    printf("\n");
    printf("the average completion time is %d\n",(float)tot_ct/n);
    printf("the average tt ime is %d\n",(float)tot_tt/n);
    printf("the average waiting time is %d\n",(float)tot_wt/n);





}
int main()
{
    int n,i,j,tot_wt,tot_tt,tot_ct;
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter the process id,arrival time, burst time in order \n");
    for(i=0;i<n;i++)
    {
        printf("enter the pid for %d",i+1);
        scanf("%d",&p[i].id);
        printf("enter the at for %d",i+1);
        scanf("%d",&p[i].at);
        printf("enter the bt for %d",i+1);
        scanf("%d",&p[i].bt);

    }
    tot_tt=tot_wt=tot_ct=0;
    fcfs(n,p);
}
