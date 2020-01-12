#include "header.h"

void delete_even(todolist event[], int *k)
{
    printf("==================================================================================\n");
    printf("                                    DELETE EVENT                                  \n");
    printf("==================================================================================\n\n");
    int c=*k;
    char decide;
    output_event(event,0,c);
    int idxhps;
    printf("\nNumber of event that you want to delete :");scanf("%d",&idxhps);
    fflush(stdin);
    printf("\nAre you sure want to delete this event? (Y/N) "); scanf("%c", &decide);
    printf("\n");
    system("cls");
    if(decide=='Y' || decide=='y') ///basic
            {
                int x;
                for(x=idxhps-1;x<c;x++)
                {
                    event[x]=event[x+1];
                }
                *k=c-1;
                c=*k;
            }

         else if(decide=='N' || decide=='n')
             {
                c=*k;
             }
    output_event(event,0,c);

}
