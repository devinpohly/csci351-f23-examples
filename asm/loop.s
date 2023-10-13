	.file	"loop.c"
	.text
	.globl	loop
	.type	loop, @function
loop:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	jmp	.L2
.L3:
	subq	$1, %rax
.L2:
	testq	%rax, %rax
	jne	.L3
	ret
	.cfi_endproc
.LFE0:
	.size	loop, .-loop
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
