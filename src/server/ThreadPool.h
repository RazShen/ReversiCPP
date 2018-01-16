/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#ifndef EX4_THREADPOOL_H
#define EX4_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {

public:

    /**
     * ThreadPool constructor.
     * @param threadsNum - number of threads for pool
     */
    ThreadPool(int threadsNum);
    /**
     * Add a task to the thread pool.
     * @param task - Task obj
     */
    void addTask(Task *task);
    /**
     * Terminate function.
     */
    void terminate();
    /**
     * Destructor for the thread pool
     */
    virtual ~ThreadPool();
private:
    //members
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};



#endif //EX4_THREADPOOL_H
