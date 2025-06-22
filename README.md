# Mo Money — Transaction History Manager

### Author: Insaf Lashari  
**Date:** December 5, 2023  
**Course Project:** ECE150 – Introduction to Programming (Project 4)  

---

## Overview

**Mo Money** is a C++ project that processes a linked list of stock market transactions to compute:

- Adjusted Cost Base (ACB)
- Capital Gains/Losses (CGL)
- Share balances and per-share values over time

It simulates the backend logic of a simplified **stock portfolio tracker**, showcasing linked list manipulation, date sorting, and financial calculations.

---

## Features

✅ Transaction creation and storage via a linked list  
✅ Chronological sorting of transactions (by date + transaction ID)  
✅ Dynamic calculation of:
- Adjusted Cost Base (ACB)
- ACB per share
- Share balance after each transaction
- Capital Gains/Losses (CGL) for "Sell" actions

✅ Reads transactions from `transaction_history.txt` using helper functions  
✅ Clean memory management with proper destructors  
✅ Terminal output for displaying formatted transaction history  

---

## Project Structure
├── Transaction.hpp / Transaction.cpp # Node class for individual transactions

├── History.hpp / History.cpp # Linked list manager for all transactions

├── project4.hpp # Helper I/O functions for file reading

├── transaction_history.txt # Input file containing transaction data

├── main.cpp # (Assumed) Main driver file

