int waiting_time[20];
int priority(int a,int b)
{
	//b_time:Burst time; ta_time:turnaround time ; aw_time : Average wait time ;
	int b_time[20], process[20], ta_time[20], priority[20];
      int i, j, limit, sum = 0, position, temp;
      float aw_time, average_ta_time;
      printf("applying priority scheduling algorithm on queue no. %d",b);
      /*printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);*/
      limit=a;
      int ask=1;
      printf("\nEnter Burst Time and Priority For %d Processes\n", limit);
      if(ask=1)
      {
      	for(i = 0; i < limit; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Burst Time:\t");
            scanf("%d", &b_time[i]);
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      ask=0;
	  }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = b_time[i];
            b_time[i] = b_time[position];
            b_time[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + b_time[j];
            }
            sum = sum + waiting_time[i];
      }
      aw_time = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            ta_time[i] = b_time[i] + waiting_time[i];
            sum = sum + ta_time[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], b_time[i], waiting_time[i], ta_time[i]);
      }
      average_ta_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", aw_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_ta_time);
      return 0;
}

int firstcomefirstserve(int c, int d)
{
	float b_time[30], waiting_time[30], ta_time[30];
        float average_waiting_time = 0.0, average_ta_time = 0.0;
        int count, j, total_process;
        printf("applying firstcomefirstserve on queue no . %d",d);
        /*printf("Enter The Number of Processes To Execute:\t");
        scanf("%d", &total_process);*/
        total_process=c;
        printf("\nEnter The Burst Time of Processes:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("Process [%d]:", count + 1);
                scanf("%f", &b_time[count]);
        }
        waiting_time[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + b_time[j];
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                ta_time[count] = b_time[count] + waiting_time[count];
                average_waiting_time = average_waiting_time + waiting_time[count];
                average_ta_time = average_ta_time + ta_time[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, b_time[count], waiting_time[count], ta_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;
        average_ta_time = average_ta_time / count;
        printf("\nAverage Waiting Time = %f", average_waiting_time);
        printf("\nAverage Turnaround Time = %f", average_ta_time);
        printf("\n");
        return 0;
}

int roundrobin(int e, int f)
{
	int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, ta_time = 0, arrival_time[10], b_time[10], temp[10]; 
      float aw_time, average_ta_time;
      printf("applying roundrobin on queue no. %d ",f);
      /*printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit);*/
	  limit=e; 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[i]); 
            temp[i] = b_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, b_time[i], total - arrival_time[i], total - arrival_time[i] - b_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - b_time[i]; 
                  ta_time = ta_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      aw_time = wait_time * 1.0 / limit;
      average_ta_time = ta_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", aw_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_ta_time); 
      return 0; 
}
