#include "banking/Transaction.h"

namespace banking {

Transaction::Transaction(const std::string& from, const std::string& to, double amount)
    : from_(from), to_(to), amount_(amount), executed_(false), 
      timestamp_(std::chrono::system_clock::now()) {}

std::string Transaction::getFrom() const {
    return from_;
}

std::string Transaction::getTo() const {
    return to_;
}

double Transaction::getAmount() const {
    return amount_;
}

bool Transaction::execute() {
    executed_ = true;
    return true;
}

bool Transaction::isExecuted() const {
    return executed_;
}

std::chrono::system_clock::time_point Transaction::getTimestamp() const {
    return timestamp_;
}

} // namespace banking
