#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <iostream>
using namespace std;

struct Process {
    int time;
    Process* next;
};

class RoundRobinScheduler {
private:
    Process* tail;
    int timeSlice;

public:
    RoundRobinScheduler(int);
    int insertProcess(int);
    int execute();
    int display();
    ~RoundRobinScheduler();
};

#endif
