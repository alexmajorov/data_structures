#include "def.h"
#include "searches.h"

worker* linear_search(worker workers[], int number_of_workers, int number_of_hours) 
{
    worker* answer = nullptr;
    for (int i = 0; i < number_of_workers; ++i)
        if (workers[i].hours == number_of_hours)
        {
            answer = &workers[i];
            break;
        }
    return answer;
}

worker* binary_search(worker workers[], int number_of_workers, int number_of_hours)
{
    int right = number_of_workers - 1;
    int left = 0;

    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (workers[middle].hours < number_of_hours) 
            left = middle + 1;
        else
            right = middle;
    }

    if (left < number_of_workers && workers[left].hours == number_of_hours)
        return &workers[left];

    return nullptr;
}
