#ifndef USER_ALLOCATOR_H
#define USER_ALLOCATOR_H

#include <inttypes.h>

void user_allocator_reset();

void user_allocator_set(void *buffer, size_t len);

void* user_allocator_alloc(size_t len);

int user_allocator_is_buffer(void *buf);

#endif
