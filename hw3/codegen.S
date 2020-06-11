.global codegen
codegen:
	sw fp, -4(sp)
	sw ra, -8(sp)
	addi sp, sp, -8

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 2
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	mul t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	add t0, t0, t1
	addi sp, sp, -4
	sw t0, 0(sp)

	sw  t0, -12(fp) 

	lw  t0, -12(fp) 
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 3
	addi sp, sp, -4
	sw t0, 0(sp)

	lw t0, 0(sp)
	addi sp, sp, 4
	lw t1, 0(sp)
	addi sp, sp, 4
	add t0, t0, t1
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

	sw  t0, -16(fp) 

	li t0, 26
	addi sp, sp, -4
	sw t0, 0(sp)

	li t0, 1
	addi sp, sp, -4
	sw t0, 0(sp)

	lw a0, 0(sp)
	addi sp, sp, 4
	lw a1, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, digitalWrite
	lw ra, 0(sp)
	addi sp, sp, 4

	lw  t0, -12(fp) 
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

	lw a0, 0(sp)
	addi sp, sp, 4
	lw a1, 0(sp)
	addi sp, sp, 4
	sw ra, -4(sp)
	addi sp, sp, -4
	jal ra, digitalWrite
	lw ra, 0(sp)
	addi sp, sp, 4

	lw  t0, -16(fp) 
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

	lw ra, -4(fp)
	lw fp, 0(fp)
	addi sp, sp, 8
