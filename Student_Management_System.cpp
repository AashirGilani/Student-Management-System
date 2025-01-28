#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<limits>
#include<sstream>

int studentid[30],teacherid[3];   //I will be using this array in both addstudents and deletestudents
bool cgpa=false;  //to determine which function the user is calling

using namespace std;

int main();
void addstudent();
void deletestudent();
void calculateCGPA();
void averageCGPA();
void ListPassedStudents();
void ListFailedStudents();
void viewGrades();
void viewCGPA();

string studentpassword;  //this will be used in main, View Grades, and View CGPA

void addteacher(){
    fstream teachers;
    bool isEmpty;   //to check if the file is previously empty or not
    teachers.open("Teachersdata.txt",ios::app);
       if (teachers.is_open()) {
        teachers.seekg(0, ios::end); // Move to the end of the file
        isEmpty= (teachers.tellg() == 0); // Check if position is at the start
    }
    if(teachers.is_open()){   //check if the file has been opened properly
        cout<<setw(50)<<setfill(' ')<<"Teacher(s) records:"<<endl;
        string teacherName,teachercourses,teacherclass;
        int i=1,count=0;
        char choice='y';
        while(true){   //run until the user exits the loop
            if(choice=='n' || choice=='N'){
                break;    
            }
            cout<<"Enter teacher's ID: ";
            cin>>teacherid[count];
             for(int i=0;i<teacherid[count];i++){
                int temp=teacherid[count]%10;
                teacherid[count]/=10;
            }
            //To clear the input buffer upto the newline character
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter teacher's name: ";
            getline(cin,teacherName);
            cout<<"Enter teacher's courses: ";
            getline(cin,teachercourses);
            cout<<"Enter teacher's class: ";
            getline(cin,teacherclass);
           // Display the table header on the console
           cout << "\n\n"
            << setw(10) << left << "ID"            // Left-align each header
            << setw(25) << left << "Name"
            << setw(30) << left << "Course(s)"
            << setw(20) << left << "Class" 
            << endl;
             // If the file is empty and it's the first record, add a header to the file
            if (count == 0 && isEmpty) {
            teachers << setw(10) << left << "ID"
             << setw(25) << left << "Name"
             << setw(30) << left << "Course(s)"
             << setw(20) << left << "Class"
             << endl;
    teachers.flush();
}
            // Display the input data on the console
            cout << setw(10) << left << teacherid[count] // Left-align each data field
             << setw(25) << left << teacherName
             << setw(30) << left << teachercourses
             << setw(20) << left << teacherclass
             << endl;

            // Write the input data to the file
            teachers << setw(10) << left << teacherid[count]
            << setw(25) << left << teacherName
            << setw(30) << left << teachercourses
            << setw(20) << left << teacherclass
            << endl;
            teachers.flush();

            i++;
            count++;
            //Ask the user if he wants to enter another record
            cout<<"\n\nDo you want to enter another record?(Y/N): ";
            cin>>choice;
            //To clear the input buffer upto the newline character
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }else{  //If the file does not open properly then display this
        cout<<"Unable to open the file \"Teachersdata.txt\""<<endl;
        return;
    } //Program executes successfully and displays this
    teachers.close();  //close the txt file
    cout<<"Your data has been scored in the records successfully!"<<endl;
    main();
}

void deleteteacher(){
    fstream teachers;
    ofstream updatedfile;
    int linenumber;
    char c='y';
    while(c=='y' || c=='Y'){
    cout<<"Enter the record number that you want to delete: ";
    cin>>linenumber;

    teachers.open("Teachersdata.txt",ios::in);
    if(teachers.fail()){
      cout<<"Error opening file. Try again";
      return;
    }
    string line;   //to store the strings present in the txt file
    vector<string> lines;   //declaring a dynamic array of type string
    while(getline(teachers,line))  //runs until the last line is met
    lines.push_back(line);   //adds a string to the end of the vector 'lines'
    teachers.close(); 
    //check whether the line that the user wants to delete even exists or not
    if(linenumber<1 || linenumber>lines.size()){  
        cout<<"This line does not exist in the file";
        return;
    }
    //using ios::trunc because we are truncating(erasing some data) in the txt file
    updatedfile.open("Teachersdata.txt",ios::trunc);
    if(updatedfile.fail()){   //display an error message if file fails to open
        cout<<"File failed to open";
        return;
    }
    for(int i=0;i<lines.size();i++){
        //keep writing the strings to the file except for the one user wants to delete
        if(i!=linenumber){   
            updatedfile<<lines[i]<<endl;
        }
    }
    //asking the user if they want to delete another record
    cout<<"Do you want to delete another record?(Y/N): ";
    cin>>c;
    }
    //display a success message at the end
    cout<<"The file has been updated with the changes you just made!";
    //close the file after processing
    updatedfile.close();
    main();
}

int main(){
    int a,n,choice,teachpass;   //n is to choose who the user is i.e; admin,teacher,etc.
    string email,password;


    //display the welcome message
    cout<<setw(40)<<setfill(' ')<<"Welcome to the student management system!"<<endl;
    cout<<"1. Admin"<<"\n"<<"2. Teacher"<<"\n"<<"3. Student"<<"\n"<<"4. Exit"<<endl;
    cin>>n;
    switch(n) {    // Each case for a different user (total of 4)
    case 1: {
        for (int i = 0; i < 3; i++) {  // Maximum of 3 attempts to enter email
            cout << "Enter email: ";
            cin >> email;
            // Iterating through each teacher ID to check if the input email is correct
            if (email == "admin@gmail.com") {
                break;
            }else 
                cout<<"Incorrect email.Try again!"<<endl;
            if (i == 2) {
                cout << "You have exceeded attempts. Terminating program" << endl;
                return 1;
            } else {
                continue;
            }
        }
        for (int i = 0; i < 3; i++) {
            cout << "Enter password: ";  // Maximum of 3 attempts to enter password
            cin >> password;
            if (password == "admin1234") {
                cout << "1. Add Teacher\n2. Delete Teacher\n";
                cin >> choice;
                switch (choice) {
                    case 1:
                        addteacher();
                        break;
                    case 2:
                        deleteteacher();
                        break;
                }
                break;
            }else
                cout<<"Incorrect Password.Try again!"<<endl;
            if (i == 2) {
                cout << "You have exceeded attempts. Terminating program" << endl;
                return 1;
            } else {
                continue;
            }
        }
        break;
    }
    case 2: {
            vector<int> teacherid; // Container to hold teacher IDs
            ifstream teachers("Teachersdata.txt"); // Open the text file
            if (!teachers) {  //Check to ensure the txt file has been opened properly
    cout << "Error: Unable to open file 'Teachersdata.txt'." << endl;
    return 1;
}
string line;
while (getline(teachers, line)) {
    stringstream ss(line); // Create a stringstream to parse the line
    int id;
    ss >> id; // Extract the integer (teacher ID)
    if (ss.fail()) {
        continue; // Skip lines that don’t start with an integer
    }
    teacherid.push_back(id);
}

if (teacherid.empty()) {
    cout << "Error: No valid teacher IDs found in the file." << endl;
    return 1;
}

teachers.close(); // Close the file
if (teacherid.empty()) {
    cout << "Error: No teacher IDs found in the file." << endl;
    return 1;
}
        int idcheck;
        bool tobreak=false;   //to check if we have to break the outer loop
        for (int i = 0; i < 3; i++) {  // Maximum of 3 attempts to enter email
            cout << "Enter email: ";
            cin >> email;
            // Iterating through each teacher ID to check if the input email is correct
            for (int j = 0; j < 3; j++) { 
                if (email == to_string(teacherid[j]) + "@gmail.com"){  // Checking email using the input teacher ID
                    tobreak=true;
                    idcheck=teacherid[j];
                    break;
                }else if(j==2)
                cout<<"Incorrect email.Try again!"<<endl;
            }
                if (i == 2 && !tobreak) {
                    cout << "You have exceeded attempts. Terminating program" << endl;
                    return 1;
                }
             if(tobreak)
                break;
            
        }
        bool passbreak=0;    //to check if we have to break the outer loop
        for (int i = 0; i < 3; i++) {
            cout << "Enter password: ";  // Maximum of 3 attempts to enter password
            cin >> teachpass;
            if (teachpass == idcheck) {  // Checking password using the input teacher ID
                  passbreak=1;
            if(passbreak){
                cout << setw(45) << setfill(' ') << "Successfully logged in!" << endl;
                cout << "1. Add Student\n2. Delete Student\n3. Calculate CGPA\n4. Average CGPA\n"
                     << "5. Calculate Grades\n6. List Passed Students\n7. List failed students" << endl;
                cin >> choice;
                // Adding a nested switch statement to determine which function to call based on user input
                switch (choice) {   
                    case 1:{
                        addstudent();
                        break;
                    }
                    case 2:{
                        deletestudent();
                        break;
                    }
                    case 3:{
                        calculateCGPA();
                        break;
                    }
                    case 4:{
                        averageCGPA();
                        break;
                    }
                    case 6:{
                        ListPassedStudents();
                        break;
                    }
                    case 7:{
                        ListFailedStudents();
                        break;
                    }

                }
            }
                break;
            }else
                cout<<"Incorrect Password.Try again!"<<endl;
            if(passbreak){
                break;
            }
            if (i == 2 && !tobreak) {
                cout << "You have exceeded attempts. Terminating program" << endl;
                return 1;
            } else {
                continue;
            }
           
        }
        break;
    }
    case 3: {
         vector<int> studentid; // Container to hold student IDs
            ifstream students("Students Data.txt"); // Open the text file
            if (!students) {  //Check to ensure the txt file has been opened properly
    cout << "Error: Unable to open file 'Teachersdata.txt'." << endl;
    return 1;
}
string line;
while (getline(students, line)) {
    stringstream ss(line); // Create a stringstream to parse the line
    int id;
    ss >> id; //xxtract the integer (Student ID)
    if (ss.fail()) {
        continue; //skip lines that don’t start with an integer
    }
    studentid.push_back(id);
}

if (studentid.empty()) {
    cout << "Error: No valid Student IDs found in the file." << endl;
    return 1;
}

students.close(); // Close the file
if (studentid.empty()) {
    cout << "Error: No Student IDs found in the file." << endl;
    return 1;
}
        int idcheck;
        bool tobreak=false;   //to check if we have to break the outer loop
        for (int i = 0; i < 30; i++) {  // Maximum of 3 attempts to enter email
            cout << "Enter email: ";
            cin >> email;
            // Iterating through each Student ID to check if the input email is correct
            for (int j = 0; j < 30; j++) { 
                if (email == to_string(studentid[j]) + "@gmail.com"){  // Checking email using the input Student ID
                    tobreak=true;
                    idcheck=studentid[j];
                    break;
                }else if(j==29)
                cout<<"Incorrect email.Try again!"<<endl;
            }
                if (i == 2 && !tobreak) {
                    cout << "You have exceeded attempts. Terminating program" << endl;
                    return 1;
                }
             if(tobreak)
                break;
            
        }
        bool passbreak=0;    //to check if we have to break the outer loop
        for (int i = 0; i < 30; i++) {
            cout << "Enter password: ";  // Maximum of 3 attempts to enter password
            cin>>studentpassword;
            if (studentpassword == to_string(idcheck)) {  // Checking password using the input student ID
                  passbreak=1;
            if(passbreak){
                cout << setw(45) << setfill(' ') << "Successfully logged in!" << endl;
                cout << "1. View Grades\n2. View CGPA"<<endl;
                cin >> choice;
                // Adding a nested switch statement to determine which function to call based on user input
                switch (choice) {   
                    case 1:{
                        viewGrades();
                        break;
                    }
                    case 2:{
                        viewCGPA();
                        break;
                    }

                }
            }
                break;
            }else
                cout<<"Incorrect Password.Try again!"<<endl;
            if(passbreak){
                break;
            }
            if (i == 2 && !tobreak) {
                cout << "You have exceeded attempts. Terminating program" << endl;
                return 1;
            } else {
                continue;
            }
           
        }
        break;
    }
}


   system("pause>0");
    return 0;

}


void addstudent() {
    fstream students;

    // Open the file for both input and output
    students.open("Students Data.txt", ios::in | ios::out | ios::app);
    if (!students.is_open()) {
        cout << "Unable to open the file \"Students Data.txt\"." << endl;
        return;
    }

    //check if the file is empty
    students.seekg(0, ios::end); // Move to the end
    if (students.tellg() == 0) { // If the file is empty
        students << "ID" << setw(25) << "Name" << setw(20) << "Class"
                 << setw(25) << "Course" << setw(15) << "Grade" << endl;
    }
    students.clear(); //clear EOF flag

    //variables for input
    string name, studentClass, courses, grade;
    char choice = 'y';
    int studentID;

    while (choice == 'y' || choice == 'Y') {
        //collect student details
        cout << "Enter Student's ID: ";
        cin >> studentID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        cout << "Enter Student's Name: ";
        getline(cin, name);

        cout << "Enter Student's Class: ";
        getline(cin, studentClass);

        cout << "Enter Student's Registered Courses (separated by commas): ";
        getline(cin, courses);

        // Process each course and grade
        stringstream ss(courses);
        string course;

        while (getline(ss, course, ',')) {
            // Trim spaces
            course.erase(0, course.find_first_not_of(' '));
            course.erase(course.find_last_not_of(' ') + 1);

            cout << "Grade for " << course << ": ";
            getline(cin, grade);

            // Display the record in the console
            cout << "\n"
                 << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Class"
                 << setw(25) << "Course" << setw(15) << "Grade" << endl;
            cout << setw(10) << studentID << setw(25) << name << setw(20) << studentClass
                 << setw(25) << course << setw(15) << grade << endl;

            // Write the record to the file
            students << studentID << setw(25) << name << setw(20) << studentClass
                     << setw(25) << course << setw(15) << grade << endl;
        }

        // Ask if the user wants to add another record
        cout << "\nDo you want to enter another record? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    }

    // Close the file and display success message
    students.close();
    cout << "Your data has been stored successfully!" << endl;
    main();
}


void deletestudent() {
    fstream students;
    ofstream updatedfile;
    string deleteID; 
    char c = 'y';

    while (c == 'y' || c == 'Y') {
        cout << "Enter the ID that you want to delete: ";
        cin >> deleteID;

        // Open the file for reading
        students.open("Students Data.txt", ios::in);
        if (students.fail()) {
            cout << "Error opening file. Try again." << endl;
            return;
        }

        string line;
        vector<string> lines;
        bool idExists = false;
        bool toprow = true; //to track and preserve the top row

        //read all lines from the file into a vector
        while (getline(students, line)) {
            if (toprow) {
                lines.push_back(line);
                toprow = false;
            } else {
                //check if the current line contains the exact ID
                stringstream ss(line);
                string id;
                ss >> id; //extract the ID from the line

                if (id == deleteID) {
                    idExists = true; //found the matching ID, skip this line
                } else {
                    lines.push_back(line); //add non-matching lines to the vector
                }
            }
        }
        students.close();

        //if the ID was not found, notify the user and restart the loop
        if (!idExists) {
            cout << "This ID does not exist in the file." << endl;
            cout << "Do you want to try deleting another record? (Y/N): ";
            cin >> c;
            continue; //skip this iteration since the input id didn't match any pre-existing id
        }

        //open the file for truncation and write the updated lines
        updatedfile.open("Students Data.txt", ios::trunc);
        if (updatedfile.fail()) {
            cout << "File failed to open for writing." << endl;
            return;
        }

        for (const string& entry : lines) {
            updatedfile << entry << endl;
        }

        updatedfile.close();

        cout << "The record with ID " << deleteID << " has been successfully deleted." << endl;
        cout << "Do you want to delete another record? (Y/N): ";
        cin >> c;
    }

    cout << "The file has been updated with the changes you just made!" << endl;
    main();
}



void calculateCGPA(){
string course;
int id,creds,totalcred=0;  //cred to store the credit hours of a course
float cgpa=0,grade;

 vector<int> studentid; // Container to hold Student IDs
            ifstream students("Students data.txt"); // Open the text file
            if (!students) {  //Check to ensure the txt file has been opened properly
    cout << "Error: Unable to open file 'Teachersdata.txt'." << endl;
    return;
}
string line;
while (getline(students, line)) {
    stringstream ss(line); //Create a stringstream to parse the line
    int id;
    ss >> id; //Extract the integer (teacher ID)
    if (ss.fail()) {
        continue; //Skip lines that don’t start with an integer
    }
    studentid.push_back(id);
}

if (studentid.empty()) {
    cout << "Error: No valid student IDs found in the file." << endl;
    return;
}

students.close(); //Close the file
if (studentid.empty()) {
    cout << "Error: No student IDs found in the file." << endl;
    return;
}
char c ='y';
bool idmatch=1;

cout<<"Enter the id of the student you want to calculate the CGPA for: ";
cin>>id;

while(c=='y' || c=='Y'){
for(int i=0;i<30;i++){
    if(id==studentid[i]){
        idmatch=1;
        break;
    }else{
     idmatch=0;
    }
}
if(!idmatch){
    cout<<"No record found!";
    return;
}
cout<<"Enter course (one at a time): ";
getline(cin,course);
cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clear the input buffer
cout<<"Enter credit hours for the course: ";
cin>>creds;
cout<<"Enter the grade points of the student: ";
cin>>grade;

totalcred=totalcred+creds;
cgpa=cgpa+(grade*creds);

cout<<"Do you want to enter another course?(Y/N): ";
cin>>c;

if(c=='n' || c=='N'){
cgpa=cgpa/totalcred;
cout<<"ID"<<setw(30)<<setfill(' ')<<"CGPA"<<endl;
cout<<id<<setw(30)<<setfill(' ')<<cgpa<<endl;
fstream CGPAs;
CGPAs.open("Students CGPA.txt",ios::app);

if (!CGPAs) {
    cout<<"Error opening file for writing!"<<endl;
    return;
}

    CGPAs.seekg(0, ios::end); //move to the end of the file
    bool isEmpty = (CGPAs.tellg() == 0);
    CGPAs.clear(); //clear any eof flags
    CGPAs.seekp(0, ios::end); //position for appending

if(isEmpty){
    CGPAs<<"ID"<<setw(30)<<setfill(' ')<<"CGPA"<<endl;
    CGPAs.flush();
}

CGPAs<<id<<setw(30)<<setfill(' ')<<cgpa<<endl;
CGPAs.flush();
CGPAs.close();
}
}
cout<<"Do you want to calculate CGPA for another student?(Y/N) ";
cin>>c;
if(c=='y' || c=='Y'){
    calculateCGPA();
}else{
    cout<<"All your data has been stored succcessfully! ";
    return;
}

main();

}


void averageCGPA(){
     ifstream results;
     results.open("Students CGPA.txt");   //Open file using ifstream since we are only reading the file
    if (!results) {
        cout << "Error: Unable to open file 'Students CGPA.txt'." << endl;
        return;
    }

    string line;
    getline(results, line); // Skip the header row

    vector<float> cgpas;
    while (getline(results, line)) {
        stringstream ss(line);
        int id;
        float cgpa;

        ss >> id;   // Read the student ID (skip it)
        ss >> cgpa; // Read the CGPA

        if (!ss.fail()) {
            cgpas.push_back(cgpa);
        }
    }
    results.close();

    if (cgpas.empty()) {
        cout << "No CGPA data found in the file." << endl;
        return;
    }

    // Calculate average
    float sum = 0;
    for (float cgpa : cgpas) {
        sum += cgpa;
    }
    float average = sum / cgpas.size();

    cout << "The average CGPA is: " << average << endl;
    main();
}

void ListPassedStudents(){
   ifstream CGPAs;
     CGPAs.open("Students CGPA.txt");   //Open file using ifstream since we are only reading the file
    if (!CGPAs) {
        cout << "Error: Unable to open file 'Students CGPA.txt'." << endl;
        return;
    }

    string line;
    getline(CGPAs, line); // Skip the header row

    vector<float> cgpas;  //vector to hold all the CGPA(s)
    vector<double> ids;   //vector to hold all student ids
    while (getline(CGPAs, line)) {
        stringstream ss(line);
        int id;
        float cgpa;

        ss >> id;   // Read the student ID (skip it)
        ss >> cgpa; // Read the CGPA

        if (!ss.fail()) {
            ids.push_back(id);
            cgpas.push_back(cgpa);
        }
    }
    CGPAs.close();

    if (cgpas.empty()) {
        cout << "No CGPA data found in the file." << endl;
        return;
    }
    cout<<"ID"<<setw(36)<<setfill(' ')<<"CGPA"<<endl;
    for(int i=0;i<cgpas.size();i++){
        if(cgpas[i]>2.0){
         cout<<ids[i]<<setw(36)<<setfill(' ')<<cgpas[i]<<endl;
        }else{
            continue;
        }
}
main();
}

void ListFailedStudents(){
   ifstream CGPAs;
     CGPAs.open("Students CGPA.txt");   //Open file using ifstream since we are only reading the file
    if (!CGPAs) {
        cout << "Error: Unable to open file 'Students CGPA.txt'." << endl;
        return;
    }

    string line;
    getline(CGPAs, line); // Skip the header row

    vector<float> cgpas;  //vector to hold all the CGPA(s)
    vector<double> ids;   //vector to hold all student ids
    while (getline(CGPAs, line)) {
        stringstream ss(line);
        int id;
        float cgpa;

        ss >> id;   // Read the student ID (skip it)
        ss >> cgpa; // Read the CGPA

        if (!ss.fail()) {
            ids.push_back(id);
            cgpas.push_back(cgpa);
        }
    }
    CGPAs.close();

    if (cgpas.empty()) {
        cout << "No CGPA data found in the file." << endl;
        return;
    }
    cout<<"ID"<<setw(36)<<setfill(' ')<<"CGPA"<<endl;
    for(int i=0;i<cgpas.size();i++){
        if(cgpas[i]>2.0){
         cout<<ids[i]<<setw(36)<<setfill(' ')<<cgpas[i]<<endl;
        }else{
            continue;
        }
}
main();
}

void viewGrades() {
    ifstream students;
    bool idExists=0;

    students.open("Students Data.txt"); //open file using ifstream since we are only reading the file

    if (!students) {
        cout << "Error: Unable to open file 'Students Data.txt'." << endl;
        return;
    }
    string line;
    getline(students, line); //skip the header row

    cout<<setw(25)<<"Course"<<setw(15)<<"Grade"<<endl; //display header for console output
    while(getline(students,line)) {
        stringstream ss(line);
        string id,name,studentClass,course,grade;
        //read the columns: ID, Name, Student Class
        ss >> id;
        ss >> name;
        ss >> studentClass;

        //skip fixed-width columns and read the rest for courses and grades
        while (getline(ss, course, ',')) {
            // Trim spaces
            course.erase(0, course.find_first_not_of(' '));
            course.erase(course.find_last_not_of(' ') + 1);

            //read grade associated with course
            getline(ss, grade);  // Take user input for grade

            //display the course and grade
            if (id == studentpassword) {
                cout << setw(25) << course << setw(15) << grade << endl;
                idExists = 1;
            }
        }
    }

    students.close(); //close the file
    if (!idExists) {
        cout << "ID does not exist in the records!" << endl;
        return;
    }
    main();
}


void viewCGPA(){
 ifstream CGPAs;
     CGPAs.open("Students CGPA.txt");   //Open file using ifstream since we are only reading the file
    if (!CGPAs) {
        cout << "Error: Unable to open file 'Students CGPA.txt'." << endl;
        return;
    }

    string line;
    getline(CGPAs, line); // Skip the header row

    vector<float> cgpas;  //vector to hold all the CGPA(s)
    vector<double> ids;   //vector to hold all student ids
    while (getline(CGPAs, line)) {
        stringstream ss(line);
        int id;
        float cgpa;

        ss >> id;   // Read the student ID 
        ss >> cgpa; // Read the CGPA

        if (!ss.fail()) {
            ids.push_back(id);
            cgpas.push_back(cgpa);
        }
    }
    CGPAs.close();

    if (cgpas.empty()) {
        cout << "No CGPA data found in the file." << endl;
        return;
    }
    bool found=0;
    int stupass = stoi(studentpassword);  // Convert string to int
    for(int i=0;i<ids.size();i++){
    if(ids[i]==stupass){
     cout<<ids[i]<<setw(30)<<cgpas[i]<<endl;
     found=1;
     break;
    }
    }
    if(!found){
        cout<<"No record found for provided ID"<<endl;
        return;
    }
    main();
}