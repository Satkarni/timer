#include "unity/src/unity.h"
#include "../src/timer.h"


void test_TimerproperInit(void)
{
	TMR_init();
	for(int i =0;i<TIMERS_NUM;i++)
	{
		TEST_ASSERT_EQUAL(0,TMR_isEnabled(i));
		TEST_ASSERT_EQUAL(0,TMR_isDone(i));
	}
	
}

void test_TimerisEnabled(void)
{
	TMR_init();
	TMR_enable(0);
	TEST_ASSERT_EQUAL(1,TMR_isEnabled(0));
}

void test_Timer(void)
{
	TMR_init();
	TMR_enable(0);
	for(int i=0;i<30;i++)
	{
		TMR_tick(10);
	}
	TEST_ASSERT_EQUAL(1,TMR_isDone(0));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_TimerproperInit);
	RUN_TEST(test_TimerisEnabled);
	RUN_TEST(test_Timer);
	return UNITY_END();	
}