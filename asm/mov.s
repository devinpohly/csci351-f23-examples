	.file	"mov.c"
	.text
	.globl	test1
	.type	test1, @function
test1:
.LFB11:
	.cfi_startproc
	// %rdi = x
	imulq $10, %rdi
	movq %rdi, %rax
	// %rax = x + 10
	ret
	.cfi_endproc
.LFE11:
	.size	test1, .-test1
	.globl	swap
	.type	swap, @function
swap:
.LFB12:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE12:
	.size	swap, .-swap
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	movl	$10, %edi
	call	test1
	movq	%rax, 8(%rsp)
	movq	$-1, 16(%rsp)
	leaq	16(%rsp), %rsi
	leaq	8(%rsp), %rdi
	call	swap
	movq	8(%rsp), %rsi
	leaq	.LC0(%rip), %rbx
	movq	%rbx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	16(%rsp), %rsi
	movq	%rbx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	24(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L6
	movl	$0, %eax
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits
