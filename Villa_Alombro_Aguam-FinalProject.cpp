#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Function to check if the name is valid (only letters and spaces)
bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false; // makes sure name only has letters and spaces
    }
    return !name.empty(); // name cannot be empty
}

// Function to check if the ID is valid (numbers and dashes only)
bool isValidID(const string& id) {
    for (char c : id) {
        if (!isdigit(c) && c != '-') return false; // only numbers and dashes are allowed
    }
    return !id.empty(); // ID cannot be empty
}

// Function to get a valid name
string getValidName(string prompt) {
    string name;
    while (true) {
        cout << prompt;
        getline(cin, name);
        if (isValidName(name)) return name; // returns valid name
        cout << "Invalid input. Please enter your name with letters and spaces only.\n";
    }
}

// Function to get a valid ID
string getValidID(string prompt) {
    string id;
    while (true) {
        cout << prompt;
        getline(cin, id);
        if (isValidID(id)) return id; // returns valid ID
        cout << "Invalid input. Enter numbers with dashes or just numbers (like 06-2024-017).\n";
    }
}

// Function to get a valid age (only numbers)
int getValidInt(string prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) { // checks if every character is a number
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            value = stoi(input);
            if (value >= 0) return value; // age must be zero or higher
        }

        cout << "Invalid input. Please enter numbers only (no dashes or letters).\n";
    }
}

// Function to get a valid grade level (1-12)
int getValidGradeLevel(string prompt) {
    string input;
    int level;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) { // checks if grade level has only numbers
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            level = stoi(input);
            if (level >= 1 && level <= 12) return level; // grade level must be 1 to 12
        }

        cout << "Invalid input. Please enter a grade level from 1 to 12 (numbers only).\n";
    }
}

// Advanced Feature C: Input Validation
// Ensures all grades are entered between 0 and 100 (with re-entry until valid).
float getValidGrade(string prompt) {
    string input;
    float grade;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c) && c != '.') { // checks if grade has only digits and maybe a decimal
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            grade = stof(input);
            if (grade >= 0 && grade <= 100) return grade; // grade must be between 0 and 100
        }

        cout << "Invalid input. Please enter a grade between 0 and 100.\n";
    }
}

// Function to add suffix to grade level like 1st, 2nd, 3rd, etc
string getGradeSuffix(int gradeLevel) {
    if (gradeLevel == 1) return "1st Grade";
    if (gradeLevel == 2) return "2nd Grade";
    if (gradeLevel == 3) return "3rd Grade";
    return to_string(gradeLevel) + "th Grade"; // adds “th” for all the other grade levels
}

// This finds the average grade.
float calculateAverage(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return (mathGrade + scienceGrade + englishGrade + historyGrade + artGrade) / 5;
}

// This finds the highest grade.
float findHighest(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return max({mathGrade, scienceGrade, englishGrade, historyGrade, artGrade});
}

// This finds the lowest grade.
float findLowest(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    return min({mathGrade, scienceGrade, englishGrade, historyGrade, artGrade});
}

// This gives the equivalent grade (1.00 - 5.00, rounded scale).
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

// This counts how many passing grades (>=60) there are.
int countPassing(float mathGrade, float scienceGrade, float englishGrade, float historyGrade, float artGrade){
    float grades[] = {mathGrade, scienceGrade, englishGrade, historyGrade, artGrade};
    
    int count_grade = 0;
    for (float i : grades){
        if (i >= 60.0)
           count_grade++; 
    }
    return count_grade;
}

// Advanced Feature B: Director's List Check
// Checks if the student's GWA is <= 1.5 and shows a congratulatory message.
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
    cout << "           STUDENT REPORT CARD            \n";
    cout << "========================================\n";
    cout << "STUDENT INFORMATION\n";
    cout << "Name: " << studentName << endl;
    cout << "ID: " << studentID << endl;
    cout << "Age: " << age << " years old\n";
    cout << "Grade Level: " << getGradeSuffix(gradeLevel) << "\n";
    cout << "Birth Year: " << (2025 - age) << "\n\n";
    
    float average_grade = calculateAverage(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);

    // Advanced Feature A: GPA Converter
    // Converts the average grade into an exact GWA with decimals.
    float real_gwa = 5.0f - (average_grade / 25.0f); 

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
    cout << "Average Grade: " << fixed << setprecision(2) << average_grade << "%" << endl;
    cout << "Grade Equivalent: " << fixed << setprecision(3) << real_gwa << endl;

    // Highest grade with subject
    if (highest_grade == mathGrade) cout << "Highest Grade: " << highest_grade << "% (Math)" << endl;
    else if (highest_grade == scienceGrade) cout << "Highest Grade: " << highest_grade << "% (Science)" << endl;
    else if (highest_grade == englishGrade) cout << "Highest Grade: " << highest_grade << "% (English)" << endl;
    else if (highest_grade == historyGrade) cout << "Highest Grade: " << highest_grade << "% (History)" << endl;
    else if (highest_grade == artGrade) cout << "Highest Grade: " << highest_grade << "% (Art)" << endl;

    // Lowest grade with subject
    if (lowest_grade == mathGrade) cout << "Lowest Grade: " << lowest_grade << "% (Math)" << endl;
    else if (lowest_grade == scienceGrade) cout << "Lowest Grade: " << lowest_grade << "% (Science)" << endl;
    else if (lowest_grade == englishGrade) cout << "Lowest Grade: " << lowest_grade << "% (English)" << endl;
    else if (lowest_grade == historyGrade) cout << "Lowest Grade: " << lowest_grade << "% (History)" << endl;
    else if (lowest_grade == artGrade) cout << "Lowest Grade: " << lowest_grade << "% (Art)" << endl;

    cout << "Subjects Passing: " << passing_grades << " out of 5" << endl;

    // Show the real GWA with decimals
    cout << "\nGWA: " << fixed << setprecision(3) << real_gwa << endl;

    // Checks if you are on the director's list
    cout << "Director's List Status: ";
    if (isOnDirectorsList(real_gwa)) {
        cout << "YES (Congratulations!)" << endl;
    } else {
        cout << "NO" << endl;
    }

    cout << "========================================\n";
    return 0;
}
