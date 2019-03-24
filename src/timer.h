/*
 * timer.h
 * Author: Rohan Pandit
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define TIMER_FREQ_Hz	( 10 )
#define TIMERS_NUM		( 60 )

void TMR_init();
void TMR_tick(float userISRfreq);
void TMR_enable(uint16_t index);
void TMR_reset(uint16_t index);
void TMR_checkifDone(uint16_t index);
void TMR_incTimers();
int TMR_isEnabled(uint16_t index);
int TMR_isDone(uint16_t index);
void TMR_setPreset(uint16_t index,double value);
void TMR_setPresetDefault(double deflt);

#endif /* TIMER_H */
