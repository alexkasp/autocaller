#include "gtest/gtest.h"
#include "../Task.h"
#include <string>
#include <vector>


TEST(Test_Task_class,check_init_func_with_correct)
{
	Task t;
	std::string schema = "333333";
	std::string outline = "222222";
	std::string caller = "111111";
	std::string taskname = "Test";

	std::vector<std::string> mokdata;

	t.init(mokdata,mokdata,schema,outline,caller,"");

	 EXPECT_EQ(schema, t.GetSchema());
	 EXPECT_EQ(outline, t.GetOutLine());
	 EXPECT_EQ(caller, t.GetCaller());
	
}

TEST(Test_Task_class,check_init_func_with_incorrect)
{
	Task t;
	std::string schema = "333333";
	std::string outline = "222222";
	std::string caller = "111111";
	std::string taskname = "Test";

	std::vector<std::string> mokdata;

	t.init(mokdata,mokdata,"incorrect","incorrect","incorrect","");

	 EXPECT_NE(schema, t.GetSchema());
	 EXPECT_NE(outline, t.GetOutLine());
	 EXPECT_NE(caller, t.GetCaller());
	
}