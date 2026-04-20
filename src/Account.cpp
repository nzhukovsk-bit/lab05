#include "banking/Account.h"

namespace banking {

Account::Account(const std::string& id, double initialBalance)
    : id_(id), balance_(initialBalance) {}

std::string Account::getId() const {
    return id_;
}

double Account::getBalance() const {
    return balance_;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    balance_ += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

bool Account::transfer(Account& to, double amount) {
    if (withdraw(amount)) {
        auto transaction = std::make_shared<Transaction>(id_, to.id_, amount);
        transaction->execute();
        transactions_.push_back(transaction);
        
        to.deposit(amount);
        to.transactions_.push_back(transaction);
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Transaction>> Account::getTransactionHistory() const {
    return transactions_;
}

} // namespace banking
