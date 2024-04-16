#include "def.h"
#include "sorts.h"

void swap_workers(worker* worker1, worker* worker2)
{
    worker temp_worker = *worker1;
    *worker1 = *worker2;
    *worker2 = temp_worker;
    return;
}

void bubble_sort_workers(worker workers[], int workers_number)
{
    for (int i = 0; i < workers_number - 1; ++i)
        for (int j = 0; j < workers_number - i - 1; ++j)
            if (workers[j].hours - workers[j + 1].hours > EPS)
                swap_workers(&workers[j], &workers[j + 1]);
    return;
}

void quick_sort_workers(worker workers[], int start, int end)
{
    int i = start;
    int j = end;
    int pivot = (i + j) / 2;

    while (i <= j)
    {
        while (workers[i].hours < workers[pivot].hours) ++i;
        while (workers[j].hours > workers[pivot].hours) --j;
        if (i <= j)
        {
            swap_workers(&workers[i], &workers[j]);
            ++i;
            --j;
        }
    }

    if (j > start) quick_sort_workers(workers, start, j);
    if (i < end) quick_sort_workers(workers, i, end);
    return;
}

void selection_sort_workers(worker workers[], int workers_number)
{
    for (int i = 0; i < workers_number - 1; ++i)
    {
        int current_min_index = i;
        for (int j = i + 1; j < workers_number; ++j)
            if (workers[j].hours - workers[current_min_index].hours < EPS)
                current_min_index = j;
    
        if (current_min_index != i)
            swap_workers(&workers[i], &workers[current_min_index]);
    }
    return;
}
