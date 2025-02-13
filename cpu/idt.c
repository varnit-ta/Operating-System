#include "idt.h"

/* Define the IDT table */
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

/* Set an entry in the IDT */
void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = handler & 0xFFFF;
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = (handler >> 16) & 0xFFFF;
}

/* Load the IDT */
void set_idt() {
    idt_reg.base = (uint32_t)&idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    asm volatile("lidtl (%0)" : : "r" (&idt_reg));
}
