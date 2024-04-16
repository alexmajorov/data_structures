#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "def.h"
#include "io.h"

using namespace std;

void read_file(string file_name, worker workers[], int* workers_number)
{
    ifstream fin(file_name);

    while ((*workers_number) < NWORKERS_MAX &&
        (fin >> workers[*workers_number].last_name >>
            workers[*workers_number].first_name >>
            workers[*workers_number].patronym >>
            workers[*workers_number].hours >>
            workers[*workers_number].wage))
        ++(*workers_number);
    return;
}

void write_file(string file_name, worker workers[], int workers_number)
{
    ofstream fout(file_name);

    for (int i = 0; i < workers_number; ++i)
        fout << 
            setw(SETW_CONST) << left << workers[i].last_name << 
            setw(SETW_CONST) << left << workers[i].first_name << 
            setw(SETW_CONST) << left << workers[i].patronym << 
            setw(SETW_CONST) << left << workers[i].hours << 
            setw(SETW_CONST) << left << workers[i].wage << 
        endl;
}

void print_workers(worker workers[], int workers_number)
{
    for (int i = 0; i < workers_number; ++i)
        cout <<
            setw(SETW_CONST) << left << workers[i].last_name <<
            setw(SETW_CONST) << left << workers[i].first_name <<
            setw(SETW_CONST) << left << workers[i].patronym <<
            setw(SETW_CONST) << left << workers[i].hours <<
            setw(SETW_CONST) << left << workers[i].wage <<
        endl;
    return;
}