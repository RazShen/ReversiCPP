/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX4_TASK_H
#define EX4_TASK_H

class Task {
public:
    /**
     * Constructor for a task.
     * @param func - void * obj
     * @param arg - void * arg
     */
    Task(void * (*func)(void *arg), void* arg): func(func), arg(arg) {

    }

    /**
     * Execute the function of the task.
     */
    void execute() {
        func(arg);
    }

    /**
     * Destructor for the task
     */
    virtual ~Task() {}
private:
    //members
    void * (*func)(void *arg);
    void *arg;
};


#endif //EX4_TASK_H
