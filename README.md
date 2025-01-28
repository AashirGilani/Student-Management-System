# Student-Management-System
A C++ project to manage student and teacher records with roles like Admin, Teacher, and Student. Features include adding/deleting records, CGPA calculation, and secure login via auto-generated credentials.

## README.md

# Student Management System

## Overview
The **Student Management System** is a C++ project designed to effectively manage the records of students and teachers. This program provides a user-friendly interface for three types of users:
1. **Admin**
2. **Teacher**
3. **Student**

The system uses text files to store data in a sequential and formatted manner, ensuring data persistence across sessions. It incorporates authentication features with passwords and emails generated dynamically based on the teacher's or student's ID. The system also supports arithmetic operations, enabling tasks such as calculating CGPA and analyzing performance.

---

## Features
### Core Functionalities:
- **User Roles**: 
  - **Admin**: Manage teacher and student data (add/delete records).
  - **Teacher**: View and analyze student grades and performance.
  - **Student**: Log in to view personal grades and CGPA.

- **Data Management**:
  - Add new teachers and students (`addteacher`, `addstudent`).
  - Delete teacher and student records by their unique ID (`deleteteacher`, `deletestudent`).
  - Text files are updated dynamically while maintaining proper formatting and order.

- **Academic Analysis**:
  - Calculate the CGPA of a student (`calculatecgpa`).
  - List students based on academic performance:
    - Passed students (`listpassedstudents`).
    - Failed students (`listfailedstudents`).
  - Display average CGPA of all students (`averagecgpa`).

- **Student-Specific Functionality**:
  - View grades and CGPA for the student logged in.

- **Security**:
  - Password-protected login for all users.
  - Email IDs auto-generated based on user IDs.

---

## User-Defined Functions
The project implements the following user-defined functions:
1. `addteacher`: Add a new teacher record to the system.
2. `deleteteacher`: Remove a teacher record based on their ID.
3. `addstudent`: Add a new student record to the system.
4. `deletestudent`: Remove a student record based on their ID.
5. `calculatecgpa`: Compute the CGPA of a student.
6. `viewgrades`: Display grades for a specific student.
7. `listpassedstudents`: List all students who passed.
8. `listfailedstudents`: List all students who failed.
9. `averagecgpa`: Calculate the average CGPA of all students.

---

## Data Storage
The system uses `.txt` files for storing teacher and student data. 
- **Data Deletion**: When a record is deleted, the file is updated to maintain proper order and formatting.
- **Data Retrieval**: Efficient access to individual records based on IDs ensures quick and accurate information retrieval.

---

## Authentication
- Each user is assigned a unique email and password upon account creation.
- Emails are dynamically generated based on the user’s ID.

---

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/student-management-system.git
   ```
2. Navigate to the project directory:
   ```bash
   cd student-management-system
   ```
3. Compile the project:
   ```bash
   g++ main.cpp -o StudentManagementSystem
   ```
4. Run the project:
   ```bash
   ./StudentManagementSystem
   ```

---

## Future Enhancements
- Add support for more file formats (e.g., CSV or databases).
- Implement a graphical user interface (GUI) for improved usability.
- Enhance security with encryption for passwords.
- Add real-time performance analytics for teachers and admins.

---

## Contributing
Contributions are welcome! Feel free to fork this repository and submit a pull request with your improvements.

---

## License
This project is open-source and available under the MIT License. See the `LICENSE` file for more details.

---

## Acknowledgments
Thanks to all contributors and the C++ community for their support and resources.
