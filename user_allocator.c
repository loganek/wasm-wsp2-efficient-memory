#include "user_allocator.h"

#include <stdlib.h>
#include <string.h>

typedef struct {
    void* buffer;
    size_t len;
    int used;
} user_allocator_t;

_Thread_local user_allocator_t user_allocator = {0};

void user_allocator_set(void *buffer, size_t len)
{
    user_allocator.buffer = buffer;
    user_allocator.len = len;
    user_allocator.used = 0;
}

void user_allocator_reset()
{
    memset(&user_allocator, 0, sizeof(user_allocator));
}

void* user_allocator_alloc(size_t len)
{
    if (user_allocator.used == 0 && len <= user_allocator.len) {
        void *ret = user_allocator.buffer;
        user_allocator.used = 1;
        return ret;
    }
    return malloc(len);
}

int user_allocator_is_buffer(void *buf)
{
    return buf == user_allocator.buffer;
}