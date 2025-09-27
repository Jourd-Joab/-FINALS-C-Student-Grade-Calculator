#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// This function checks if the name only contains letters and spaces.
bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false; // invalid if it has numbers or symbols
    }
    return !name.empty(); // name cannot be blank
}

// This function checks if the student ID only has numbers and dashes.
bool isValidID(const string& id) {
    for (char c : id) {
        if (!isdigit(c) && c != '-') return false; // anything other than digits or dash is invalid
    }
    return !id.empty(); // ID cannot be blank
}

// This function asks for a name and keeps asking until it is valid.
string getValidName(string prompt) {
    string name;
    while (true) {
        cout << prompt;
        getline(cin, name);
        if (isValidName(name)) return name; // return valid name
        cout << "Invalid input. Please enter your name with letters and spaces only.\n";
    }
}

// This function asks for a student ID and keeps asking until it is valid.
string getValidID(string prompt) {
    string id;
    while (true) {
        cout << prompt;
        getline(cin, id);
        if (isValidID(id)) return id; // return valid ID
        cout << "Invalid input. Enter numbers with dashes or just numbers (like 06-2024-017).\n";
    }
}

// This function makes sure the input is a valid age (numbers only).
int getValidInt(string prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) { // only numbers are allowed for age
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            value = stoi(input);
            if (value >= 0) return value; // age has to be zero or more
        }

        cout << "Invalid input. Please enter numbers only (no dashes or letters).\n";
    }
}

// This function checks if the grade level is valid (must be 1-12).
int getValidGradeLevel(string prompt) {
    string input;
    int level;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) { // only numbers are allowed
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            level = stoi(input);
            if (level >= 1 && level <= 12) return level; // only accepts grades 1 to 12
        }

        cout << "Invalid input. Please enter a grade level from 1 to 12 (numbers only).\n";
    }
}

// This function checks if the subject grade is between 0 and 100.
float getValidGrade(string prompt) {
    string input;
    float grade;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c) && c != '.') { // allows numbers and one decimal point
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            grade = stof(input);
            if (grade >= 0 && grade <= 100) return grade; // grade must be in the range 0-100
        }

        cout << "Invalid input. Please enter a grade between 0 and 100.\n";
    }
}

// This function adds the right suffix to the grade level like 1st, 2nd, 3rd, etc.
string getGradeSuffix(int gradeLevel) {
    if (gradeLevel == 1) return "1st Grade";
    if (gradeLevel == 2) return "2nd Grade";
    if (gradeLevel == 3) return "3rd Grade";
    return to_string(gradeLevel) + "th Grade"; // for all other grade levels
}

// This function calculates the average of all five subject grades.
float calculateAverage(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return (mathGrade + scienceGrade + englishGrade + historyGrade + artGrade) / 5;
}

// This function finds the highest grade among the five subjects.
float findHighest(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return max({mathGrade, scienceGrade, englishGrade, historyGrade, artGrade});
}

// This function finds the lowest grade among the five subjects.
float findLowest(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return min({mathGrade, scienceGrade, englishGrade, historyGrade, artGrade});
}

// This function converts the average grade to its grade equivalent (1.00 to 5.00).
float getGrade(float average){
    if (average >= 96 && average <= 100) {
        return 1.00f;
    }
    else if (average >= 94 && average <= 95.9) {
        return 1.25f;
    }
    else if (average >= 92 && average <= 93.9) {
        return 1.50f;
    }
    else if (average >= 90 && average <= 91.9) {
        return 1.75f;
    }
    else if (average >= 88 && average <= 89.9) {
        return 2.00f;
    }
    else if (average >= 86 && average <= 87.9) {
        return 2.25f;
    }
    else if (average >= 84 && average <= 85.9) {
        return 2.50f;
    }
    else if (average >= 82 && average <= 83.9) {
        return 2.75f;
    }
    else if (average >= 80 && average <= 81.9){
        return 3.00f;
    }
    else if (average >= 0 && average <= 79.9) {
        return 5.00f;
    }
    else{
        cout << "ERROR: Invalid input" << endl;
        return 0;
    }
}

// This function counts how many subjects are passing (grades 60 and above).
int countPassing(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    float grades[] = {mathGrade, scienceGrade, englishGrade, historyGrade, artGrade};
    
    int count_grade = 0;
    for (float i : grades){
        if (i >= 60.0)
           count_grade++; 
    }
    return count_grade;
}

// This function checks if the student's GWA qualifies for the Director's List.
bool isOnDirectorsList(float gwa) {
    return gwa <= 1.5;
}

int main(){
    cout << "========================================\n";
    cout << "        STUDENT GRADE CALCULATOR\n";
    cout << "========================================\n\n";
    
    cout << "=== STUDENT PROFILE SETUP ===\n";
    string studentName = getValidName("Enter student name: ");
    string studentID = getValidID("Enter student ID: ");
    int age = getValidInt("Enter student age (numbers only): ");
    int gradeLevel = getValidGradeLevel("Enter grade level (1-12): ");

    cout << "\nProfile created successfully!\n\n";
    
    cout << "=== GRADE ENTRY ===\n";
    float mathGrade = getValidGrade("Enter Math grade (0-100): ");
    float scienceGrade = getValidGrade("Enter Science grade (0-100): ");
    float englishGrade = getValidGrade("Enter English grade (0-100): ");
    float historyGrade = getValidGrade("Enter History grade (0-100): ");
    float artGrade = getValidGrade("Enter Art grade (0-100): ");

    cout << "\nGrades recorded successfully!\n\n";

    cout << "========================================\n";
    cout << "          STUDENT REPORT CARD            \n";
    cout << "========================================\n";
    cout << "STUDENT INFORMATION\n";
    cout << "Name: " << studentName << endl;
    cout << "ID: " << studentID << endl;
    cout << "Age: " << age << " years old\n";
    cout << "Grade Level: " << getGradeSuffix(gradeLevel) << "\n";
    cout << "Birth Year: " << (2025 - age) << "\n\n";
    
    float average_grade = calculateAverage(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    float equivalent_grade = getGrade(average_grade);
    float highest_grade = findHighest(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    float lowest_grade = findLowest(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    int passing_grades = countPassing(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    
    cout << "SUBJECT GRADES:" << endl;
    cout << "Math: " << mathGrade << "%" << endl;
    cout << "Science: " << scienceGrade << "%" << endl;
    cout << "English: " << englishGrade << "%" << endl;
    cout << "History: " << historyGrade << "%" << endl;
    cout << "Art: " << artGrade << "%" << endl;
    cout << endl;
    cout << "GRADE STATISTICS:" << endl;
    cout << "Average Grade: " << average_grade << "%" << endl;
    cout << "Grade Equivalent: " << fixed << setprecision(2) << equivalent_grade << endl;
    cout << "Highest Grade: " << highest_grade << "%" << endl;
    cout << "Lowest Grade: " << lowest_grade << "%" << endl;
    cout << "Subjects Passed: " << passing_grades << " out of 5" << endl;

    // This section checks if the student is qualified for the Director's List.
    cout << fixed << setprecision(3);
    cout << "\nGWA: " << equivalent_grade << endl;
    cout << "Director's List Status: ";
    if (isOnDirectorsList(equivalent_grade)) {
        cout << "YES (Congratulations!)" << endl;
    } else {
        cout << "NO" << endl;
    }

    cout << "========================================\n";
    return 0;
}
