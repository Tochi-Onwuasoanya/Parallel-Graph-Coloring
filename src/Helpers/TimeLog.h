#ifndef SRC_TIMELOG_H
#define SRC_TIMELOG_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class TimeLog {
private:
    std::chrono::steady_clock::time_point _start;
    string _name;

public:
    explicit TimeLog(const string &name) {
        _name = name;
    }

    ~TimeLog() = default;

    void start() {
        cout << ">>>>>>>>>>>>>>> Starting " << _name << endl;
        _start = std::chrono::steady_clock::now();
    }

    double stop() {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration<double>(end - _start).count();
        cout << ">>>>>>>>>>>>>>> Ending " << _name
            << ", Duration: " << duration << " seconds" << endl;
        return duration;
    }
};


#endif 
