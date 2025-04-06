#include<stdio.h>
#include<stdlib.h>
void printframes(int frames[], int f) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}
void fifo(int n,int f,int pages[])
{   int frames[f],p,i,j,k;
    for(j=0;j<f;j++)
    {
        frames[j]=-1;
    }
    int fault=0;
    k=0;
    for(i=0;i<n;i++)
    {
        p=pages[i];
        int flag=0;
        for(j=0;j<f;j++)
        {
            if(frames[j]==p)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            fault++;
            frames[k]=p;
            k=(k+1)%f;
        }
        printframes(frames,f);


    }
    printf("the number of page faults is %d",fault);
    printf("no. of page miss is %d",n-fault);
}
void lru(int n,int f,int pages[])
{   int frames[f],recent[f],i,j,k,p;
    for(j=0;j<f;j++)
    {
        frames[j]=-1;
        recent[j]=-1;
    }
    int fault=0;
    k=0;
    for(i=0;i<n;i++)
    {
        p=pages[i];
        int flag=0;
        for(j=0;j<f;j++)
        {
            if(frames[j]==p)
            {
                flag=1;
                recent[j]=k;
                k++;
                break;
            }


        }
        if(flag==0)
        {   fault++;
            int min=0;
            for(j=1;j<f;j++)
            {
                if(recent[j]<recent[min])
                {
                    min=j;
                }
            }

            frames[min]=p;
            recent[min]=k;
            k++;
        }
        printframes(frames,f);


    }
   printf("the number of page faults is %d",fault);
    printf("no. of page miss is %d",n-fault);
}

void lfu(int n, int f, int pages[]) {
    int frames[f], freq[f], time[f];
    int i, j, k = 0;
    int fault = 0;

    // Initialize all frames
    for (j = 0; j < f; j++) {
        frames[j] = -1;
        freq[j] = 0;
        time[j] = -1;
    }

    for (i = 0; i < n; i++) {
        int p = pages[i];
        int flag = 0;

        // Check for hit
        for (j = 0; j < f; j++) {
            if (frames[j] == p) {
                flag = 1;
                freq[j]++;
                break;
            }
        }

        // Page fault
        if (!flag) {
            fault++;

            int replaceIndex = -1;

            // First look for empty frame
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // No empty frame, apply LFU + FIFO tie-breaker
            if (replaceIndex == -1) {
                int minFreq = freq[0];
                int earliestTime = time[0];
                replaceIndex = 0;

                for (j = 1; j < f; j++) {
                    if (freq[j] < minFreq) {
                        minFreq = freq[j];
                        earliestTime = time[j];
                        replaceIndex = j;
                    } else if (freq[j] == minFreq && time[j] < earliestTime) {
                        earliestTime = time[j];
                        replaceIndex = j;
                    }
                }
            }

            // Replace page
            freq[replaceIndex] = 1;       // Reset frequency
            frames[replaceIndex] = p;
            time[replaceIndex] = k++;     // Set arrival time
        }

        printframes(frames, f);
    }

    printf("The number of page faults is %d\n", fault);
    printf("The number of page hits is %d\n", n - fault);
}
int main()
{
    int n,f,i,ch;
    printf("enter the number of pages");
    scanf("%d",&n);
    printf("enter the number of frames");
    scanf("%d",&f);
    int pages[n];
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
            fifo(n,f,pages);
            break;

            case 2:
            lru(n,f,pages);
            break;

            case 3:
            lfu(n,f,pages);
            break;

            case 4:
            exit(0);

            default:
            printf("INVALID CHOICE\n");


        }

    }


}
