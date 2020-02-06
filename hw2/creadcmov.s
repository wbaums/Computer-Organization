	.file	"creadcmov.c"
	.text
	.p2align 4,,15
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	testq	%rdi, %rdi
	movl	$ret, %edx
	movq	$-8, %rax
	cmovne	%rdx, %rax
	movq	(%rax), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.globl	ret
	.data
	.align 8
	.type	ret, @object
	.size	ret, 8
ret:
	.quad	-1
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
