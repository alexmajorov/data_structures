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
            if (workers[j].hours > workers[j + 1].hours)
                swap_workers(&workers[j], &workers[j + 1]);
    return;
}

int partition(worker arr[], int low, int high)
{
    int pivot = arr[high].hours;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].hours < pivot) 
        {
            i++;
            swap_workers(&arr[i], &arr[j]);
        }
    }
    swap_workers(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_workers(worker arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quick_sort_workers(arr, low, pi - 1);
        quick_sort_workers(arr, pi + 1, high);
    }
}