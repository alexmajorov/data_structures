#ifndef _DEF_H_
#define _DEF_H_

#include <string>

using namespace std;

#define NWORKERS_MAX 50
#define SETW_CONST 15
#define EPS 0.000001

struct worker
{
    string first_name;
    string last_name;
    string patronym;
    int hours;
    float wage;
};

#endif