; -------------------------------------------------------------------
; hello.asm - Windows x64 Hello World
; -------------------------------------------------------------------

extern GetStdHandle
extern WriteFile
extern ExitProcess

section .data
    msg db 'Hello from Windows Assembly!', 0Dh, 0Ah
    msg_len equ $ - msg
    stdout_query equ -11

section .bss
    bytes_written resd 1

section .text
    global main
main:
    sub rsp, 40          ; Shadow space for Windows function calls

    ; Get handle to stdout
    mov ecx, stdout_query
    call GetStdHandle
    mov r12, rax         ; Save handle in r12

    ; WriteFile(handle, msg, len, &bytes_written, NULL)
    mov rcx, r12         ; 1st arg: handle
    lea rdx, [rel msg]   ; 2nd arg: message pointer
    mov r8d, msg_len     ; 3rd arg: message length
    lea r9, [rel bytes_written] ; 4th arg: pointer to output variable
    mov qword [rsp + 32], 0    ; 5th arg: NULL (on stack)
    call WriteFile

    ; ExitProcess(0)
    xor ecx, ecx
    call ExitProcess