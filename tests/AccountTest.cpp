#include "banking/Account.h"
#include <gtest/gtest.h>

using namespace banking;

class AccountTest : public ::testing::Test {
protected:
    void SetUp() override {
        account1 = std::make_unique<Account>("ACC1", 1000.0);
        account2 = std::make_unique<Account>("ACC2", 500.0);
    }
    
    std::unique_ptr<Account> account1;
    std::unique_ptr<Account> account2;
};

TEST_F(AccountTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(account1->getId(), "ACC1");
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1000.0);
}

TEST_F(AccountTest, DepositValidAmount) {
    EXPECT_TRUE(account1->deposit(500.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1500.0);
}

TEST_F(AccountTest, DepositInvalidAmount) {
    EXPECT_FALSE(account1->deposit(-100.0));
    EXPECT_FALSE(account1->deposit(0.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1000.0);
}

TEST_F(AccountTest, WithdrawValidAmount) {
    EXPECT_TRUE(account1->withdraw(300.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 700.0);
}

TEST_F(AccountTest, WithdrawInvalidAmount) {
    EXPECT_FALSE(account1->withdraw(-50.0));
    EXPECT_FALSE(account1->withdraw(2000.0));
    EXPECT_FALSE(account1->withdraw(0.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1000.0);
}

TEST_F(AccountTest, TransferValidAmount) {
    EXPECT_TRUE(account1->transfer(*account2, 300.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 700.0);
    EXPECT_DOUBLE_EQ(account2->getBalance(), 800.0);
    EXPECT_EQ(account1->getTransactionHistory().size(), 1);
    EXPECT_EQ(account2->getTransactionHistory().size(), 1);
}

TEST_F(AccountTest, TransferInvalidAmount) {
    EXPECT_FALSE(account1->transfer(*account2, 2000.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1000.0);
    EXPECT_DOUBLE_EQ(account2->getBalance(), 500.0);
}

TEST_F(AccountTest, TransferNegativeAmount) {
    EXPECT_FALSE(account1->transfer(*account2, -100.0));
    EXPECT_DOUBLE_EQ(account1->getBalance(), 1000.0);
    EXPECT_DOUBLE_EQ(account2->getBalance(), 500.0);
}

TEST_F(AccountTest, TransactionHistoryAfterMultipleTransfers) {
    account1->transfer(*account2, 200.0);
    account1->transfer(*account2, 150.0);
    
    auto history = account1->getTransactionHistory();
    EXPECT_EQ(history.size(), 2);
    EXPECT_DOUBLE_EQ(history[0]->getAmount(), 200.0);
    EXPECT_DOUBLE_EQ(history[1]->getAmount(), 150.0);
}
