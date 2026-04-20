#ifndef MOCK_TRANSACTION_H
#define MOCK_TRANSACTION_H

#include "banking/Transaction.h"
#include <gmock/gmock.h>

namespace banking {

class MockTransaction : public Transaction {
public:
    MockTransaction(const std::string& from, const std::string& to, double amount)
        : Transaction(from, to, amount) {}
    
    MOCK_METHOD0(execute, bool());
};

} // namespace banking

#endif
