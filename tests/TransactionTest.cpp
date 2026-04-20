#include "banking/Transaction.h"
#include <gtest/gtest.h>

using namespace banking;

class TransactionTest : public ::testing::Test {
protected:
    void SetUp() override {
        transaction = std::make_unique<Transaction>("ACC1", "ACC2", 100.0);
    }
    
    std::unique_ptr<Transaction> transaction;
};

TEST_F(TransactionTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(transaction->getFrom(), "ACC1");
    EXPECT_EQ(transaction->getTo(), "ACC2");
    EXPECT_DOUBLE_EQ(transaction->getAmount(), 100.0);
    EXPECT_FALSE(transaction->isExecuted());
}

TEST_F(TransactionTest, ExecuteSetsExecutedFlag) {
    EXPECT_TRUE(transaction->execute());
    EXPECT_TRUE(transaction->isExecuted());
}

TEST_F(TransactionTest, TimestampIsSet) {
    auto timestamp = transaction->getTimestamp();
    auto now = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - timestamp);
    EXPECT_LE(diff.count(), 1);
}

TEST_F(TransactionTest, MultipleExecutions) {
    transaction->execute();
    transaction->execute();
    EXPECT_TRUE(transaction->isExecuted());
}
