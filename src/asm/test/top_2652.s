	.name "zork"
	.comment "just a basic living prog"

l2:	 sti r1,%:live,%1
	and r1,%0,r1
	fork %:prog
live:	 live %100
	fork %:protekfion
	zjmp %:live

attack:	 live %1
	ld      %425,r2
	ld      %0,r3
	ld      %4,r4
	sub     r3,r8,r3
	ld      %0,r11
	ld      %0,r11
	ld %200, r13
	fork %:attack
	zjmp %:protekfion

arriere:		ld	%-5, r5
	ld	%1024,r4

arriere2:		ld	%-5, r3

prog:	 ld %400, r2
	fork %:protekfion
	ld %200,r6
	ld %400,r3
	ld      %0,r15
	fork    %:prog
	live    %1
	ld %:arriere, r8
	zjmp %:prog

protekfion:	      live	%200
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-300
	st	r8,-400
	st	r8,-600
	st	r8,-400
	st	r8,-600
	st	r8,-400
	st	r8,-600
	st	r8,-400
	st	r8,-600
	st	r8,-400
	st	r8,-600
	st	r8,-400
	st	r8,-600
	st	r8,-400
	live %200
	fork %:protekfion
	zjmp    %:attack
