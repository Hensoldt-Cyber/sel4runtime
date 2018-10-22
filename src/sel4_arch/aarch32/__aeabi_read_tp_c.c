/*
 * Copyright 2018, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */
#include <autoconf.h>
#include <sel4/sel4.h>

__attribute__((__visibility__("hidden")))
void *__aeabi_read_tp_c(void) {
#if defined(CONFIG_IPC_BUF_GLOBALS_FRAME)
    return ((void **)(seL4_GlobalsFrame))[1];
#else
    void *p;
    __asm__ __volatile__ ( "mrc p15,0,%0,c13,c0,3" : "=r"(p) );
    return p;
#endif
}