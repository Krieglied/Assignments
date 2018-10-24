;Name: Robert John Graham III
;Date: 23 Oct 2018
;Project: Lab 13
;
; vim: filetype=nasm :

bits 64

; LABS
global ex_strlen, ex_memcpy, ex_memset, ex_memcmp, ex_memchr, ex_strchr, ex_strcmp, ex_strcpy, ex_atoi
global ex_strstr, find_largest, walk_list

; BONUS LABS
global ex_isort, ex_qsort


find_largest:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This function takes two arguments:
;  - Arg1: A pointer to an array of integers
;  - Arg2: The number of integers in the array
;
;  Find and return the largest element in the array.
;  
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;doing this lab, register size needed to match the value being
;grabbed from the array [In this case, 32-bit register]
;rdi : pointer to array
;rsi : size of array
xor eax, eax ; will be used to track largest number
xor rcx, rcx

.loop_start:
cmp rcx, rsi
jge .loop_end

cmp eax, [rdi + rcx * 4]
jge .inc
mov eax, [rdi + rcx * 4]
.inc:
inc rcx
jmp .loop_start
.loop_end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strlen:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  size_t strlen(char*);  
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : string buffer

xor ecx, ecx
xor eax, eax
not ecx
cld
repne scasb
not ecx
mov eax, ecx
dec eax

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memcpy:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  void memcpy(void* dst, void* src, int count);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : destination buffer
;rsi : source buffer
;rdx : length
xor rcx, rcx
mov rcx, rdx

rep movsb
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_memset:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	void memset(void* buf, unsigned char value, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : destination buffer
;rsi : character to be initialize the buffer
;rdx : length of the buffer
xor rcx, rcx
xor rax, rax
mov rcx, rdx
mov rax, rsi

rep stosb
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memchr:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	void* memchr(void* haystack, unsigned char needle, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : buffer to be searched
;rsi : value to search for
;rdx : how many bytes to search

xor rcx, rcx
xor rax, rax
mov rcx, rdx
mov rax, rsi

repne scasb
jne .notfound
lea rax, [rdi - 1]
jmp .end

.notfound:
xor rax, rax

.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memcmp:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	int memcmp(void*, void*, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : input buffer 1
;rsi : input buffer 2
;rdx : provided length

xor rcx, rcx
mov rcx, rdx

cld
cmp rcx, rcx
rep cmpsb
je .set
jmp .end

.set:
mov rax, 0
.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strchr:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;        const char * strchr ( const char * str, int character )
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : buffer to be searched
;rsi : search character
xor rax, rax
push rdi
mov rax, rdi
call ex_strlen
xor rcx, rcx
mov rcx, rax
pop rdi
cld
xor rax, rax
mov rax, rsi
repne scasb
jne .set
mov rax, rdi
dec rax
jmp .end
.set:
mov rax, 0
.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strcmp:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;            int strcmp ( const char * str1, const char * str2 )
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : first string
;rsi : second string
xor rax, rax
push rdi
mov rax, rdi
call ex_strlen
xor rcx, rcx
mov rcx, rax
pop rdi
cld
cmp rcx, rcx
rep cmpsb
je .set
jg .neg
mov rax, 1
jmp .end

.neg:
mov rax, -1
jmp .end
.set:
mov rax, 0
.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strcpy:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;           char * strcpy ( char * destination, const char * source )
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : destination buffer
;rsi : source buffer
xor rax, rax
xor r8, r8
mov r8, rdi
xor rdi, rdi
mov rdi, rsi
call ex_strlen
xor rcx, rcx
mov rcx, rax
xor rdi, rdi
mov rdi, r8
cld
cmp rcx, rcx
rep movsb
xor rax, rax
stosb
mov rax, r8
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  |-- |      |--- |    |\     |    |   |   |-------
;  |   |      |    |    | \    |    |   |   |
;  |---- |    |    |    |  \   |    |   |   |_______
;  |     |    |    |    |   \  |    |   |           |
;  |     |    |    |    |    \ |    |   |           |
;  |____ |    |___ |    |     \|    |___|   ________|
;
;
;        |           |------ |   |------ |     |-------
;        |           |       |   |       |     |_______
;        |           |------ |   |-------- |           |
;        |           |       |   |         |           |
;        |_______    |       |   |_________|   ________|
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


ex_atoi:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;             int atoi (const char * str)
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : string pointer
xor rax, rax        ; The sum register is zero'd
push rdi            ; Address of the string needs to be stored while length function is called
call ex_strlen      ; Length of provided string is computed and returned in rax
pop rdi             ; Address of string is put back into RDI

mov rsi, rax        ; RSI will store the length of the string (The bounds for the function)
dec rsi
xor rcx, rcx        ; RCX will be the counter, starting at 0
xor rax, rax        ; The sum register is reset, to be able to store the value of the string

.loop_start:        ; Loop to evaluate each byte of the string
mov bl, [rdi + rcx] ; The byte at index [rcx] is stored into a 8-bit register
cmp bl, 32          ; Checks if the byte is whitespace (ASCII # 32), 
                    ; if so then the next character needs to be checked
je .loop_start
cmp bl, 57          ; Checks if the byte is above the range of the numbers 0-9
jg .undefined       ; If so, jump to the undefined section
sub bl, 48          ; Subtracts the value down to 0-9
cmp bl, 0           ; Checks to see if the value is below zero, if so, not a number
jl .undefined
movzx rbx, bl       ; Changes the register size so that the value can be saved into rax
                    ; Assumption from here on is that value is an int
push rax            ; Need to save the previous stored sum
xor r8, r8          ; R8 will be used as the factor value to multiple by 10
mov r8, rsi         
mov rax, 1          ; Default factor multiplier 
sub r8, rcx         
cmp r8, 0           ; Checks to see RCX is 0, if so, then 10 will need to be multipled by 1
jne .set
jmp .multi          ; If the factor is 1, then the value needs to be multipled
.set:
mov rdx, 10         ; Multiple the factor by 10
mul rdx             ; R8 - RCX * 10
dec r8
cmp r8, 0
jne .set
.multi:             ; Factor has been computed
mul rbx             ; Multiple the value of RBX * RAX
mov rbx, rax
pop rax             ; Return the previously stored sum
add rax, rbx        ; Add the computed byte value
inc rcx             ; Loop is complete, increment the counter
cmp rcx, rsi        ; See if the counter is equal to the size of the string
jg .end
jmp .loop_start

.undefined:         ; This section handles if the value of the byte is not an int
                    ; RAX is set to 0 and returned
xor rax, rax
.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_strstr:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;           const char * strstr ( const char * str1, const char * str2 )     
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;rdi : Full string buffer to be looked through 
;rsi : Needle string to be looked for
.prep:
xor rax, rax         ; Used at the start to compute length of string buffer
call ex_strlen       ; Computes the length of string
xor rcx, rcx
;rax                 ; Length of string

;Look for cmpsb of [rcx] for buffer and needle to be 0

.loop_string:
push rdi
push rsi
push rax



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


struc Node
	.Next	resq	1
	.Data	resq	1
endstruc

 walk_list:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ret


ex_isort:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  insertion_sort.c is provided
;  to give an example implementation.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_qsort:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret
