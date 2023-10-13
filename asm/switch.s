	.file	"switch.c"
	.text
	.p2align 4
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	cmpq	$5, %rsi
	ja	.L9
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rsi,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L9-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rdi, %rax
	imulq	%rdi, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	leaq	2(%rdi), %rax
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	leaq	-3(%rdi), %rax
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movq	%rdi, %rax
	salq	$8, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L5:
	movabsq	$6148914691236517206, %rax
	movq	%rdi, %rcx
	imulq	%rdi
	sarq	$63, %rcx
	movq	%rdx, %rax
	subq	%rcx, %rax
	ret
.L9:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
