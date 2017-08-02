/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "Constants.h"

#include "sc_timer_service.h"



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static Constants statechart;

class ConstantsTests : public ::testing::Test{
	protected:
	virtual void SetUp() {
		constants_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &constants_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(ConstantsTests, constantDefinition) {
	constants_enter(&statechart);
	EXPECT_TRUE(constants_isStateActive(&statechart, Constants_main_region_A));
	EXPECT_TRUE(constantsIface_get_x(&statechart)== 10l);
	EXPECT_TRUE(constantsIface_get_y(&statechart)== 20l);
	EXPECT_TRUE(strcmp(constantsIfaceNamed_get_y(&statechart) , "Hello World") == 0);
	constantsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(constantsIface_get_result(&statechart)== 20l);
	constantsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(constants_isStateActive(&statechart, Constants_main_region_C));
	EXPECT_TRUE(constantsIface_get_result(&statechart)== 100l);
	constantsIface_raise_e2(&statechart, constantsIface_get_x(&statechart));
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(constantsIface_get_result(&statechart)== 1000l);
	EXPECT_TRUE(constants_isStateActive(&statechart, Constants_main_region_A));
}


