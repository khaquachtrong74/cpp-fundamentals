.global _start
.section .text
_start:
    mov $1, %rax
    mov $1, %rdi
    mov msg, %rdx 
    mov $13, %rsi
    syscall

    mov $60, %rax 
    mov $0, %rdi  
    syscall 
msg:
    .asciz "Hello World\n"

