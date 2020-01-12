#include "header.h"

void rec_selection_sort_2(todolist data[], int cur, int arrSize, int *x)
{
    int time1,time2;
    time1=urut_tanggal(data[cur]);
    time2=urut_tanggal(data[*x]);
    if(cur<arrSize)
    {
        if(time1>time2)
        {
            *x=cur;
        }
        rec_selection_sort_2(data,cur+1,arrSize,x);
    }
}


void rec_selection_sort(todolist data[], int arrSize)
{

    int maxx=0;
    todolist temp;

    if(arrSize>1)
    {
        rec_selection_sort_2(data,1,arrSize, &maxx);
        temp=data[arrSize-1];
        data[arrSize-1]=data[maxx];
        data[maxx]=temp;
        rec_selection_sort(data,arrSize-1);
    }
}

int urut_tanggal(todolist events)
{
    int menit,jam,hari,bulans,tahun;
    if(events.tanggal.year %4 ==0)
    {
        tahun=events.tanggal.year*525600;
        if(events.tanggal.month==2)
        {
            bulans=events.tanggal.month*41760;
        }
    }
    else
        {
            tahun=events.tanggal.year*524160;
            if(events.tanggal.month==2)
            {
                bulans=events.tanggal.month*40320;
            }
        }

    if((events.tanggal.month==4 || events.tanggal.month==6 || events.tanggal.month==9 ||
        events.tanggal.month==11))
        {
            bulans=events.tanggal.month*43200;
        }
        else if(events.tanggal.month==1 ||events.tanggal.month==3 ||events.tanggal.month==5 ||
                events.tanggal.month==7 ||events.tanggal.month==8 ||events.tanggal.month==10 ||events.tanggal.month==12)
                {
                    bulans=events.tanggal.month*44640;
                }
    hari=events.tanggal.date*1440;
    jam=events.waktu.hours*60;
    menit=events.waktu.minutes+jam+hari+bulans+tahun;

    return menit;
}
