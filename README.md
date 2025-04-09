# 🎓 Student Record Management System in C++

This is a console-based application developed in **C++** that allows users to manage student records using **Object-Oriented Programming (OOP)** and **binary file handling**.

## 📌 Features

- 🔹 Add new student records  
- 🔹 Display all records  
- 🔹 Search a student by roll number  
- 🔹 Delete a student record  
- 🔹 Update an existing student record  
- 🔹 Validates roll number to ensure it's a 4-digit number  

## 💻 Technologies Used

- C++ (OOP concepts)
- File Handling with Binary Files (`fstream`)
- `cin.getline()` for multi-word input
- Console-based interaction (`getch()` and `goto` used for menu navigation)

## 🛠 Functionality Details

| Function | Description |
|---------|-------------|
| `add()` | Takes user input and appends student records to `record.dat` |
| `display()` | Reads and displays all student records |
| `search()` | Searches and shows details of a student using roll number |
| `Delete()` | Deletes a student record by copying all other records to a new file |
| `update()` | Updates an existing record based on roll number |

## 📂 File Structure

- `record.dat` – Binary file that stores all student records
- Temporary files like `newfile.dat`, `newdata.dat` are used during update/delete operations

## ⚠️ Validations

- Roll number must be a **4-digit number**
- Uses `cin.ignore()` to clear buffer before reading full names
- Validates file operations with safety checks
![Student Record Management Flow](https://github.com/your-username/your-repo-name/blob/main/include_bits_stdc++.h_ - visual selection (1).png?raw=true)

## 🚀 How to Run

1. Make sure you have a C++ compiler (like `g++`) installed.
2. Compile the code:

   ```bash
   g++ -o student student.cpp
