#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include <sstream>
#include "module/ThreadPool.h"
#include <ctime>

using namespace std;

const string filename = "D:\\Minh\\code\\CandC++\\ThreadPool\\Input\\input.txt";
void task(int time);

int main()
{
    auto start = chrono::system_clock::now();
    //create thread
    ThreadPool pool(10);
    pool.init();

    ifstream file(filename);
    string str;
    while (getline(file, str))
    {
        // Process str
        stringstream geek(str);
        int x = 0;
        geek >> x;
        pool.submit(task, x);
    }
    pool.shutdown();
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "finished computation at " << ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << endl;
    return  0;
}

void task(int t)
{
    this_thread::sleep_for(chrono::milliseconds(t*1000));
}
