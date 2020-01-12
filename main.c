#include "header.h"



int main()
{
    /*menu home*/
    todolist event[100];

    char decide;

    menu:;
    printf("==========================================\n");
    printf("            EVENTS ORGANIZER APP          \n");
    printf("==========================================\n");
    printf("1. Add an event\n");
    printf("2. Show an event\n");
    printf("3. Delete an event\n");
    printf("4. Find an event\n");
    printf("5. Sort an event\n");
    printf("6. EXIT\n");
    printf("==========================================\n");
    printf("Choose          : "); scanf("%d", &chs); ///input pilihan menu

    switch (chs)
    {
        /*jalan program pertama add event*/
        case 1      : system("cls"); goto menu1; break;
        case 2      : system("cls"); goto menu2; break;
        case 3      : system("cls"); goto menu3; break;
        case 4      : system("cls"); goto menu4; break;
        case 5      : system("cls"); goto menu5; break;
        case 6      : exit(0); /*keluar program*/
        default     : printf("\nError 404: NOT Found!"); Sleep(3000); system("cls"); goto menu;
    }

    menu1:;
    event[banyak]=input_event();
    banyak=banyak+1;
    printf("\nDo you want to add more event? (Y/N) "); scanf("%c", &decide);
    printf("\n");
    if(decide=='Y' || decide=='y') ///basic
            {
                goto menu1;
            }

         else if(decide=='N' || decide=='n')
             {
                system("pause");
                system("cls");
                goto menu;
             }
    ///appoint[0]=add_event(event, 0, 100);

    menu2:;
    if(banyak==0)
    {
        printf("There's no event exist\n\n");
    }
    else{
        output_event(event,0,banyak);
    }

    system("pause");
    system("cls");
    goto menu;

    menu3:;
    if(banyak==0)
    {
        printf("There's no event exist\n\n");
    }
    else{
        delete_even(event,&banyak);
    }

    system("pause");
    system("cls");
    goto menu;

    menu4:;
    if(banyak==0)
    {
        printf("There's no event exist\n\n");
    }
    else{
        printf("==================================================================================\n");
        printf("                                    SEARCH EVENT                                  \n");
        printf("==================================================================================\n\n");
        calendar tgl;
        printf("Enter the date      : "); scanf("%d", &tgl.date);
        printf("Enter the month     : "); scanf("%d", &tgl.month);
        printf("Enter the year      : "); scanf("%d", &tgl.year);

        index=cari(event,banyak,tgl);
        if(index!=-1)
        {
            printf("==================================================================================\n");
            printf("                                   Event %d                                   \n",index+1);
            printf("==================================================================================\n");

            printf("Event name                      : %s\n", event[index].event_name);
            printf("People who related              : %s\n", event[index].related_people);
            printf("Event date                      : %d - %d - %d\n", event[index].tanggal.date, event[index].tanggal.month, event[index].tanggal.year);
            if(event[index].waktu.minutes>=0&&event[index].waktu.minutes<=9)
                {
                    printf("Event time                      : %d:0%d\n", event[index].waktu.hours, event[index].waktu.minutes);
                }
            else
                {
                    printf("Event time                      : %d:%d\n", event[index].waktu.hours, event[index].waktu.minutes);
                }
        }
        else{
            printf("\n\nEvent Not Found\n\n");
        }
    }

    printf("\n");
    system("pause");
    system("cls");
    goto menu;

    menu5:;
        if(banyak==0)
    {
        printf("There's no event exist\n\n");
    }
    else{
        rec_selection_sort(event,banyak);
        output_event(event,0,banyak);
    }

    system("pause");
    system("cls");
    goto menu;

    return 0;
}
