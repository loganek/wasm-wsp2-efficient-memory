#include "libc.h"
#include "imports.h"
#include "user_allocator.h"

#include <string.h>

void read_data(char *buf, size_t buf_len)
{
    imports_list_u8_t out_list;

    user_allocator_set(buf, buf_len);

    mkolny_pkg_example_read(buf_len, &out_list);

    if (!user_allocator_is_buffer(out_list.ptr)) {
        memcpy(buf, out_list.ptr, out_list.len);
        imports_list_u8_free(&out_list);
    }
    user_allocator_reset();
}