#include "RoundRobin.h"

RoundRobinScheduler::RoundRobinScheduler(int slice) : tail(nullptr), timeSlice(slice) {}

int RoundRobinScheduler::insertProcess(int time) {
    Process* newProcess = new Process{time, nullptr};
    if (!tail) {
        tail = newProcess;
        tail->next = tail;
    } else {
        newProcess->next = tail->next;
        tail->next = newProcess;
        tail = newProcess;
    }
    cout << "Inserted Process with Time: " << time << "\n";
    return 1;
}

int RoundRobinScheduler::execute() {
    if (!tail) {
        cout << "No Processes in Queue\n";
        return -1;
    }

    Process* temp = tail->next;
    int remainingTime = temp->time - timeSlice;

    if (remainingTime <= 0) {
        if (tail == temp) {
            delete tail;
            tail = nullptr;
        } else {
            tail->next = temp->next;
            delete temp;
        }
        cout << "Process Completed\n";
        return 0;
    }

    tail->next = temp->next;
    tail = temp;
    tail->time = remainingTime;

    cout << "Process Executed, Remaining Time: " << remainingTime << "\n";
    return remainingTime;
}

int RoundRobinScheduler::display() {
    if (!tail) {
        cout << "No Processes in Queue\n";
        return 0;
    }

    Process* temp = tail->next;
    cout << "Processes in Queue: ";
    do {
        cout << temp->time << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "\n";
    return 1;
}

RoundRobinScheduler::~RoundRobinScheduler() {
    while (tail) {
        execute();
    }
}

int main() {
    int timeSlice, choice, time;

    cout << "Enter Time Slice: ";
    cin >> timeSlice;

    RoundRobinScheduler rr(timeSlice);

    do {
        cout << "\n--- Round Robin Scheduler Menu ---\n";
        cout << "1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Process Time: ";
                cin >> time;
                rr.insertProcess(time);
                break;
            case 2:
                rr.execute();
                break;
            case 3:
                rr.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice.\n";
        }
    } while (choice != 4);

    return 0;
}
