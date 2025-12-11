	.file	"char_asm.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "x = '%c' (%d)\12\0"
LC1:
	.ascii "y = '%c' (%d)\12\0"
LC2:
	.ascii "z = y + 3 = '%c' (%d)\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
/APP
 # 12 ".\char_asm.c" 1
	movb $65, 31(%esp)
movb $66, 30(%esp)
movb 30(%esp), %al
addb $3, %al
movb %al, 29(%esp)

 # 0 "" 2
/NO_APP
	movzbl	31(%esp), %eax
	movsbl	%al, %edx
	movzbl	31(%esp), %eax
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movzbl	30(%esp), %eax
	movsbl	%al, %edx
	movzbl	30(%esp), %eax
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movzbl	29(%esp), %eax
	movsbl	%al, %edx
	movzbl	29(%esp), %eax
	movsbl	%al, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
