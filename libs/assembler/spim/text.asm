
	USER TEXT SEGMENT
[0x00400000]	0x8fa40000  lw $4, 0($29)                   ; 183: lw $a0 0($sp)		# argc
[0x00400004]	0x27a50004  addiu $5, $29, 4                ; 184: addiu $a1 $sp 4		# argv
[0x00400008]	0x24a60004  addiu $6, $5, 4                 ; 185: addiu $a2 $a1 4		# envp
[0x0040000c]	0x00041080  sll $2, $4, 2                   ; 186: sll $v0 $a0 2
[0x00400010]	0x00c23021  addu $6, $6, $2                 ; 187: addu $a2 $a2 $v0
[0x00400014]	0x0c100009  jal 0x00400024 [main]           ; 188: jal main
[0x00400018]	0x00000000  nop                             ; 189: nop
[0x0040001c]	0x3402000a  ori $2, $0, 10                  ; 191: li $v0 10
[0x00400020]	0x0000000c  syscall                         ; 192: syscall			# syscall 10 (exit)
[0x00400024]	0x34020004  ori $2, $0, 4                   ; 62: li $v0, 4	# syscall 4 (print_str)
[0x00400028]	0x3c011000  lui $1, 4096 [msg]              ; 63: la $a0, msg	# argument: string
[0x0040002c]	0x3424e010  ori $4, $1, -8176 [msg]
[0x00400030]	0x0000000c  syscall                         ; 64: syscall		# print the string
[0x00400034]	0x00000000  nop                             ; 65: nop
[0x00400038]	0x8f898000  lw $9, -32768($28)              ; 66: lw $t1, foobar
[0x0040003c]	0x3c0a1001  lui $10, 4097                   ; 67: li $t2, 0x10010000
[0x00400040]	0xad490000  sw $9, 0($10)                   ; 68: sw $t1, 0($t2)
[0x00400044]	0x2005000a  addi $5, $0, 10                 ; 69: addi $a1, $zero, 10
[0x00400048]	0x23bdfffc  addi $29, $29, -4               ; 71: addi $sp, $sp, -4
[0x0040004c]	0xafbf0000  sw $31, 0($29)                  ; 72: sw $ra, 0($sp)
[0x00400050]	0x23bdfffc  addi $29, $29, -4               ; 73: addi $sp, $sp, -4
[0x00400054]	0xafa50000  sw $5, 0($29)                   ; 74: sw $a1, 0($sp)
[0x00400058]	0x8fa60000  lw $6, 0($29)                   ; 76: lw $a2, 0($sp)
[0x0040005c]	0x23bd0004  addi $29, $29, 4                ; 77: addi $sp, $sp, 4
[0x00400060]	0x8fa70000  lw $7, 0($29)                   ; 78: lw $a3, 0($sp)
[0x00400064]	0x23bd0004  addi $29, $29, 4                ; 79: addi $sp, $sp, 4
[0x00400068]	0x03e00008  jr $31                          ; 81: jr $ra  # retrun to caller
