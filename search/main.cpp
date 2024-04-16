#include <iostream>
#include <string>
#include "io.h"
#include "sorts.h"
#include "searches.h"

using namespace std;

int main(void)
{
    worker workers[NWORKERS_MAX];
	int workers_number = 0;
    string input_file_name = "input.txt";
    string output_file_name = "output.txt";
    worker* answer;
    read_file(input_file_name, workers, &workers_number);
    
    quick_sort_workers(workers, 0, workers_number - 1);
    print_workers(workers, workers_number);
    cout << "\n";
    answer = binary_search(workers, workers_number, 156);
    
    if (answer != nullptr) print_workers(answer, 1);
    else cout << "Not Found";
	return 0;
}
