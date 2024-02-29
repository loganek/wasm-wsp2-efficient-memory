#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define TEXT "hello"
#define TEXT_SIZE sizeof(TEXT)

static size_t preview1_read(char *buf, size_t len)
{
    // the syscall should be implemented in the host, but we provide
    // the implementation here just for simplicity
    size_t size = TEXT_SIZE > len ? len : TEXT_SIZE;
    memcpy(buf, TEXT, size);
    return size;
}

void *user_allocator_alloc(size_t len);

// the actual adapter function
void __wasm_import_mkolny_pkg_example_read(int64_t len, uint8_t* ret)
{
    void *data = user_allocator_alloc(len);

    preview1_read(data, len);

    *((uint32_t*)ret) = (int32_t)data;
    *((uint32_t*)(ret + 4)) = len;
}