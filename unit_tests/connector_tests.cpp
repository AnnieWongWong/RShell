#ifndef __CONNECTOR_TESTS_CPP__
#define __CONNECTOR_TESTS_CPP__
#include "Connector.h"
#include "SemiColon.h"
#include "AndStrat.h"
#include "OrStrat.h"

#include "gtest/gtest.h"

TEST(Connectors, Semi1) {
   bool runns = true;
   SemiColon* semi = new SemiColon();
   EXPECT_EQ(semi->run(runns),true);
}

TEST(Connectors, Semi2) {
   bool runns = false;
   SemiColon* semi = new SemiColon();
   EXPECT_EQ(semi->run(runns),true);
}

TEST(Connectors, And1) {
   bool runns = true;
   AndStrat* and1 = new AndStrat();
   EXPECT_EQ(and1->run(runns),true);
}

TEST(Connectors, And2) {
   bool runns = false;
   AndStrat* or1 = new AndStrat();
   EXPECT_EQ(or1->run(runns),false);
}

TEST(Connectors, Or1) {
   bool runns = false;
   OrStrat* or2 = new OrStrat();
   EXPECT_EQ(or2->run(runns),true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif
