/*Instance of task t7*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisgreaterorequal);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t7_instance1(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = ReceiveMessage(rm_newisgreaterorequal, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,2, (int)received_char);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t7_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t7_instance1",test_t7_instance1)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}