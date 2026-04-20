#ifndef BANKING_TRANSACTION_H
#define BANKING_TRANSACTION_H

#include <string>
#include <chrono>

namespace banking {

class Transaction {
public:
    Transaction(const std::string& from, const std::string& to, double amount);
    
    std::string getFrom() const;
    std::string getTo() const;
    double getAmount() const;
    bool execute();
    bool isExecuted() const;
    std::chrono::system_clock::time_point getTimestamp() const;

private:
    std::string from_;
    std::string to_;
    double amount_;
    bool executed_;
    std::chrono::system_clock::time_point timestamp_;
};

} // namespace banking

#endif
