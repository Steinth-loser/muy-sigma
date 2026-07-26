/*
 * bsp.c
 *
 *  Created on: Jul 4, 2026
 *      Author: th3ka
 */


#include "gpio.h"
#include "bsp.h"
#include "qpc.h"
#include <stdint.h>


















//NEEDED IN EVERY PROJECT
void Q_onError(char const * const module, int_t const id) {
    (void)module;
    (void)id;
    __disable_irq();     // kesmeleri kapat
    NVIC_SystemReset();  // ya da burada kendi hata yönetimini yaz (LED yakıp sonsuz döngü vs.)
}

/* QF başlarken bir kere çağrılır  */
void QF_onStartup(void) {
	NVIC_SetPriority(SysTick_IRQn, QF_AWARE_ISR_CMSIS_PRI);
    /* Örn: SysTick önceliğini ayarla, gerekli interrupt'ları enable et */
}

/* QV kernel boşta kaldığında (işlenecek event yokken) sürekli çağrılır */
void QV_onIdle(void) {
	QF_INT_ENABLE();
    /* Örn: düşük güç moduna geç, ya da boş bırak (__WFI() de kullanılabilir) */
}
