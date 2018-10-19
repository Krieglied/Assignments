;Name: Robert John Graham III
;Date: 18 Oct 2018
;Project: Monday Windows Lab
;
; vim: filetype=nasm :

bits 32

global _unpack_string@12, @walk_list@8, _call_function

section .text


_unpack_string@12:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;	This function takes three params:
;
;  Param 1: A string of unsigned characters, all of which have been left
;  shifted 1 bit
;
;  Param 2: An empty, NULL-terminated character string
;
;  Param 3: A size indicating the number of bytes each string can hold.
;
;  This function simply needs to:
;	1.) Walk the first string, loading each byte
;	2.) Right-shift the value retrieved
;	3.) Store the result in the destination string
;
;	void __stdcall unpack_string(unsigned char* input, char* output, size_t length);
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
;rcx = A string of unsigned characters, all of which have been left shifted 1 bit
;[ebp + 8]
;rdx = An empty, NULL-terminated character string
;[ebp + 12]
;r8 = A size indicating the number of bytes each string can hold.
;[ebp + 16]
push ebp
mov ebp, esp

xor eax, eax
xor esi, esi
xor ecx, ecx
xor edi, edi
mov esi, [ebp + 8]
mov ecx, [ebp + 16]
mov edi, [ebp + 12]
.continue:
lodsb
shr eax, 1
stosb
xor eax, eax
loop .continue

pop ebp 
ret 12

;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;


struc Node
	.Next	resd  1
	.Data	resd  1
endstruc

@walk_list@8:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;	This function takes 2 parameters:
;	
;	Param 1: A pointer to the beginning of a linked list of nodes (
;   structure definition given above), which is NULL-terminated (e.g., the
;   last Next pointer is NULL).
;
;	Param 2: A needle to search for within the list.
;
;	Walk the list, searching each Node for the needle (in Node.Data), and either:
;	1.) Return the node where you found the value
;	2.) Return NULL if the value cannot be found
;
;   Node* __fastcall walk_list(Node* start, size_t needle);
;
;	HINTS:
;	-Notice the struc Node on line 46
;	-Think back to these Nodes... what are they? 
;	-Take a look at main.cpp and note which is the next node
;	-Remember... the next sequential address you need is given to you... this isn't like itterating through arrays
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
;ecx = A pointer to the beginning of a linked list of nodes
; -> Once you're walking the nodes
; -> [edi + Node.Next] = next Node
; -> [edi + Node.Data] = data
;edx = A needle to search for within the list.
.main:
push ebp
mov ebp, esp

xor eax, eax
xor edi, edi
xor esi, esi
mov edi, [ecx] ; address of Node
.nextNode:
mov eax, [edi + Node.Data] ; data
cmp eax, edx ; if needle == data
je .found
mov edi, [edi + Node.Next]
cmp edi, 0
je .null
jmp .nextNode
.found:
mov eax, edi
jmp .end
.null:
xor eax, eax

.end:
pop ebp 
ret
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;

extern _first_func@0
extern _test_func

_call_function:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This function takes no parameters.
;
; Using the two extern'd in functions (above):
;
;	_first_func@0 -> int __stdcall first_func();
;	_test_func -> int __cdecl test_func(int);
;
;	1.) Call _first_func@0
;	2.) Take the result from the first function call,
;	and pass it as a parameter to _test_func
;	3.) Return the result.
;
;	 int __cdecl call_function();
;	
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
xor eax, eax
call _first_func@0
push eax
call _test_func
pop edx
ret

;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
