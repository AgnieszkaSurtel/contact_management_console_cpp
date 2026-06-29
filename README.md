# 📖 Contact Management System

A robust console-based application written in **C++** designed for efficient personal contact management.

## 🚀 Live Demo
You can check out the working application here: [YouTube](https://youtu.be/faE6aPZhRJg)

## 🚀 Features

* **🔐 Secure Authentication**: Multi-user registration and login system with password protection.
* **👤 Relational Contact Management**:
    * **Registration**: First, create a unique account; each user is assigned a specific **User ID**.
    * **Personalized System**: After logging in, you can manage contacts that are strictly assigned to your **User ID** and password.
    * **Add**: Create new contact records linked to your account.
    * **Search**: Efficiently locate your own contacts by name or surname.
    * **Display**: View all entries specifically assigned to your user account.
    * **Edit**: Update your existing contact details seamlessly.
    * **Remove**: Safely delete contacts belonging to your account from the database.
* **⚙️ Account Security**: Change your password at any time.
* **💾 Data Persistence**: Seamless saving and loading of user and contact data using local text files (`Users.txt`, `Recipients.txt`), where contact data is filtered by the logged-in **User ID**.

## 🏗️ Data Architecture

The application ensures data integrity through a structured ID system:

* **Unique User Identification**: Every account is assigned a unique **User ID**.
* **Relational Mapping**: Each contact entry is strictly linked to a specific **User ID**.

* **Language**: C++ 💻
* **Version Control**: Git & GitHub 🐙
* **IDE**: Visual Studio Code ⚡
* **System APIs**: `windows.h` (used for `system("cls")` and `Sleep` functions) 🪟
* **Data Handling**: File I/O (fstream, sstream) for persistent storage 💾

## 🚀 How to Run

1. **Clone the repository**:
   ```
   git clone https://github.com/AgnieszkaSurtel/contact_management_console_cpp.git
   ```
2. Navigate to the project folder:
```
cd contact_management_console_cpp
```
3. Compile the code (ensure you have a C++ compiler like MinGW installed):
  ```
 g++ -o ContactManager.exe main.cpp Recipient.cpp User.cpp UserManager.cpp RecipientManager.cpp HelperMethods.cpp
```
4. Run the application:
   ```
   ./AddressBook.exe
   ```
## 💡 Author

Built by Agnieszka Surtel
