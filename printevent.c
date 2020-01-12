#include "header.h"

void output_event(todolist event[],int cur,int limit)
{
    if(cur==limit)
    {

    }
    else
    {
        printf("==================================================================================\n");
        printf("                                   Event %d                                   \n",cur+1);
        printf("==================================================================================\n");

         printf("Event name                      : %s\n", event[cur].event_name);
         printf("People who related              : %s\n", event[cur].related_people);
         printf("Event date                      : %d - %d - %d\n", event[cur].tanggal.date, event[cur].tanggal.month, event[cur].tanggal.year);
         if(event[cur].waktu.minutes>=0&&event[cur].waktu.minutes<=9)
         {
             printf("Event time                      : %d:0%d\n", event[cur].waktu.hours, event[cur].waktu.minutes);
         }
         else
        {
            printf("Event time                      : %d:%d\n", event[cur].waktu.hours, event[cur].waktu.minutes);
         }
         output_event(event,cur+1,limit);

    }

}
