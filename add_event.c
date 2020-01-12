#include "header.h"


todolist input_event()//input acara
{
    todolist events;

    printf("==================================================================================\n");
    printf("                                      ADD EVENT                                   \n");
    printf("==================================================================================\n\n");
    fflush(stdin);
    printf("Enter the event name            : "); gets(events.event_name);
    printf("Who's related in this event?    : "); gets(events.related_people);
    fflush(stdin);
    date:;
    printf("Enter the date                  : "); scanf("%d", &events.tanggal.date);
    fflush(stdin);
    printf("Enter the month                 : "); scanf("%d", &events.tanggal.month);
    fflush(stdin);

    if((events.tanggal.month==2 || events.tanggal.month==4 || events.tanggal.month==6 || events.tanggal.month==9 ||
        events.tanggal.month==11)&&(events.tanggal.date>30))// kondisi jumlah tanggal pada bulan yang kurang lebih dari 30 hari
        {
         printf("The date that you've entered is invalid!\n");//pemebritahuan tanggal salah karena tanggal tidak ada pada bulan itu
         Sleep(3000);
         printf("\r");
         goto date;//kembali input tanggal
        }
    else if(events.tanggal.month>12|| (events.tanggal.date>31))
    {
        printf("The date that you've entered is invalid!\n");//pemebritahuan tanggal salah karena tanggal tidak ada pada bulan itu
         Sleep(3000);
         printf("\r");
         goto date;//kembali input tanggal

    }
    else//jika tangal dan bilan sudah benar
        {
         printf("Enter the year                  : "); scanf("%d", &events.tanggal.year);//input tahun
         /*menghitung kabisat*/
         if(events.tanggal.year%4!=0)//jika tidak kabisat
            {
             if(events.tanggal.month==2 && events.tanggal.date>28)//jika input februari lebih dari tanggal 28 input ulang
                {
                 printf("The date that you've entered is invalid!\n");//pemebritahuan inputan salah
                 Sleep(3000);
                 printf("\r");
                 goto date;
                }
             else//program lanjut apabila tanggal benar
                {
                /*input jam*/
                 time:;
                 fflush(stdin);
                 printf("Enter the hours                 : "); scanf("%d", &events.waktu.hours);
                 fflush(stdin);
                 printf("Enter the minutes               : "); scanf("%d", &events.waktu.minutes);
                 fflush(stdin);
                 if(events.waktu.hours>23||events.waktu.minutes>59)
                    {
                     printf("The time that you've entered is invalid!\n");//pemebritahuan inputan salah
                     Sleep(3000);
                     printf("\r");
                     goto time;
                    }
                }
            }
            else
            {
             if(events.tanggal.month==2 && events.tanggal.date>29)//jika input februari lebih dari tanggal 28 input ulang
                {
                 printf("The date that you've entered is invalid!\n");//pemebritahuan inputan salah
                 Sleep(3000);
                 printf("\r");
                 goto date;
                }
             else//program lanjut apabila tanggal benar
                {
                /*input jam*/
                 fflush(stdin);
                 printf("Enter the hours                 : "); scanf("%d", &events.waktu.hours);
                 fflush(stdin);
                 printf("Enter the minutes               : "); scanf("%d", &events.waktu.minutes);
                 fflush(stdin);
                 if(events.waktu.hours>23||events.waktu.minutes>59)
                    {
                     printf("The time that you've entered is invalid!\n");//pemebritahuan inputan salah
                     Sleep(3000);
                     printf("\r");
                     goto time;
                    }
                }
            }
        }

    printf("\n----------------------------------------------------------------------------------\n\n");

    printf("NEW EVENT HAS BEEN ADDED!\n\n");//pemeberitahuan berhasil input
    /*laporan langusng seletah input*/
    if(events.waktu.minutes>9)//jika menit =0 hanya input menit 0
        {
         printf("Event name                      : %s\n", events.event_name);
         printf("People who related              : %s\n", events.related_people);
         printf("Event date                      : %d - %d - %d\n", events.tanggal.date, events.tanggal.month, events.tanggal.year);
         printf("Event time                      : %d:%d\n", events.waktu.hours, events.waktu.minutes);
        }
    else//jika menit !=0 hanya input menit 0+menit
        {
         printf("Event name                      : %s\n", events.event_name);
         printf("People who related              : %s\n", events.related_people);
         printf("Event date                      : %d - %d - %d\n", events.tanggal.date, events.tanggal.month, events.tanggal.year);
         printf("Event time                      : %d:0%d\n", events.waktu.hours, events.waktu.minutes);
        }
    return events;
}
