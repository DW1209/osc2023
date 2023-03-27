#ifndef __TIMER_H__
#define __TIMER_H__

#define CORE0_TIMER_IRQ_CTRL 0x40000040

void core_timer_enable(void);
void core_timer_handler(void);
unsigned long get_current_time(void);
unsigned long get_core_frequency(void);

#endif