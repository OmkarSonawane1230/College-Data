section .data
    msg1 db "Enter the first number: ",0xa    ; Prompt for first number
    len1 equ $ - msg1
    msg2 db "Enter the 2nd number: ",0xa      ; Prompt for second number
    len2 equ $ - msg2
    msg3 db "The sum is: ",0xa                ; Message for the result
    len3 equ $ - msg3

section .bss
    num1 resb 10                              ; Reserve space for first number (up to 10 digits)
    num2 resb 10                              ; Reserve space for second number (up to 10 digits)
    res resb 10                               ; Reserve space for result (up to 10 digits)

section .text
    global _start
_start:
    ; Print "Enter the first number:"
    mov edx, len1
    mov ecx, msg1
    mov ebx, 1         ; File descriptor 1 (stdout)
    mov eax, 4         ; Syscall number for sys_write (4)
    int 0x80           ; Make syscall

    ; Read first number (user input)
    mov edx, 10        ; Maximum number of bytes to read
    mov ecx, num1      ; Buffer to store first number
    mov ebx, 0         ; File descriptor 0 (stdin)
    mov eax, 3         ; Syscall number for sys_read (3)
    int 0x80           ; Make syscall

    ; Print "Enter the second number:"
    mov edx, len2
    mov ecx, msg2
    mov ebx, 1         ; File descriptor 1 (stdout)
    mov eax, 4         ; Syscall number for sys_write (4)
    int 0x80           ; Make syscall

    ; Read second number (user input)
    mov edx, 10        ; Maximum number of bytes to read
    mov ecx, num2      ; Buffer to store second number
    mov ebx, 0         ; File descriptor 0 (stdin)
    mov eax, 3         ; Syscall number for sys_read (3)
    int 0x80           ; Make syscall

    ; Convert first number (num1) from ASCII to integer
    xor eax, eax        ; Clear eax (to store the number)
    xor ebx, ebx        ; Clear ebx (to keep track of digits)
convert_first:
    mov al, [num1 + ebx]
    cmp al, 0           ; Check for null terminator
    je convert_second   ; Jump if we reach end of input
    sub al, '0'         ; Convert ASCII to integer
    imul eax, eax, 10   ; Multiply current value in eax by 10 (shift left)
    add eax, al         ; Add the current digit to the number
    inc ebx             ; Move to next character
    jmp convert_first   ; Repeat until the whole number is processed

convert_second:
    xor ebx, ebx        ; Clear ebx (to keep track of digits for second number)
    xor ecx, ecx        ; Clear ecx (to store the second number)
convert_second_loop:
    mov al, [num2 + ebx]
    cmp al, 0           ; Check for null terminator
    je add_numbers      ; Jump if we reach the end of input
    sub al, '0'         ; Convert ASCII to integer
    imul ecx, ecx, 10   ; Multiply current value in ecx by 10 (shift left)
    add ecx, al         ; Add the current digit to the number
    inc ebx             ; Move to next character
    jmp convert_second_loop

add_numbers:
    add eax, ecx        ; Add the two numbers (eax + ecx), result stored in eax

    ; Convert result back to ASCII
    add eax, '0'        ; Convert the sum back to ASCII (we only handle single digits here)

    ; Store result in memory
    mov [res], eax      ; Store the result in 'res'

    ; Print "The sum is:"
    mov edx, len3
    mov ecx, msg3
    mov ebx, 1         ; File descriptor 1 (stdout)
    mov eax, 4         ; Syscall number for sys_write (4)
    int 0x80           ; Make syscall

    ; Print the result
    mov edx, 1         ; Print 1 byte (the sum)
    mov ecx, res       ; Pointer to result
    mov ebx, 1         ; File descriptor 1 (stdout)
    mov eax, 4         ; Syscall number for sys_write (4)
    int 0x80           ; Make syscall

    ; Exit the program
    mov ebx, 0         ; Return code 0
    mov eax, 1         ; Syscall number for sys_exit (1)
    int 0x80           ; Make syscall
