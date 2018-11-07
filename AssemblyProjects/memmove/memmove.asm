bits 32

section .text

global _movememory

; This task is similar to memcopy but with one important exception: it must 
; be able to handle overlapped memory copies (just like memmove). That is to say, it has to be able
; to perform a copy where the source and destination overlap. This means that the copy either needs
; to happen in reverse, or a buffer must be used.
;
; void __cdecl movememory(void* dest, void* src, size_t length)
_movememory:
	push ebp
	mov ebp, esp

	push edi
	push esi
	push ebx

	mov edi, [ebp+0x8]	;dest
	mov esi, [ebp+0xc]	;src
	mov ecx, [ebp+0x10]	;length

	;// code begin //
	;int3
	xor edx, edx
	mov edx, esi     ; stores source_addr
	cmp esi, edi     ; compare source_addr (minuend), dst_addr (subtrahend)
	jl .reverse_move ; if minuend < subtrahend
	repne movsb      ; if minuend > subtrahend, then just move
	jmp .end
	.reverse_move:
	push edi         ; save the original address of the destination
	push esi         ; save the original address of the source
	add esi, ecx     ; use the address of source + counter
	add edi, ecx     ; use the address of dst + counter
	xor eax, eax
	lodsb            ; save value of source[counter] into eax
	stosb            ; load value into dst[counter]
	dec ecx          ; counter--
	pop esi          ; restore source address
	pop edi          ; restore destination address
	cmp ecx, 0       ; once counter is less than 0, loop is over
	jge .reverse_move
	.end:
	mov eax, edi     ; return eax register
	;//  code end  //

	pop edi
	pop esi
	pop ebx

	mov esp, ebp
	pop ebp

	ret
