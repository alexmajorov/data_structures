#include <iostream>
#include <string>
#include "io.h"
#include "sorts.h"

int main(void)
{
    worker workers[NWORKERS_MAX];
	int workers_number = 0;
    string input_file_name = "input.txt";
    string output_file_name = "output.txt";
    read_file(input_file_name, workers, &workers_number);

    //bubble_sort_workers(workers, workers_number);
    //quick_sort_workers(workers, 0, workers_number - 1);
    selection_sort_workers(workers, workers_number);
    print_workers(workers, workers_number);

    write_file(output_file_name, workers, workers_number);

	return 0;
}
