#include<stdio.h>
float tot_rt,tot_wt,tot_ct,tot_tt;
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tt;
    int rt;
    int started;
    int remaining_bt;

}p[20],s[20],temp;
void roundrobin(int n,struct process s[],int tq)
{
    int index,i,j;
    tot_rt=tot_wt=tot_ct=tot_tt=0;
    int queue[100],rear=0,front=0;
    int completed=0,currenttime=0;
    for(i=0;i<n;i++)
    {
        s[i].rt=-1;
        s[i].started=0;
        s[i].remaining_bt=s[i].bt;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(s[j].at>s[j+1].at)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    queue[rear++]=0;
    s[0].started=1;
    //index=queue[front++];
    while(completed!=n)
    {    index=queue[front++];
        if(s[index].rt==-1)
        {
            s[index].rt=currenttime-s[index].at;
        }
      //  index=queue[front++];
        if(s[index].remaining_bt>tq)
        {
            s[index].remaining_bt-=tq;
            currenttime+=tq;
           // s[index].ct=currenttime;
        }
        else{
            currenttime+=s[index].remaining_bt;
            s[index].remaining_bt=0;
            s[index].ct=currenttime;
            s[index].tt=s[index].ct-s[index].at;
            s[index].wt=s[index].tt-s[index].bt;
            tot_ct+=s[index].ct;
            tot_tt+=s[index].tt;
            tot_wt+=s[index].wt;
            tot_rt+=s[index].rt;
            completed++;

        }
        printf("|P%d|%d",s[index].id,currenttime);
         for(i=0;i<n;i++){
        if(s[i].started==0&&s[i].at<=currenttime)
        {
            queue[rear++]=i;
            s[i].started=1;
        }}
        if(s[index].remaining_bt>0)
        {
            queue[rear++]=index;
        }
    }
    printf("\nprocess id\tarrival time\tburst time\tcompletion time\twaiting time\tturnaround time\tresponse time");
    for(i=0;i<n;i++){

    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",s[i].id,s[i].at,s[i].bt,s[i].ct,s[i].wt,s[i].tt,s[i].rt);}
    printf("\navg ct time %.2f",tot_ct/n);
    printf("\navg wt time %.2f",tot_wt/n);
    printf("\navg tt time %.2f",tot_tt/n);
    printf("\navg rt time %.2f",tot_rt/n);


}

int main()
{
    int i,n,tq;
    printf("Enter the no. of processes : ");
    scanf("%d", &n);
    printf("enter the time quantam");
    scanf("%d",&tq);
    struct process s[20];
    for (i = 0; i < n; i++) {
        printf("\n enter process id \n");
       scanf("%d",&p[i].id);
        printf("Enter the arrival time : ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time : ");
        scanf("%d", &p[i].bt);
       }
       for(i=0;i<n;i++)
       {
        s[i]=p[i];
       }
       roundrobin(n,s,tq);
       return 0;
}





