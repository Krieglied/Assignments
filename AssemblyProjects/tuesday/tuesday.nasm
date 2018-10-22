;Name: Robert John Graham III
;Date: 22 Oct 2018
;Project: Tuesday
;
; vim: filetype=nasm :
bits 32

global _copy_string, _get_cpu_string@4, _set_flags

section .text


_copy_string:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes 2 params:
;
;	Param 1: An empty buffer
;
;	Param 2: A NULL-terminated string
;
;	Given these two inputs, 
;	1.) Find the length of the string provided in
;	param 2
;	2.) Copy the string from param 2, to the empty buffer
;	provided in param 1.
;
;	void __cdecl copy_string(char* dest, char* src);
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
mov edx, [esp + 4] ; Empty Buffer
mov edi, [esp + 8] ; Null-terminated string
mov esi, [esp + 8] ; Copy of null-terminated string

xor ecx, ecx
xor eax, eax
not ecx
cld
repne scasb
not ecx
mov edi, edx

rep movsb

mov eax, edi
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;

_get_cpu_string@4:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This function takes 1 param:
;
;	Param 1: A zero'd character buffer, containing
;	13 elements.
;
;	The following steps must be performed:
;	1.) Call CPUID and get the vendor string
;	2.) Copy from ASCII bytes returned into the buffer
;	provided.
;	
;	void __stdcall get_cpu_string(char* buf);
;
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
mov edi, [esp + 4] ; character buffer
xor eax, eax
xor ebx, ebx
xor ecx, ecx
xor edx, edx
cpuid
mov [edi], ebx
mov [edi + 4], edx
mov [edi + 8], ecx
xor eax, eax
mov [edi + 12], eax

ret 4
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
