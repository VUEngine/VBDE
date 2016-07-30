	.file	"CannonBallIdle.c"
	.section .text
	.align 2
	.global _CannonBallIdle_getBaseClass
	.type	_CannonBallIdle_getBaseClass, @function
_CannonBallIdle_getBaseClass:
	movhi hi(_State_getBaseClass),r0,r10
	movea lo(_State_getBaseClass),r10,r10
	jmp [r31]
	.size	_CannonBallIdle_getBaseClass, .-_CannonBallIdle_getBaseClass
	.section	.rodata
.LC0:
	.string	"CannonBallIdle"
	.section .text
	.align 2
	.global _CannonBallIdle_getClassName
	.type	_CannonBallIdle_getClassName, @function
_CannonBallIdle_getClassName:
	movhi hi(.LC0),r0,r10
	movea lo(.LC0),r10,r10
	jmp [r31]
	.size	_CannonBallIdle_getClassName, .-_CannonBallIdle_getClassName
	.align 2
	.global _CannonBallIdle_execute
	.type	_CannonBallIdle_execute, @function
_CannonBallIdle_execute:
	jmp [r31]
	.size	_CannonBallIdle_execute, .-_CannonBallIdle_execute
	.align 2
	.global _CannonBallIdle_exit
	.type	_CannonBallIdle_exit, @function
_CannonBallIdle_exit:
	jmp [r31]
	.size	_CannonBallIdle_exit, .-_CannonBallIdle_exit
	.align 2
	.global _CannonBallIdle_processMessage
	.type	_CannonBallIdle_processMessage, @function
_CannonBallIdle_processMessage:
	mov 0,r10
	jmp [r31]
	.size	_CannonBallIdle_processMessage, .-_CannonBallIdle_processMessage
	.align 2
	.global _CannonBallIdle_enter
	.type	_CannonBallIdle_enter, @function
_CannonBallIdle_enter:
	add -4,sp
	st.w lp,0[sp]
	mov r7,r6
	jal _CannonBall_stopMovement
	ld.w 0[sp],lp
	add 4,sp
	jmp [r31]
	.size	_CannonBallIdle_enter, .-_CannonBallIdle_enter
	.align 2
	.global _CannonBallIdle_destructor
	.type	_CannonBallIdle_destructor, @function
_CannonBallIdle_destructor:
	add -8,sp
	st.w r29,4[sp]
	st.w lp,0[sp]
	mov r6,r29
	jal _State_destructor
	jal _MemoryPool_getInstance
	mov r10,r6
	mov r29,r7
	jal _MemoryPool_free
	movea sdaoff(__singletonConstructed),gp,r10
	st.b r0,0[r10]
	ld.w 0[sp],lp
	ld.w 4[sp],r29
	add 8,sp
	jmp [r31]
	.size	_CannonBallIdle_destructor, .-_CannonBallIdle_destructor
	.align 2
	.global _CannonBallIdle_setVTable
	.type	_CannonBallIdle_setVTable, @function
_CannonBallIdle_setVTable:
	add -4,sp
	st.w lp,0[sp]
	movhi hi(_State_setVTable),r0,r10
	movhi hi(_CannonBallIdle_setVTable),r0,r11
	movea lo(_State_setVTable),r10,r10
	movea lo(_CannonBallIdle_setVTable),r11,r11
	cmp r10,r11
	be .L9
	jal _State_setVTable
.L9:
	movhi hi(_CannonBallIdle_destructor),r0,r11
	movea lo(_CannonBallIdle_destructor),r11,r11
	st.w r11,sdaoff(_CannonBallIdle_vTable)[gp]
	movhi hi(_Object_handleMessage),r0,r11
	movea lo(_Object_handleMessage),r11,r11
	movea sdaoff(_CannonBallIdle_vTable),gp,r10
	st.w r11,12[r10]
	movhi hi(_State_suspend),r0,r11
	movea lo(_State_suspend),r11,r11
	st.w r11,28[r10]
	movhi hi(_State_resume),r0,r11
	movea lo(_State_resume),r11,r11
	st.w r11,32[r10]
	movhi hi(_CannonBallIdle_enter),r0,r11
	movea lo(_CannonBallIdle_enter),r11,r11
	st.w r11,16[r10]
	movhi hi(_CannonBallIdle_execute),r0,r11
	movea lo(_CannonBallIdle_execute),r11,r11
	st.w r11,20[r10]
	movhi hi(_CannonBallIdle_exit),r0,r11
	movea lo(_CannonBallIdle_exit),r11,r11
	st.w r11,24[r10]
	movhi hi(_CannonBallIdle_processMessage),r0,r11
	movea lo(_CannonBallIdle_processMessage),r11,r11
	st.w r11,36[r10]
	movhi hi(_CannonBallIdle_getBaseClass),r0,r11
	movea lo(_CannonBallIdle_getBaseClass),r11,r11
	st.w r11,4[r10]
	movhi hi(_CannonBallIdle_getClassName),r0,r11
	movea lo(_CannonBallIdle_getClassName),r11,r11
	st.w r11,8[r10]
	ld.w 0[sp],lp
	add 4,sp
	jmp [r31]
	.size	_CannonBallIdle_setVTable, .-_CannonBallIdle_setVTable
	.align 2
	.global _CannonBallIdle_getObjectSize
	.type	_CannonBallIdle_getObjectSize, @function
_CannonBallIdle_getObjectSize:
	mov 8,r10
	jmp [r31]
	.size	_CannonBallIdle_getObjectSize, .-_CannonBallIdle_getObjectSize
	.align 2
	.global _CannonBallIdle_constructor
	.type	_CannonBallIdle_constructor, @function
_CannonBallIdle_constructor:
	add -4,sp
	st.w lp,0[sp]
	jal _State_constructor
	ld.w 0[sp],lp
	add 4,sp
	jmp [r31]
	.size	_CannonBallIdle_constructor, .-_CannonBallIdle_constructor
	.section	.rodata
.LC1:
	.string	"CannonBallIdle get instance during construction"
	.section .text
	.align 2
	.type	_CannonBallIdle_instantiate, @function
_CannonBallIdle_instantiate:
	add -12,sp
	st.w r28,8[sp]
	st.w r29,4[sp]
	st.w lp,0[sp]
	movea sdaoff(__singletonConstructed),gp,r29
	ld.b 0[r29],r10
	cmp 1,r10
	be .L16
	ld.w sdaoff(_CannonBallIdle_vTable)[gp],r10
	cmp 0,r10
	be .L17
.L15:
	mov 1,r10
	movea sdaoff(_CannonBallIdle_vTable),gp,r28
	st.b r10,0[r29]
	st.w r28,sdaoff(__instanceCannonBallIdle)[gp]
	movea sdaoff(__instanceCannonBallIdle),gp,r6
	jal _CannonBallIdle_constructor
	ld.w 0[sp],lp
	mov 2,r10
	st.w r28,sdaoff(__instanceCannonBallIdle)[gp]
	st.b r10,0[r29]
	ld.w 8[sp],r28
	ld.w 4[sp],r29
	add 12,sp
	jmp [r31]
.L16:
	movhi hi(__sp),r0,r10
#APP
# 48 "source/objects/actors/CannonBall/states/CannonBallIdle.c" 1
	 mov sp,r12  
# 0 "" 2
#NO_APP
	st.w r12,lo(__sp)[r10]
	movhi hi(__lp),r0,r10
#APP
# 48 "source/objects/actors/CannonBall/states/CannonBallIdle.c" 1
	 mov lp,r11  
# 0 "" 2
#NO_APP
	st.w r11,lo(__lp)[r10]
	jal _Error_getInstance
	movhi hi(.LC1),r0,r7
	mov r10,r6
	movea lo(.LC1),r7,r7
	mov 0,r8
	jal _Error_triggerException
	ld.w sdaoff(_CannonBallIdle_vTable)[gp],r10
	cmp 0,r10
	bne .L15
.L17:
	jal _CannonBallIdle_setVTable
	br .L15
	.size	_CannonBallIdle_instantiate, .-_CannonBallIdle_instantiate
	.align 2
	.global _CannonBallIdle_getInstance
	.type	_CannonBallIdle_getInstance, @function
_CannonBallIdle_getInstance:
	add -4,sp
	st.w lp,0[sp]
	movea sdaoff(__singletonConstructed),gp,r10
	ld.b 0[r10],r10
	cmp 0,r10
	bne .L19
	jal _CannonBallIdle_instantiate
.L19:
	ld.w 0[sp],lp
	movea sdaoff(__instanceCannonBallIdle),gp,r10
	add 4,sp
	jmp [r31]
	.size	_CannonBallIdle_getInstance, .-_CannonBallIdle_getInstance
	.global _CannonBallIdle_vTable
	.section	.sbss,"aw",@nobits
	.align 2
	.type	_CannonBallIdle_vTable, @object
	.size	_CannonBallIdle_vTable, 40
_CannonBallIdle_vTable:
	.zero	40
	.section	.sdata,"aw",@progbits
	.type	__singletonConstructed, @object
	.size	__singletonConstructed, 1
__singletonConstructed:
	.zero	1
	.section	.sbss
	.align 2
	.type	__instanceCannonBallIdle, @object
	.size	__instanceCannonBallIdle, 8
__instanceCannonBallIdle:
	.zero	8
	.ident	"GCC: (GNU) 4.7.4"
