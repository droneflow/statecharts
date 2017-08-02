/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "ShallowHistoryWithDeepEntry.h"

#include "sc_timer_service.h"



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static ShallowHistoryWithDeepEntry statechart;

class ShallowHistoryWithDeepEntryTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		shallowHistoryWithDeepEntry_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &shallowHistoryWithDeepEntry_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(ShallowHistoryWithDeepEntryTest, noDeepEntryWithinHistory) {
	shallowHistoryWithDeepEntry_enter(&statechart);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toZ(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_A));
	shallowHistoryWithDeepEntryIface_raise_toY(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toZ(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_A));
}
TEST_F(ShallowHistoryWithDeepEntryTest, deepEntryWithinHistory) {
	shallowHistoryWithDeepEntry_enter(&statechart);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toZ(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_A));
	shallowHistoryWithDeepEntryIface_raise_toC(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B__region0_C));
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B));
	shallowHistoryWithDeepEntryIface_raise_toY(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toZ(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B__region0_C));
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B));
}
TEST_F(ShallowHistoryWithDeepEntryTest, directDeepEntryIntoHistory) {
	shallowHistoryWithDeepEntry_enter(&statechart);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toC(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B__region0_C));
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B));
	shallowHistoryWithDeepEntryIface_raise_toY(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Y));
	shallowHistoryWithDeepEntryIface_raise_toZ(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B__region0_C));
	EXPECT_TRUE(shallowHistoryWithDeepEntry_isStateActive(&statechart, ShallowHistoryWithDeepEntry_main_region_Z__region0_B));
}


