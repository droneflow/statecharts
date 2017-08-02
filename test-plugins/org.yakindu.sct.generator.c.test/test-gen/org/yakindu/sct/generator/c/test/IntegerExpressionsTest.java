/* Generated by YAKINDU Statechart Tools code generator. */
package org.yakindu.sct.generator.c.test;

import org.junit.Before;
import org.junit.runner.RunWith;
import org.yakindu.sct.generator.c.gtest.GTest;
import org.yakindu.sct.generator.c.gtest.GTestRunner;
import org.yakindu.sct.generator.c.gtest.GTestHelper;

@GTest(
	statechartBundle = "org.yakindu.sct.test.models",
	sourceFile = "gtests/IntegerExpressions/IntegerExpressionsTest.cc",
	program = "gtests/IntegerExpressions/IntegerExpressions",
	model = "testmodels/SCTUnit/IntegerExpressions.sct",
	additionalFilesToCopy = {
		"gtests/IntegerExpressions/sc_timer_service.c",
		"gtests/IntegerExpressions/sc_timer_service.h"
	},
	additionalFilesToCompile = {
		"IntegerExpressions.c",
		"sc_timer_service.c"
	}
)
@RunWith(GTestRunner.class)
public class IntegerExpressionsTest {

	protected final GTestHelper helper = new GTestHelper(this);

	@Before
	public void setUp() {
		helper.generate();
		helper.compile();
	}
}
