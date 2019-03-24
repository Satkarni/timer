/*
 * timer.c
 * Author: Rohan Pandit
 */

#include "timer.h"
#include "string.h"

struct Timer
{
    int enabled;
    int done;
    uint16_t count;
    uint16_t preset;
};

static struct Timer TimerArr[TIMERS_NUM];

void TMR_init()
{
    int i = 0;
    for (i = 0; i < TIMERS_NUM; i++)
    {
        memset((void *) (TimerArr + i), 0, sizeof(struct Timer));
    }
    TMR_setPresetDefault(3);
}

void TMR_tick(float userISRfreq)
{
    static uint16_t TimerTick = 0;
    if(++TimerTick >= (userISRfreq / TIMER_FREQ_Hz))
    {
        TMR_incTimers();   //increment count for enabled timers
        TimerTick = 0;
    }
}
void TMR_reset(uint16_t index)
{
    TimerArr[index].count = 0;
    TimerArr[index].done = 0;
    TimerArr[index].enabled = 0;
}

void TMR_checkifDone(uint16_t index)
{
    if(TimerArr[index].count >= TimerArr[index].preset)
    {
        TimerArr[index].done = 1;
    }
}

void TMR_incTimers()
{
    int i;
    for (i = 0; i < TIMERS_NUM; i++)
    {
        if(TMR_isEnabled(i) && !(TMR_isDone(i)))
        {
            TimerArr[i].count++;
        }
        TMR_checkifDone(i);
    }
}

void TMR_enable(uint16_t index)
{
    TimerArr[index].enabled = 1;
}

int TMR_isEnabled(uint16_t index)
{
    return TimerArr[index].enabled;
}
int TMR_isDone(uint16_t index)
{
    return TimerArr[index].done;
}

void TMR_setPreset(uint16_t index, double value)
{
    TimerArr[index].preset = value * TIMER_FREQ_Hz;
}

void TMR_setPresetDefault(double deflt)
{
    int i = 0;
    for (i = 0; i < TIMERS_NUM; i++)
    {
        TMR_setPreset(i, deflt);
    }
}
