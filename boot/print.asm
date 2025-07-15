; Print a null-terminated string at [bx] using BIOS interrupt 0x10
print:
    pusha
start:
    mov al, [bx]
    cmp al, 0
    je done
    mov ah, 0x0e
    int 0x10
    add bx, 1
    jmp start
done:
    popa
    ret

; Print a newline and carriage return using BIOS interrupt 0x10
print_nl:
    pusha
    mov ah, 0x0e
    mov al, 0x0a
    int 0x10
    mov al, 0x0d
    int 0x10
    popa
    ret
