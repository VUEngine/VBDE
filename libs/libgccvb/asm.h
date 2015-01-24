#ifndef __ASM_H
#define __ASM_H

#define INT_ENABLE		asm("CLI;")
#define INT_DISABLE		asm("SEI;")

#define ASM_H_INLINE

u32 jump_addr(void *addr);
void ASM_H_INLINE set_intlevel(u8 level);
int ASM_H_INLINE get_intlevel();

#endif
