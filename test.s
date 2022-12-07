# helloworld.s
#
# Print out "Hello World"
#
# Copyright (c) 2013, James R. Larus.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation and/or
# other materials provided with the distribution.
#
# Neither the name of the James R. Larus nor the names of its contributors may be
# used to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

		.data 0x10008000
var1:	.word 0x12345678
var2:	.word 0x9abcdef0
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

msg:	.asciiz "Hello World\n"
		.extern foobar 4

		.text 0x00400024
		.globl main
main:   li $v0, 4	# syscall 4 (print_str)
		la $a0, msg	# argument: string
		syscall		# print the string
		lw $t1, foobar
		li $t2, 0x10010000
		sw $t1, 0($t2)

		jr $ra  # retrun to caller
