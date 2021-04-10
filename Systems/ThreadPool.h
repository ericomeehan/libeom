//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// ThreadPool.h
//
// Eric Meehan
// 2/26/21
//
//

/*
The ThreadPool object is used to create a provided number of threads awaiting work to be added to a queue.
 Work takes the form of a function with arguments wrapped in a ThreadJob, which is added as the data to the work queue.
 */

#ifndef ThreadPool_h
#define ThreadPool_h

#include "../DataStructures/Lists/Queue.h"

#include <pthread.h>

// MARK: DATA TYPES

struct ThreadJob
{
    // The function to be executed.
    void * (*job)(void *arg);
    // The argument to be passed.
    void *arg;
};

struct ThreadPool
{
    // The number of threads in the pool.
    int num_threads;
    // A control switch for the thread pool.
    int active;
    // A queue to store work.
    struct Queue work;
    // Mutices for making the pool thread-safe.
    pthread_t *pool;
    pthread_mutex_t lock;
    pthread_cond_t signal;
    // A function for safely adding work to the queue.
    void (*add_work)(struct ThreadPool *thread_pool, struct ThreadJob thread_job);
};

// MARK: CONSTRUCTORS

struct ThreadPool thread_pool_constructor(int num_threads);
struct ThreadJob thread_job_constructor(void * (*job)(void *arg), void *arg);

void thread_pool_destructor(struct ThreadPool *thread_pool);

#endif /* ThreadPool_h */
