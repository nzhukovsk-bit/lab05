#ifndef BANKING_ACCOUNT_H
#define BANKING_ACCOUNT_H

#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"

namespace banking {

class Account {
public:
    explicit Account(const std::string& id, double initialBalance = 0.0);
    
    std::string getId() const;
    double getBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& to, double amount);
    std::vector<std::shared_ptr<Transaction>> getTransactionHistory() const;
    
private:
    std::string id_;
    double balance_;
    std::vector<std::shared_ptr<Transaction>> transactions_;
};

} // namespace banking

#endif
