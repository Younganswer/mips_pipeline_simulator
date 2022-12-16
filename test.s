.data 0x10008000
var1:	.word 0x11111111
var2:	.word 0x22222222
var3:	.word 3
var4:	.word 4
var5:	.word 5
var6:	.word 6
		.data 0x1000a004
var7:	.word 7
var8:	.word 8
var9:	.word 9
var10:	.word 10
		.data 0x1000c000
var11:	.word 11
var12:	.word 12
var13:	.word 13
var14:	.word 14
		.data 0x1000e000
var15:	.word 15
var16:	.word 16
var17:	.word 17
var18:	.word 18
var19:	.word 19
var20:	.word 20
var21:	.word 21
var22:	.word 22
var23:	.word 23
var24:	.word 24
var25:	.word 25
var26:	.word 26
var27:	.word 27
var28:	.word 28
var29:	.word 29
var30:	.word 30
var31:	.word 31
var32:	.word 32
var33:	.word 33
var34:	.word 34
var35:	.word 35

.text 0x00400024
.globl main

main:
	lw	$t0, 0($gp)
	lw	$t1, 4($gp)