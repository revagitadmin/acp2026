	.file	"demo4.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Enter flight number : \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "Enter destination: \0"
.LC3:
	.ascii "%s\0"
.LC4:
	.ascii "Enter available seats: \0"
	.text
	.globl	readFlights
	.def	readFlights;	.scl	2;	.type	32;	.endef
	.seh_proc	readFlights
readFlights:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	-4(%rbp), %eax
	cltq
	imulq	$60, %rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_scanf
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	-4(%rbp), %eax
	cltq
	imulq	$60, %rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	leaq	4(%rax), %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_scanf
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	-4(%rbp), %eax
	cltq
	imulq	$60, %rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	leaq	56(%rax), %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_scanf
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jl	.L3
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC5:
	.ascii "Flight available. Flight Number: %d\12\0"
	.align 8
.LC6:
	.ascii "The flights are not available for the destination\0"
	.text
	.globl	searchByDestination
	.def	searchByDestination;	.scl	2;	.type	32;	.endef
	.seh_proc	searchByDestination
searchByDestination:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L7:
	movl	-4(%rbp), %eax
	cltq
	imulq	$60, %rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	leaq	4(%rax), %rcx
	movq	32(%rbp), %rax
	movq	%rax, %rdx
	call	strcmp
	testl	%eax, %eax
	jne	.L6
	movl	-4(%rbp), %eax
	cltq
	imulq	$60, %rax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leaq	.LC5(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	movl	$1, -8(%rbp)
.L6:
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jl	.L7
	cmpl	$0, -8(%rbp)
	jne	.L9
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L9:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC7:
	.ascii "Enter the destination to go : \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$352, %rsp
	.seh_stackalloc	352
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$4, 220(%rbp)
	leaq	-32(%rbp), %rdx
	movl	220(%rbp), %eax
	movl	%eax, %ecx
	call	readFlights
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	leaq	-96(%rbp), %rax
	leaq	.LC3(%rip), %rcx
	movq	%rax, %rdx
	call	__mingw_scanf
	leaq	-96(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	movl	220(%rbp), %eax
	movq	%rcx, %r8
	movl	%eax, %ecx
	call	searchByDestination
	movl	$0, %eax
	addq	$352, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
