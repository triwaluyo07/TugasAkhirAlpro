#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

typedef struct//type data tangal
{
    int date;
    int month;
    int year;
}calendar;

typedef struct//type data jam
{
    int minutes;
    int hours;
}time;

typedef struct//type data acara
{
    char event_name[255];
    char related_people[255];
    calendar tanggal;
    time waktu;
}todolist;

todolist input_event();
todolist add_event(todolist event[], int cur, int limit);
void output_event(todolist event[],int cur,int limit);
int cari(todolist events[], int batas, calendar tgl);
int urut_tanggal(todolist data);
void rec_selection_sort(todolist data[], int arrSize);
void rec_selection_sort_2(todolist data[], int cur, int arrSize, int *x);
void delete_even(todolist event[], int *isisi);

int chs;
int banyak;

int index;

#endif // HEADER_H_INCLUDED
