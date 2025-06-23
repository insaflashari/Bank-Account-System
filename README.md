![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

# Mo Money — Transaction History Manager

### Author: Insaf Lashari  
**Date:** December 5, 2023  
**University of Waterloo – ECE150 Project 4

---

## Overview

**Mo Money** is a C++ console program that simulates a stock transaction history and computes:

- Adjusted Cost Base (ACB)
- Capital Gains/Losses (CGL)
- Share balances and per-share values across transactions

This project demonstrates linked list data structures, dynamic memory, file parsing, and basic financial computation.

---

## Features

✅ Build a linked list from a transaction file  
✅ Sort transactions by date and transaction ID  
✅ Compute ACB, ACB/share, and CGL  
✅ Display clean, formatted transaction history  
✅ Modular structure using OOP principles

## Key Concepts

- Singly linked lists
- Operator overloading (`<` for date comparison)
- File I/O (via `project4.cpp` helpers)
- Dynamic memory & destructors
- Financial logic (buy/sell, cost basis, profit/loss)

---

## Project Structure
├── main.cpp # Program entry point

├── History_Transaction_definitions.cpp # All class definitions (History & Transaction)

├── History.hpp / Transaction.hpp # Header files for class declarations

├── project4.cpp / project4.hpp # Helper functions for file input

├── transaction_history.txt # Input data file

### Sample Output

========== BEGIN TRANSACTION HISTORY ============
   1 AAPL   15    3 2020   Buy   100     12000.00     12000.00  100     120.000       0.000
   2 AAPL   10    5 2020  Sell    50      7000.00      6000.00   50     120.000     1000.000
========== END TRANSACTION HISTORY ============


## How to Compile and Run
### Compile (Windows PowerShell):
```bash
g++ -o mo_money.exe main.cpp History_Transaction_definitions.cpp project4.cpp -std=c++11
.\mo_money.exe

