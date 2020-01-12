#include "header.h"

int cari(todolist events[], int batas, calendar tgl)
{
    int x;
    int vv=-1;
    for(x=0;x<batas;x++)
    {
        if(events[x].tanggal.year == tgl.year)
        {
            if(events[x].tanggal.month == tgl.month)
            {
                if(events[x].tanggal.date == tgl.date)
                {
                    vv=x;
                }
            }
        }
    }
    return vv;
}
