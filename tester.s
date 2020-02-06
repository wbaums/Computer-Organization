	.file	"tester.c"
	.text
	.p2align 4,,15
	.globl	for_loop
	.type	for_loop, @function
for_loop:
.LFB11:
	.cfi_startproc
	testl	%edi, %edi
	jle	.L4
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	addl	%edx, %eax
	addl	$1, %edx
	cmpl	%edi, %edx
	jne	.L3
	rep ret
.L4:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	for_loop, .-for_loop
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
