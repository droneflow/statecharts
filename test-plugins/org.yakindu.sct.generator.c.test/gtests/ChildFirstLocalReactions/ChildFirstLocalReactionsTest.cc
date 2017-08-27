/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "ChildFirstLocalReactions.h"

#include "sc_timer_service.h"

static long counter = 0l;


//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static ChildFirstLocalReactions statechart;

class ChildFirstLocalReactionsTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		childFirstLocalReactions_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &childFirstLocalReactions_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(ChildFirstLocalReactionsTest, expectBottomUpLocalReactionOrder) {
	childFirstLocalReactions_enter(&statechart);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAA));
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAA));
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aaa_local(&statechart)== 1l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aa_local(&statechart)== 2l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_a_local(&statechart)== 3l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_sm_local(&statechart)== 4l);
}
TEST_F(ChildFirstLocalReactionsTest, expectParentLocalReactionOnChildLocalTransition) {
	childFirstLocalReactions_enter(&statechart);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAA));
	childFirstLocalReactionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAB));
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aaa_local(&statechart)== 0l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aa_local(&statechart)== 1l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_a_local(&statechart)== 2l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_sm_local(&statechart)== 3l);
}
TEST_F(ChildFirstLocalReactionsTest, expectGrandparentLocalReactionOnParentLocalTransition) {
	childFirstLocalReactions_enter(&statechart);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAA));
	childFirstLocalReactionsIface_set_disable_aaa(&statechart,true);
	childFirstLocalReactionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AB));
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aaa_local(&statechart)== 1l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aa_local(&statechart)== 0l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_a_local(&statechart)== 2l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_sm_local(&statechart)== 3l);
}
TEST_F(ChildFirstLocalReactionsTest, expectNoLocalReactionOnGrandparentTransition) {
	childFirstLocalReactions_enter(&statechart);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_A_r_AA_r_AAA));
	childFirstLocalReactionsIface_set_disable_aaa(&statechart,true);
	childFirstLocalReactionsIface_set_disable_aa(&statechart,true);
	childFirstLocalReactionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(childFirstLocalReactions_isStateActive(&statechart, ChildFirstLocalReactions_ChildFirstLocalReactions_r_B));
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aaa_local(&statechart)== 1l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_aa_local(&statechart)== 2l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_a_local(&statechart)== 0l);
	EXPECT_TRUE(childFirstLocalReactionsIface_get_sm_local(&statechart)== 3l);
}

