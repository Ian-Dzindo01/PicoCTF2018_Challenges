.intel_syntax noprefix
.bits 32
	
.global asm0

asm0:							  # function prologue
	push	ebp                   # push the base pointer
	mov	ebp,esp					  # push the stack pointer
	mov	eax,DWORD PTR [ebp+0x8]
	mov	ebx,DWORD PTR [ebp+0xc]
	mov	eax,ebx
	mov	esp,ebp
	pop	ebp	
	ret
