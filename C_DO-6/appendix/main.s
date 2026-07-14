	.file	"main.c"
	.text
	.section	.rodata
.LC24:
	.string	"========== char =========="
	.align 8
.LC25:
	.string	"\n========== signed char =========="
	.align 8
.LC26:
	.string	"\n========== unsigned char =========="
	.align 8
.LC27:
	.string	"\n========== signed short =========="
	.align 8
.LC28:
	.string	"\n========== unsigned short =========="
.LC29:
	.string	"\n========== int =========="
	.align 8
.LC30:
	.string	"\n========== signed int =========="
	.align 8
.LC31:
	.string	"\n========== unsigned int =========="
	.align 8
.LC32:
	.string	"\n========== signed long =========="
	.align 8
.LC33:
	.string	"\n========== unsigned long =========="
	.align 8
.LC34:
	.string	"\n========== signed long long =========="
	.align 8
.LC35:
	.string	"\n========== unsigned long long =========="
.LC36:
	.string	"\n========== float =========="
.LC37:
	.string	"\n========== double =========="
	.align 8
.LC38:
	.string	"\n========== long double =========="
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$640, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$6504659406362926939, %rax
	movq	%rax, -32(%rbp)
	movabsq	$4542393829698453492, %rax
	movq	%rax, -24(%rbp)
	movabsq	$-972999103809644073, %rax
	movq	%rax, -16(%rbp)
	movw	$-1234, -640(%rbp)
	movw	$501, -638(%rbp)
	movw	$500, -636(%rbp)
	movw	$325, -634(%rbp)
	movw	$450, -632(%rbp)
	movw	$-678, -630(%rbp)
	movw	$668, -628(%rbp)
	movw	$2000, -626(%rbp)
	movw	$5432, -624(%rbp)
	movw	$2423, -622(%rbp)
	movw	$2500, -620(%rbp)
	movw	$876, -618(%rbp)
	movw	$1200, -616(%rbp)
	movw	$3456, -614(%rbp)
	movw	$511, -612(%rbp)
	movw	$4660, -610(%rbp)
	movl	$-98765, -608(%rbp)
	movl	$5349, -604(%rbp)
	movl	$43981, -600(%rbp)
	movl	$45678, -596(%rbp)
	movl	$78900, -592(%rbp)
	movl	$-54321, -588(%rbp)
	movl	$4012, -584(%rbp)
	movl	$4660, -580(%rbp)
	movl	$-123456, -576(%rbp)
	movl	$5349, -572(%rbp)
	movl	$43981, -568(%rbp)
	movl	$45678, -564(%rbp)
	movl	$98700, -560(%rbp)
	movl	$-654321, -556(%rbp)
	movl	$32099, -552(%rbp)
	movl	$74565, -548(%rbp)
	movl	$987654, -544(%rbp)
	movl	$256794, -540(%rbp)
	movl	$703710, -536(%rbp)
	movl	$54321, -532(%rbp)
	movl	$654000, -528(%rbp)
	movl	$123456, -524(%rbp)
	movl	$42798, -520(%rbp)
	movl	$1043915, -516(%rbp)
	movq	$-1234567, -480(%rbp)
	movq	$342391, -472(%rbp)
	movq	$703710, -464(%rbp)
	movq	$765432, -456(%rbp)
	movq	$1230000, -448(%rbp)
	movq	$-7654321, -440(%rbp)
	movq	$2054353, -432(%rbp)
	movq	$1043915, -424(%rbp)
	movq	$3456789, -416(%rbp)
	movq	$154707, -408(%rbp)
	movq	$1193046, -400(%rbp)
	movq	$876543, -392(%rbp)
	movq	$2340000, -384(%rbp)
	movq	$9876543, -376(%rbp)
	movq	$256794, -368(%rbp)
	movq	$11259375, -360(%rbp)
	movq	$-123456789, -352(%rbp)
	movq	$2739128, -344(%rbp)
	movq	$305419896, -336(%rbp)
	movq	$9876543, -328(%rbp)
	movq	$56700000, -320(%rbp)
	movq	$-987654321, -312(%rbp)
	movq	$16434824, -304(%rbp)
	movl	$2882400018, %eax
	movq	%rax, -296(%rbp)
	movq	$123456789, -288(%rbp)
	movq	$16434824, -280(%rbp)
	movl	$4275878552, %eax
	movq	%rax, -272(%rbp)
	movq	$7654321, -264(%rbp)
	movq	$89100000, -256(%rbp)
	movq	$987654321, -248(%rbp)
	movq	$2739128, -240(%rbp)
	movq	$305441741, -232(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -512(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -508(%rbp)
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, -504(%rbp)
	movss	.LC3(%rip), %xmm0
	movss	%xmm0, -500(%rbp)
	movss	.LC4(%rip), %xmm0
	movss	%xmm0, -496(%rbp)
	movss	.LC5(%rip), %xmm0
	movss	%xmm0, -492(%rbp)
	movss	.LC6(%rip), %xmm0
	movss	%xmm0, -488(%rbp)
	movss	.LC7(%rip), %xmm0
	movss	%xmm0, -484(%rbp)
	movsd	.LC8(%rip), %xmm0
	movsd	%xmm0, -224(%rbp)
	movsd	.LC9(%rip), %xmm0
	movsd	%xmm0, -216(%rbp)
	movsd	.LC10(%rip), %xmm0
	movsd	%xmm0, -208(%rbp)
	movsd	.LC11(%rip), %xmm0
	movsd	%xmm0, -200(%rbp)
	movsd	.LC12(%rip), %xmm0
	movsd	%xmm0, -192(%rbp)
	movsd	.LC13(%rip), %xmm0
	movsd	%xmm0, -184(%rbp)
	movsd	.LC14(%rip), %xmm0
	movsd	%xmm0, -176(%rbp)
	movsd	.LC15(%rip), %xmm0
	movsd	%xmm0, -168(%rbp)
	fldt	.LC16(%rip)
	fstpt	-160(%rbp)
	fldt	.LC17(%rip)
	fstpt	-144(%rbp)
	fldt	.LC18(%rip)
	fstpt	-128(%rbp)
	fldt	.LC19(%rip)
	fstpt	-112(%rbp)
	fldt	.LC20(%rip)
	fstpt	-96(%rbp)
	fldt	.LC21(%rip)
	fstpt	-80(%rbp)
	fldt	.LC22(%rip)
	fstpt	-64(%rbp)
	fldt	.LC23(%rip)
	fstpt	-48(%rbp)
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-32(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_char_array@PLT
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-24(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_signed_char_array@PLT
	leaq	.LC26(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-16(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_unsigned_char_array@PLT
	leaq	.LC27(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-640(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_signed_short_array@PLT
	leaq	.LC28(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-624(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_unsigned_short_array@PLT
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-608(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_int_array@PLT
	leaq	.LC30(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-576(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_signed_int_array@PLT
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-544(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_unsigned_int_array@PLT
	leaq	.LC32(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-480(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_signed_long_array@PLT
	leaq	.LC33(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-416(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_unsigned_long_array@PLT
	leaq	.LC34(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-352(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_signed_long_long_array@PLT
	leaq	.LC35(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-288(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_unsigned_long_long_array@PLT
	leaq	.LC36(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-512(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_float_array@PLT
	leaq	.LC37(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-224(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_double_array@PLT
	leaq	.LC38(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-160(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	print_long_double_array@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1095069860
	.align 4
.LC1:
	.long	1113792184
	.align 4
.LC2:
	.long	1103626240
	.align 4
.LC3:
	.long	1119253955
	.align 4
.LC4:
	.long	1139015680
	.align 4
.LC5:
	.long	1117639148
	.align 4
.LC6:
	.long	1102813594
	.align 4
.LC7:
	.long	1116194734
	.align 8
.LC8:
	.long	446676599
	.long	1079958831
	.align 8
.LC9:
	.long	-1821066134
	.long	1082697752
	.align 8
.LC10:
	.long	0
	.long	1078591488
	.align 8
.LC11:
	.long	-1099511628
	.long	1081904287
	.align 8
.LC12:
	.long	0
	.long	1084822528
	.align 8
.LC13:
	.long	1752346657
	.long	1082421905
	.align 8
.LC14:
	.long	1683627180
	.long	1083104571
	.align 8
.LC15:
	.long	1065151889
	.long	1079758389
	.align 16
.LC16:
	.long	-927712936
	.long	-1601192330
	.long	16391
	.long	0
	.align 16
.LC17:
	.long	-1614907703
	.long	-1549979878
	.long	16392
	.long	0
	.align 16
.LC18:
	.long	-618475291
	.long	-151879943
	.long	16392
	.long	0
	.align 16
.LC19:
	.long	-412316860
	.long	-562976261
	.long	16389
	.long	0
	.align 16
.LC20:
	.long	0
	.long	-158334976
	.long	16395
	.long	0
	.align 16
.LC21:
	.long	-206158430
	.long	-1497836291
	.long	16391
	.long	0
	.align 16
.LC22:
	.long	1992864825
	.long	-1964335170
	.long	16392
	.long	0
	.align 16
.LC23:
	.long	-206158430
	.long	-1032268547
	.long	16392
	.long	0
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
