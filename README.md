# Lab05 - Banking System with Google Test

## Description

Banking system implementation with comprehensive unit testing using Google Test and Google Mock.

## Building

```bash
mkdir build && cd build
cmake .. -DBUILD_TESTS=ON
make
```

## Running Tests

```bash
./check
# or
ctest
```

## Code Coverage

```bash
make coverage
```

## Features

- Account management (deposit, withdraw, transfer)
- Transaction history
- 100% code coverage
- Mock objects for isolated testing

## Author

nzhukovsk-bit

## Code Coverage

| File | Coverage |
|------|----------|
| Account.cpp | 100% ✅ |
| Transaction.cpp | 100% ✅ |
| **Total** | **100%** ✅ |

### Test Results
- **16/16 tests passed** ✅
- Lines coverage: 44/44 (100%)
- Functions coverage: 14/14 (100%)
