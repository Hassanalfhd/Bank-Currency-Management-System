# 🏦 Advanced Banking & Currency Management System

A robust, enterprise-grade **C++ Console Application** that simulates a full-scale banking environment integrated with a sophisticated currency exchange engine. This project is a comprehensive showcase of **Object-Oriented Programming (OOP)**, **Layered Architecture**, and **Data Persistence** using flat files.

---

## 🚀 Core Modules

### 1. 👤 User Management & Security
- **Multi-Level Permissions:** A bitwise system to grant/deny access to specific features (Manage Users, Transactions, etc.).
- **Login/Logout Tracking:** Automatic logging of user sessions in `LoginRegister.txt`.
- **Full User CRUD:** Create, Read, Update, and Delete system operators.

### 2. 💰 Banking Operations (Clients)
- **Account Management:** Comprehensive client profiles with unique account numbers and pin codes.
- **Transaction Engine:**
    - **Deposit & Withdraw:** Real-time balance updates.
    - **Internal Transfers:** Securely move money between accounts.
    - **Transfer Auditing:** Every transfer is logged in a `TransferLog.txt` with timestamps and user details.

### 3. 💱 Currency Exchange Engine
- **Global Database:** Manage world currencies, codes, and exchange rates.
- **Cross-Currency Calculator:** Convert any amount between two different currencies using **USD** as the base reference.
- **Dynamic Updates:** Update currency rates on the fly without restarting the system.

---

## 🛠 Technical Highlights (OOP & Architecture)

This project follows the **SOLID** principles and a **Tiered Architecture**:
- **Inheritance:** Used for Persons (`clsPerson` → `clsBankClient`) and UI Screens (`clsScreen` → `clsLoginScreen`).
- **Encapsulation:** Private data members with public getters/setters using properties.
- **Abstraction:** Static helper classes for input validation, string manipulation, and date formatting.
- **Data Layer:** Custom-built file handling system using delimited text files (`#//#`).

---

## 📸 System Showcase (Screenshots)

### 🔑 Authentication & Main Menu
| Login Screen | Home Menu | Access Denied |
| :---: | :---: | :---: |
| ![Login](LoginScreen.PNG) | ![Home](HomeScreen.PNG) | ![Denied](AccessDeniedScreen.PNG) |

### 👥 Client & User Management
| Clients List | Add New User | Permissions System |
| :---: | :---: | :---: |
| ![Clients](ShowClientsListScreen.PNG) | ![Add User](AddNewUserScreen1.PNG) | ![Permissions](AddNewUserScreenWithPermissions.PNG) |

### 💸 Transactions & Transfers
| Transactions Menu | Transfer Operation | Transfer Log |
| :---: | :---: | :---: |
| ![Transactions](TransctionsMenueScreen.PNG) | ![Transfer](TransferScreen1.PNG) | ![Log](TransferLogRegisterScreen.PNG) |

### 💱 Currency Exchange Module
| Currency Menu | Currency Calculator | Currencies List |
| :---: | :---: | :---: |
| ![Currency Menu](CurrencyExchangeMenue.PNG) | ![Calculator](CurrencyCalculatorScreen.PNG) | ![Currencies](CurrenciesListScreen.PNG) |

<details>
<summary>📂 View More Screens (Update/Delete/Find)</summary>

- **Update Operations:** `UpdateClientScreen.PNG`, `UpdateUserScreen.PNG`, `UpdateCurrencyScreen.PNG`.
- **Delete Operations:** `DeleteClientScreen.PNG`, `DeleteUserScreen.PNG`.
- **Search Operations:** `FindClientScreen.PNG`, `FindUserScreen.PNG`, `FindCurrencyScreen.PNG`.
- **Balances:** `TotalVBalanceScreen.PNG`, `DepositAmountScreen.PNG`, `WithdrawAmountScreen.PNG`.
</details>

---

