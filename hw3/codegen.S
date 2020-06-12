.global codegen
codegen:
	sw s0, -4(sp)
	addi sp, sp, -4
	addi s0, sp, 0
	sw sp, -4(s0)
	sw s1, -8(s0)
	sw s2, -12(s0)
	sw s3, -16(s0)
	sw s4, -20(s0)
	sw s5, -24(s0)
	sw s6, -28(s0)
	sw s7, -32(s0)
	sw s8, -36(s0)
	sw s9, -40(s0)
	sw s10, -44(s0)
	sw s11, -48(s0)
	addi sp, s0, -48

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 2
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	add t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 7
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	mul t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	sub t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 2
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	div t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw  t0, -52(s0) 
	addi sp, sp, -4
	sw t0, 0(sp)

Loop:
	li t0, 26
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw a1, 0(sp)
	addi sp, sp, 4
	lw a0, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, digitalWrite
	lw ra, 0(sp)
	addi sp, sp, 4

	li t0, 10
	addi sp, sp, -4
	sw t0, 0(sp)

	lw  t0, -52(s0) 
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	sub t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	add t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1000
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	mul t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw a0, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, delay
	lw ra, 0(sp)
	addi sp, sp, 4

	li t0, 26
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 0
	addi sp, sp, -4
	sw t0, 0(sp)

	lw a1, 0(sp)
	addi sp, sp, 4
	lw a0, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, digitalWrite
	lw ra, 0(sp)
	addi sp, sp, 4

	lw  t0, -52(s0) 
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	sub t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1000
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	mul t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw a0, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, delay
	lw ra, 0(sp)
	addi sp, sp, 4

	beq , , Loop	lw s11, -48(s0)
	lw s10, -44(s0)
	lw s9, -40(s0)
	lw s8, -36(s0)
	lw s7, -32(s0)
	lw s6, -28(s0)
	lw s5, -24(s0)
	lw s4, -20(s0)
	lw s3, -16(s0)
	lw s2, -12(s0)
	lw s1, -8(s0)
	lw sp, -4(s0)
	addi sp, sp, 4
	lw s0, -4(sp)

	jalr zero, 0(ra)
