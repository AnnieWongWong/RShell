#include "gtest/gtest.h"

TEST(Connector, get_Line) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

TEST(Connector, run) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

//---------------------------------------------------------------------------------------------------
TEST(Executable, get_Line) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

TEST(Executable, run) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}
//----------------------------------------------------------------------------------------------------
TEST(Command, get_Line) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

TEST(Connector, run) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

TEST(Connector, get_Runned) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}

TEST(Connector, start_Command_prompt) {
    Op value(-5.7);
    EXPECT_EQ("0", .evaluate());
}







int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
