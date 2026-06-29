📖 Contact Management System
A robust console-based application written in C++ designed for efficient personal contact management. This project focuses on implementing a secure Contact Management System with user authentication and comprehensive data manipulation capabilities.

🚀 Features
🔐 Secure Authentication: Multi-user registration and login system with password protection.

👤 Relational Contact Management:

Registration: First, create a unique account; each user is assigned a specific User ID.

Personalized System: After logging in, you can manage contacts that are strictly assigned to your User ID.

Add: Create new contact records linked to your account (First/Last Name, Phone, Email, Address).

Search: Efficiently locate your own contacts by name.

Display: View all entries specifically assigned to your user account in a clean, readable format.

Edit: Update your existing contact details seamlessly.

Remove: Safely delete contacts belonging to your account from the database.

⚙️ Account Security: Change your password at any time.

💾 Data Persistence: Seamless saving and loading of user and contact data using local text files (Users.txt, Recipients.txt), where contact data is filtered by the logged-in User ID.

🏗️ Data Architecture
The application ensures data integrity and organization through a structured ID system:

Unique User Identification: Every account is assigned a unique User ID upon registration.

Relational Mapping: Each contact entry is strictly linked to a specific User ID. This hierarchical structure ensures that the Contact Management data remains organized and accessible only to their respective owners.

🛠️ Technologies & Tools
Language: C++ 💻

Version Control: Git & GitHub 🐙

IDE: Visual Studio Code ⚡

System APIs: windows.h (used for system("cls") and Sleep functions) 🪟

Data Handling: File I/O (fstream, sstream) for persistent storage 💾

🎥 Demonstration
See how the Contact Management System works in practice:

[▶️ Click here to watch the demonstration video](https://youtu.be/faE6aPZhRJg)
