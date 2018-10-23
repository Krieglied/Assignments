;Name: Robert John Graham III
;Date: 23 Oct 2018
;Project: Wednesday
;
; vim: filetype=nasm :


bits 32

global _sum_array@8, _find_largest

section .text


_sum_array@8:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes two parameters:
;
;	Param 1: A pointer to a buffer of integers (4 bytes/each).
;
;	Param 2: A number indicating the number of elements in the buffer.
;
;	You must:
;	1.) Walk through the buffer, and sum together all of the elements
;	2.) Return the result
;
;	int __stdcall sum_array(int* buffer, int size);
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
;esi = [esp + 4] : pointer to array
;edx = [esp + 8] : length of array

xor eax, eax ; sum of values
xor ecx, ecx
xor edx, edx
xor esi, esi
mov esi, [esp + 4]
mov edx, [esp + 8]

.loop_start:
cmp ecx, edx
jge .loop_end

add eax, [esi + ecx * 4]
inc ecx
jmp .loop_start
.loop_end:
ret 8
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;


_find_largest:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This function takes two
;	parameters:
;
;	Param 1: A pointer to a buffer of integers (4 bytes/each)
;
;	Param 2: A number indicating the number of elements in the
;	buffer.
;
;	Your task is to:
;	1.) Walk through the buffer, locating the largest element
;	2.) Return it as the result.	
;
;	int __cdecl find_largest(unsigned long* buffer, int size)
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
;edi = [esp + 4] : pointer to array
;esi = [esp + 8] : size of array


xor eax, eax ; will be used to track largest number
xor ecx, ecx

xor edi, edi
xor esi, esi
mov edi, [esp + 4]
mov esi, [esp + 8]

.loop_start:
cmp ecx, esi
jge .loop_end

cmp eax, [edi + ecx * 4]
jge .inc
mov eax, [edi + ecx * 4]
.inc:
inc ecx
jmp .loop_start
.loop_end:
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
