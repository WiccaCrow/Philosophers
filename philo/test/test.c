# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<sys/time.h>
# include <pthread.h>

typedef struct  s_mutex
{
    pthread_mutex_t data;
    atomic int _lock;
    struct  s_mutex *self;

    void (*lock)(t_mutex *self);
    void (*unlock)(t_mutex *self);
}              t_mutex;


void lock(t_mutex *m)
{
    m._lock = 1;
    pthread_mutex_lock(m->data);
} 

void unlock(t_mutex *m)
{
    m._lock = 0;
    pthread_mutex_lock(m->data);
} 

void init(t_mutex *m)
{
    m->_lock = 0;
    m->self = m;
    m->lock = &lock;
    m->unlock = &unlock;
    pthread_mutex_init(&m->data, 0);
}

int main() {
    t_mutex m;

    init(&m);

    printf("%d\n", m._lock);
    m.lock(m);
    printf("%d\n", m._lock);
    m.unlock(m);
    printf("%d\n", m._lock);

    // if (test.__opaque[18] & test.__opaque[24]) lock
    
    // pthread_mutex_t test;
    // test = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    // for (int i =0; i < 56; ++i)
    //     printf("%4d, ", test.__opaque[i]);
    // printf("\nsig: %ld\n", test.__sig);
    // pthread_mutex_lock(&test);
    // for (int i =0; i < 56; ++i)
    //     printf("%4d, ", test.__opaque[i]);
    // printf("\nsig: %ld\n", test.__sig);
    // pthread_mutex_unlock(&test);
    // for (int i =0; i < 56; ++i)
    //     printf("%4d, ", test.__opaque[i]);
    // printf("\nsig: %ld\n", test.__sig);
    //  pthread_mutex_lock(&test);
    // for (int i =0; i < 56; ++i)
    //     printf("%4d, ", test.__opaque[i]);
    // printf("\nsig: %ld\n", test.__sig);
    //  pthread_mutex_unlock(&test);
    // for (int i =0; i < 56; ++i)
    //     printf("%4d, ", test.__opaque[i]);
    // printf("\nsig: %ld\n", test.__sig);
    return 0;
}