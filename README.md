# timer
Small utility to generate non blocking delays in embedded firmware

To use:

1. Call TMR_init() in your initialization code.
2. Enable timer with TMR_enable(index).
3. Generate periodic interrupt at fixed frequency as per your firmware and call TMR_tick() within it.
4. Check if done with TMR_isDone().


Example :

```c
#include "timer.h"

void init()
{
    //Microcontroller initialization code here...
    init_clocks();
    init_hw();
    ...
    TMR_init();
}

//ISR routine at a fixed frequency (for e.g 1 KHz)
void interrupt ISR(void)
{
    //Other ISR code here...
    TMR_tick(1000);   //Pass frequency of ISR as argument
}

int main()
{
    TMR_setPreset(2,10);    //Sets preset for timer no.2 to 10 seconds
    TMR_enable(2);          //Enable timer no. 2
    .
    ..
    doSomethingElse1();     
    if(TMR_isDone(2))
    {
      //...application code to be executed
    }
    
    doSomethingElse2();     //Timer counts in the background and does not block this function
    
}
```




    
