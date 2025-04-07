#include <stdio.h>
#include <stdlib.h>

int p, n, i, j, f, pages[30], recent[30], time[30], freq[30], frames[30];

void printframes()
{
    for (j = 0; j < f; j++)
    {
        if (frames[j] == -1)
            printf("|-|");
        else
            printf("|%d|", frames[j]);
    }
    printf("\n");
}

void fifo()
{
    int k = 0, fault = 0;

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++)
    {
        p = pages[i];
        int flag = 0;
        for (j = 0; j < f; j++)
        {
            if (p == frames[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            fault++;
            frames[k] = p;
            k = (k + 1) % f;
        }
        printframes();
    }

    printf("The number of faults is %d\n", fault);
    printf("The number of hits is %d\n", n - fault);
}

void lru()
{
    int k = 0, fault = 0;

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        p = pages[i];
        int flag = 0;
        for (j = 0; j < f; j++)
        {
            if (p == frames[j])
            {
                flag = 1;
                recent[j] = k++;
                break;
            }
        }
        if (!flag)
        {
            int min = 0;
            for (j = 1; j < f; j++)
            {
                if (recent[j] < recent[min])
                    min = j;
            }
            fault++;
            frames[min] = p;
            recent[min] = k++;
        }
        printframes();
    }

    printf("The number of faults is %d\n", fault);
    printf("The number of hits is %d\n", n - fault);
}

void lfu()
{
    int global_freq[100] = {0};
    int fault = 0, k = 0;

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = -1;
        freq[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        p = pages[i];
        int flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == p)
            {
                flag = 1;
                global_freq[p]++;
                freq[j] = global_freq[p];
                break;
            }
        }

        if (!flag)
        {
            int minFreq = freq[0], minindex = 0, earliest = time[0];

            for (j = 1; j < f; j++)
            {
                if (freq[j] < minFreq)
                {
                    minFreq = freq[j];
                    earliest = time[j];
                    minindex = j;
                }
                else if (freq[j] == minFreq && time[j] < earliest)
                {
                    earliest = time[j];
                    minindex = j;
                }
            }

            fault++;
            frames[minindex] = p;
            global_freq[p]++;
            freq[minindex] = global_freq[p];
            time[minindex] = k++;
        }
        printframes();
    }

    printf("The number of faults is %d\n", fault);
    printf("The number of hits is %d\n", n - fault);
}

void mfu()
{
    int global_freq[100] = {0};
    int fault = 0, k = 0;

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = -1;
        freq[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        p = pages[i];
        int flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == p)
            {
                flag = 1;
                global_freq[p]++;
                freq[j] = global_freq[p];
                break;
            }
        }

        if (!flag)
        {
            int maxFreq = freq[0], maxindex = 0, earliest = time[0];

            for (j = 1; j < f; j++)
            {
                if (freq[j] > maxFreq)
                {
                    maxFreq = freq[j];
                    earliest = time[j];
                    maxindex = j;
                }
                else if (freq[j] == maxFreq && time[j] < earliest)
                {
                    earliest = time[j];
                    maxindex = j;
                }
            }

            fault++;
            frames[maxindex] = p;
            global_freq[p]++;
            freq[maxindex] = global_freq[p];
            time[maxindex] = k++;
        }
        printframes();
    }

    printf("The number of faults is %d\n", fault);
    printf("The number of hits is %d\n", n - fault);
}

void optimal()
{
    int fault = 0;

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++)
    {
        p = pages[i];
        int flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == p)
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            fault++;
            int replace_index = -1, farthest = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    replace_index = j;
                    break;
                }
            }

            if (replace_index == -1)
            {
                for (j = 0; j < f; j++)
                {
                    int k, next_use = -1;
                    for (k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frames[j])
                        {
                            next_use = k;
                            break;
                        }
                    }

                    if (next_use == -1)
                    {
                        replace_index = j;
                        break;
                    }

                    if (next_use > farthest)
                    {
                        farthest = next_use;
                        replace_index = j;
                    }
                }
            }

            frames[replace_index] = p;
        }
        printframes();
    }

    printf("The number of faults is %d\n", fault);
    printf("The number of hits is %d\n", n - fault);
}

int main()
{
    int ch;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the page sequence:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    while (1)
    {
        printf("\nChoose an algorithm:\n");
        printf("1. FIFO\n2. LRU\n3. LFU\n4. MFU\n5. OPTIMAL\n6. Exit\n");
        scanf("%d", &ch);

        switch (ch)
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
            mfu();
            break;
        case 5:
            optimal();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
