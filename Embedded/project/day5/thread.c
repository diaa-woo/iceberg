#include "thread.h"

uint32_t thread_create(callback_t func, void *args)
{
    uint32_t t_id;
    pthread_create(&t_id, NULL, func, args);
    return t_id;
}

int thread_join(uint32_t t_id)
{
    int status;
    int rc;
    rc = pthread_join(t_id, (void**)&status);

    return (rc == 0) ? status : rc;
}

int thread_exit(int state)
{
    pthread_exit((void *)state);
}