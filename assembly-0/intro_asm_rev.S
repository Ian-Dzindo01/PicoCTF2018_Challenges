.intel_syntax noprefix
.bits 32
	
.global asm0

asm0:							  # function prologue
	push	ebp                   # push the base pointer
	mov	ebp,esp					  # push the stack pointer
	mov	eax,DWORD PTR [ebp+0x8]   # eax = first argument 
	mov	ebx,DWORD PTR [ebp+0xc]	  # ebx = second argument
	mov	eax,ebx					  # eax = ebx = 0x4f
	mov	esp,ebp					  # function epilogue
	pop	ebp	
	ret

#asm0(0x2a, 0x4f)

#----------------------

#argument variables     # +8 from the base pointer

#return address			# +4 from the base pointer

#ebp					# base pointer

#local variables

#----------------------