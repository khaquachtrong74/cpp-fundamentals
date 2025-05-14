    .section .rodata
msg1:
    .string "Hello, world!\n"
msg2:
    .string "Goodbye!\n"
msg3:
    .string "Another string\n"

    .text
    .globl main
main:
    # In msg1
    leaq    msg1(%rip), %rdi   # đưa địa chỉ msg1 vào RDI (tham số 1 cho puts)
    leaq    msg2(%rip), %rsi 
    leaq    msg3(%rip), %rdi 
    call    printf@PLT

    movl    $0, %eax
    ret
