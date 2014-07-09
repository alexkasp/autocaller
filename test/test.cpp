#include "gtest/gtest.h"
#include "testTask.h"
TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18.0, 18);
    EXPECT_EQ (25.4, 25+0.4);
    EXPECT_EQ (50.3321, 50.3322-0.0001);
}

 int main(int argc, char **argv) {
        ::testing::InitGoogleTest( &argc, argv );
        return RUN_ALL_TESTS();
    }