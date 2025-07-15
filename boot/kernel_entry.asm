; Kernel entry point for 32-bit protected mode. Calls kernel_main in C.
global _start;
[bits 32]

_start:
    [extern kernel_main]
    call kernel_main
    jmp $
