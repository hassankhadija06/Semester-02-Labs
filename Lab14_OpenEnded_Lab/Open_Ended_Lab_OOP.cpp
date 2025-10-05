#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

// ================= STRUCTURES =================
struct Appointment {
    string appointmentId;
    string patientId;
    string therapistId;
    string date;
    string time;
    string status;
};

struct MoodEntry {
    string patientId;
    string date;
    int moodRating;
    string notes;
};

struct QuestionnaireResult {
    string patientId;
    string date;
    int totalScore;
    string riskLevel;
};

// ================= DISPLAY MANAGER =================
class DisplayManager {
public:
    static void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static void setColor(int color) {
        #ifdef _WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, color);
        #endif
    }

    static void resetColor() {
        #ifdef _WIN32
            setColor(7);
        #endif
    }

    static void displayWelcomeArt() {
        setColor(11);

    // Enable UTF-8 in Windows console
    SetConsoleOutputCP(CP_UTF8);

    cout << u8"░███     ░███ ░██████░███    ░██ ░███████     ░██████     ░███    ░█████████  ░██████████ \n";
    cout << u8"░████   ░████   ░██  ░████   ░██ ░██   ░██   ░██   ░██   ░██░██   ░██     ░██ ░██         \n";
    cout << u8"░██░██ ░██░██   ░██  ░██░██  ░██ ░██    ░██ ░██         ░██  ░██  ░██     ░██ ░██         \n";
    cout << u8"░██ ░████ ░██   ░██  ░██ ░██ ░██ ░██    ░██ ░██        ░█████████ ░█████████  ░█████████  \n";
    cout << u8"░██  ░██  ░██   ░██  ░██  ░██░██ ░██    ░██ ░██        ░██    ░██ ░██   ░██   ░██         \n";
    cout << u8"░██       ░██   ░██  ░██   ░████ ░██   ░██   ░██   ░██ ░██    ░██ ░██    ░██  ░██         \n";
    cout << u8"░██       ░██ ░██████░██    ░███ ░███████     ░██████  ░██    ░██ ░██     ░██ ░██████████ \n";
    cout << "\n\n\n";



        resetColor();
    }

    static void displayCenterInfo() {
        setColor(10);
        cout << "\n\t MIND CARE MENTAL HEALTH CENTER " << endl;
        setColor(14);
        cout << "\t    \"Where Mental Wellness Matters\"\n" << endl;
        setColor(7);
        cout << "\t══════════════════════════════════════════" << endl;
        resetColor();
    }

    static void printHeader(const string& title) {
        clearScreen();
        displayWelcomeArt();
        displayCenterInfo();
        
        setColor(11);
        cout << "\n╔══════════════════════════════════════════════════╗" << endl;
        cout << "║" << setw((50 - title.length()) / 2 + title.length()) 
                  << title << setw(50 - ((50 - title.length()) / 2 + title.length())) << "║" << endl;
        cout << "╚══════════════════════════════════════════════════╝" << endl;
        resetColor();
    }

    static void printSuccess(const string& message) {
        setColor(10);
        cout << "✅ " << message << endl;
        resetColor();
    }

    static void printError(const string& message) {
        setColor(12);
        cout << "❌ " << message << endl;
        resetColor();
    }

    static void printWarning(const string& message) {
        setColor(14);
        cout << "️  "<< message << endl;
        resetColor();
    }

    static void printMenuOption(int number, const string& option) {
        setColor(11);
        cout << number << ". ";
        setColor(7);
        cout << option << endl;
    }

    static void loadingAnimation(int seconds) {
        cout << "\nLoading ";
        for (int i = 0; i < seconds * 2; i++) {
            cout << "▓";
            cout.flush();
            #ifdef _WIN32
                Sleep(500);
            #else
                usleep(500000);
            #endif
        }
        cout << endl;
    }

    static void pressEnterToContinue() {
        setColor(8);
        cout << "\n📋 Press Enter to continue...";
        resetColor();
        cin.ignore();
        cin.get();
    }

    static void displayPatientArt() {
        setColor(11);

    cout << "            ░█████████     ░███    ░██████████░██████░██████████ ░███    ░██ ░██████████                " << endl;
    cout << "            ░██     ░██   ░██░██       ░██      ░██  ░██         ░████   ░██     ░██                    " << endl;
    cout << "            ░██     ░██  ░██  ░██      ░██      ░██  ░██         ░██░██  ░██     ░██                    " << endl;
    cout << "            ░█████████  ░█████████     ░██      ░██  ░█████████  ░██ ░██ ░██     ░██                    " << endl;
    cout << "            ░██         ░██    ░██     ░██      ░██  ░██         ░██  ░██░██     ░██                    " << endl;
    cout << "            ░██         ░██    ░██     ░██      ░██  ░██         ░██   ░████     ░██                    " << endl;
    cout << "            ░██         ░██    ░██     ░██    ░██████░██████████ ░██    ░███     ░██                    " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "░███████      ░███      ░██████   ░██     ░██ ░████████     ░██████      ░███    ░█████████  ░███████   " << endl;
    cout << "░██   ░██    ░██░██    ░██   ░██  ░██     ░██ ░██    ░██   ░██   ░██    ░██░██   ░██     ░██ ░██   ░██  " << endl;
    cout << "░██    ░██  ░██  ░██  ░██         ░██     ░██ ░██    ░██  ░██     ░██  ░██  ░██  ░██     ░██ ░██    ░██ " << endl;
    cout << "░██    ░██ ░█████████  ░████████  ░██████████ ░████████   ░██     ░██ ░█████████ ░█████████  ░██    ░██ " << endl;
    cout << "░██    ░██ ░██    ░██         ░██ ░██     ░██ ░██     ░██ ░██     ░██ ░██    ░██ ░██   ░██   ░██    ░██ " << endl;
    cout << "░██   ░██  ░██    ░██  ░██   ░██  ░██     ░██ ░██     ░██  ░██   ░██  ░██    ░██ ░██    ░██  ░██   ░██  " << endl;
    cout << "░███████   ░██    ░██   ░██████   ░██     ░██ ░█████████    ░██████   ░██    ░██ ░██     ░██ ░███████   " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;



        resetColor();
    }

    static void displayTherapistArt() {
        setColor(10);

    cout << "░██████████░██     ░██ ░██████████ ░█████████     ░███    ░█████████  ░██████  ░██████   ░██████████    " << endl;
    cout << "    ░██    ░██     ░██ ░██         ░██     ░██   ░██░██   ░██     ░██   ░██   ░██   ░██      ░██        " << endl;
    cout << "    ░██    ░██     ░██ ░██         ░██     ░██  ░██  ░██  ░██     ░██   ░██  ░██             ░██        " << endl;
    cout << "    ░██    ░██████████ ░█████████  ░█████████  ░█████████ ░█████████    ░██   ░████████      ░██        " << endl;
    cout << "    ░██    ░██     ░██ ░██         ░██   ░██   ░██    ░██ ░██           ░██          ░██     ░██        " << endl;
    cout << "    ░██    ░██     ░██ ░██         ░██    ░██  ░██    ░██ ░██           ░██   ░██   ░██      ░██        " << endl;
    cout << "    ░██    ░██     ░██ ░██████████ ░██     ░██ ░██    ░██ ░██         ░██████  ░██████       ░██        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "░███████      ░███      ░██████   ░██     ░██ ░████████     ░██████      ░███    ░█████████  ░███████   " << endl;
    cout << "░██   ░██    ░██░██    ░██   ░██  ░██     ░██ ░██    ░██   ░██   ░██    ░██░██   ░██     ░██ ░██   ░██  " << endl;
    cout << "░██    ░██  ░██  ░██  ░██         ░██     ░██ ░██    ░██  ░██     ░██  ░██  ░██  ░██     ░██ ░██    ░██ " << endl;
    cout << "░██    ░██ ░█████████  ░████████  ░██████████ ░████████   ░██     ░██ ░█████████ ░█████████  ░██    ░██ " << endl;
    cout << "░██    ░██ ░██    ░██         ░██ ░██     ░██ ░██     ░██ ░██     ░██ ░██    ░██ ░██   ░██   ░██    ░██ " << endl;
    cout << "░██   ░██  ░██    ░██  ░██   ░██  ░██     ░██ ░██     ░██  ░██   ░██  ░██    ░██ ░██    ░██  ░██   ░██  " << endl;
    cout << "░███████   ░██    ░██   ░██████   ░██     ░██ ░█████████    ░██████   ░██    ░██ ░██     ░██ ░███████   " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;
    cout << "                                                                                                        " << endl;



        resetColor();
    }

    static void displayReceptionistArt() {
        setColor(13);

    cout << "░█████████  ░██████████   ░██████  ░██████████ ░█████████  ░██████████░██████  ░██████   ░███    ░██ ░██████  ░██████   ░██████████" << endl;
    cout << "░██     ░██ ░██          ░██   ░██ ░██         ░██     ░██     ░██      ░██   ░██   ░██  ░████   ░██   ░██   ░██   ░██      ░██    " << endl;
    cout << "░██     ░██ ░██         ░██        ░██         ░██     ░██     ░██      ░██  ░██     ░██ ░██░██  ░██   ░██  ░██             ░██    " << endl;
    cout << "░█████████  ░█████████  ░██        ░█████████  ░█████████      ░██      ░██  ░██     ░██ ░██ ░██ ░██   ░██   ░████████      ░██    " << endl;
    cout << "░██   ░██   ░██         ░██        ░██         ░██             ░██      ░██  ░██     ░██ ░██  ░██░██   ░██          ░██     ░██    " << endl;
    cout << "░██    ░██  ░██          ░██   ░██ ░██         ░██             ░██      ░██   ░██   ░██  ░██   ░████   ░██   ░██   ░██      ░██    " << endl;
    cout << "░██     ░██ ░██████████   ░██████  ░██████████ ░██             ░██    ░██████  ░██████   ░██    ░███ ░██████  ░██████       ░██    " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "            ░███████      ░███      ░██████   ░██     ░██ ░████████     ░██████      ░███    ░█████████  ░███████                  " << endl;
    cout << "            ░██   ░██    ░██░██    ░██   ░██  ░██     ░██ ░██    ░██   ░██   ░██    ░██░██   ░██     ░██ ░██   ░██                 " << endl;
    cout << "            ░██    ░██  ░██  ░██  ░██         ░██     ░██ ░██    ░██  ░██     ░██  ░██  ░██  ░██     ░██ ░██    ░██                " << endl;
    cout << "            ░██    ░██ ░█████████  ░████████  ░██████████ ░████████   ░██     ░██ ░█████████ ░█████████  ░██    ░██                " << endl;
    cout << "            ░██    ░██ ░██    ░██         ░██ ░██     ░██ ░██     ░██ ░██     ░██ ░██    ░██ ░██   ░██   ░██    ░██                " << endl;
    cout << "            ░██   ░██  ░██    ░██  ░██   ░██  ░██     ░██ ░██     ░██  ░██   ░██  ░██    ░██ ░██    ░██  ░██   ░██                 " << endl;
    cout << "            ░███████   ░██    ░██   ░██████   ░██     ░██ ░█████████    ░██████   ░██    ░██ ░██     ░██ ░███████                  " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;


        resetColor();
    }

    static void displayGoodbyeArt() {
        setColor(14);


    cout << "  ░██████    ░██████     ░██████   ░███████      ░████████   ░██     ░██ ░██████████ " << endl;
    cout << " ░██   ░██  ░██   ░██   ░██   ░██  ░██   ░██     ░██    ░██   ░██   ░██  ░██         " << endl;
    cout << "░██        ░██     ░██ ░██     ░██ ░██    ░██    ░██    ░██    ░██ ░██   ░██         " << endl;
    cout << "░██  █████ ░██     ░██ ░██     ░██ ░██    ░██    ░████████      ░████    ░█████████  " << endl;
    cout << "░██     ██ ░██     ░██ ░██     ░██ ░██    ░██    ░██     ░██     ░██     ░██         " << endl;
    cout << " ░██  ░███  ░██   ░██   ░██   ░██  ░██   ░██     ░██     ░██     ░██     ░██         " << endl;
    cout << "  ░█████░█   ░██████     ░██████   ░███████      ░█████████      ░██     ░██████████ " << endl;
    cout << "                                                                                     " << endl;
    cout << "                                                                                     " << endl;
    cout << "                                                                                     " << endl;




        resetColor();
    }
};

// ================= UTILITY FUNCTIONS =================
vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    stringstream date;
    date << (now->tm_year + 1900) << '-' 
         << setw(2) << setfill('0') << (now->tm_mon + 1) << '-'
         << setw(2) << setfill('0') << now->tm_mday;
    return date.str();
}

// ================= USER CLASS =================
class User {
protected:
    string username;
    string password;
    string role;
    string name;

public:
    User(const string& uname = "", const string& pwd = "", const string& r = "", const string& n = "")
        : username(uname), password(pwd), role(r), name(n) {}

    virtual ~User() {}
    virtual void displayMenu() = 0;

    bool login(const string& uname, const string& pwd) {
        return (username == uname && password == pwd);
    }

    void logout() {
        DisplayManager::clearScreen();
        DisplayManager::displayGoodbyeArt();
        cout << "\nLogging out user: " << username << endl;
        DisplayManager::loadingAnimation(2);
    }

    string getUsername() const { return username; }
    string getRole() const { return role; }
    string getName() const { return name; }

    static void saveUserToFile(const User& user) {
        ofstream file("users.txt", ios::app);
        if (file.is_open()) {
            file << user.username << "," << user.password << "," << user.role << "," << user.name << "\n";
            file.close();
        }
    }

    static User* authenticateUser(const string& username, const string& password);
};

// ================= APPOINTMENT MANAGER =================
class AppointmentManager {
public:
    static bool scheduleAppointment(const string& patientId, const string& therapistId, 
                                  const string& date, const string& time) {
        if (checkConflict(therapistId, date, time)) {
            return false;
        }
        
        Appointment appointment;
        appointment.appointmentId = "APP" + to_string(rand() % 10000);
        appointment.patientId = patientId;
        appointment.therapistId = therapistId;
        appointment.date = date;
        appointment.time = time;
        appointment.status = "Scheduled";
        
        saveAppointmentToFile(appointment);
        return true;
    }

    static bool checkConflict(const string& therapistId, const string& date, const string& time) {
        ifstream file("appointments.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 6) {
                if (tokens[2] == therapistId && tokens[3] == date && tokens[4] == time && tokens[5] != "Cancelled") {
                    return true;
                }
            }
        }
        return false;
    }

    static vector<Appointment> getAppointmentsByPatient(const string& patientId) {
        vector<Appointment> appointments;
        ifstream file("appointments.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 6) {
                if (tokens[1] == patientId) {
                    Appointment app;
                    app.appointmentId = tokens[0];
                    app.patientId = tokens[1];
                    app.therapistId = tokens[2];
                    app.date = tokens[3];
                    app.time = tokens[4];
                    app.status = tokens[5];
                    appointments.push_back(app);
                }
            }
        }
        return appointments;
    }

    static vector<Appointment> getAppointmentsByTherapist(const string& therapistId) {
        vector<Appointment> appointments;
        ifstream file("appointments.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 6) {
                if (tokens[2] == therapistId) {
                    Appointment app;
                    app.appointmentId = tokens[0];
                    app.patientId = tokens[1];
                    app.therapistId = tokens[2];
                    app.date = tokens[3];
                    app.time = tokens[4];
                    app.status = tokens[5];
                    appointments.push_back(app);
                }
            }
        }
        return appointments;
    }

    static void saveAppointmentToFile(const Appointment& appointment) {
        ofstream file("appointments.txt", ios::app);
        if (file.is_open()) {
            file << appointment.appointmentId << "," << appointment.patientId << "," 
                 << appointment.therapistId << "," << appointment.date << "," 
                 << appointment.time << "," << appointment.status << "\n";
            file.close();
        }
    }
};

// ================= MOOD TRACKER =================
class MoodTracker {
public:
    static void addMoodEntry(const string& patientId, int rating, const string& notes) {
        MoodEntry entry;
        entry.patientId = patientId;
        entry.date = getCurrentDate();
        entry.moodRating = rating;
        entry.notes = notes;
        
        saveMoodEntryToFile(entry);
    }

    static vector<MoodEntry> getMoodHistory(const string& patientId) {
        vector<MoodEntry> history;
        ifstream file("mood_entries.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 4) {
                if (tokens[0] == patientId) {
                    MoodEntry entry;
                    entry.patientId = tokens[0];
                    entry.date = tokens[1];
                    entry.moodRating = stoi(tokens[2]);
                    entry.notes = tokens[3];
                    history.push_back(entry);
                }
            }
        }
        return history;
    }

    static void analyzeMoodTrends(const string& patientId) {
        auto history = getMoodHistory(patientId);
        if (history.empty()) {
            cout << "No mood data available." << endl;
            return;
        }
        
        cout << " Mood History:"<< endl;
        for (const auto& entry : history) {
            cout << " Date: "<< entry.date << " | ⭐ Rating: " << entry.moodRating 
                      << " |  Notes: " << entry.notes << endl;
        }
        
        double average = 0.0;
        for (const auto& entry : history) {
            average += entry.moodRating;
        }
        average /= history.size();
        
        cout << "\n📈 Average Mood Rating: " << fixed << setprecision(1) << average << endl;
        
        if (average < 4) {
            DisplayManager::printWarning("Trend: Low mood detected. Consider scheduling a session.");
        } else if (average > 7) {
            DisplayManager::printSuccess("Trend: Positive mood pattern observed. ");
        } else {
            cout << "Trend: Stable mood pattern. ✅" << endl;
        }
    }

    static void saveMoodEntryToFile(const MoodEntry& entry) {
        ofstream file("mood_entries.txt", ios::app);
        if (file.is_open()) {
            file << entry.patientId << "," << entry.date << "," 
                 << entry.moodRating << "," << entry.notes << "\n";
            file.close();
        }
    }
};

// ================= QUESTIONNAIRE MANAGER =================
class QuestionnaireManager {
public:
    static QuestionnaireResult conductQuestionnaire(const string& patientId) {
        QuestionnaireResult result;
        result.patientId = patientId;
        result.date = getCurrentDate();
        
        vector<string> questions = {
            "How often do you feel overwhelmed by daily activities?",
            "How would you rate your sleep quality recently?",
            "How often do you experience feelings of anxiety?",
            "How satisfied are you with your social relationships?",
            "How would you rate your ability to concentrate?",
            "How often do you engage in physical activity?",
            "How would you describe your appetite lately?",
            "How often do you feel supported by friends/family?",
            "How would you rate your overall energy levels?",
            "How optimistic do you feel about the future?"
        };
        
        DisplayManager::printHeader("WELLNESS QUESTIONNAIRE");
        cout << "Please rate each question on a scale of 1-5:\n" << endl;
        cout << "1: Never/Very Poor | 2: Rarely/Poor | 3: Sometimes/Average\n";
        cout << "4: Often/Good | 5: Always/Excellent\n" << endl;
        
        int totalScore = 0;
        for (int i = 0; i < questions.size(); i++) {
            cout << "\nQ" << (i + 1) << ": " << questions[i] << endl;
            
            int response;
            while (true) {
                cout << "Your response (1-5): ";
                cin >> response;
                if (response >= 1 && response <= 5) {
                    totalScore += response;
                    break;
                } else {
                    DisplayManager::printError("Please enter a number between 1 and 5.");
                }
            }
        }
        
        result.totalScore = totalScore;
        
        // Determine risk level based on total score
        if (totalScore <= 20) {
            result.riskLevel = "High Risk";
            DisplayManager::printWarning("High risk detected. Please consult with your therapist.");
        } else if (totalScore <= 30) {
            result.riskLevel = "Moderate Risk";
            DisplayManager::printWarning("Moderate risk detected. Consider discussing with your therapist.");
        } else {
            result.riskLevel = "Low Risk";
            DisplayManager::printSuccess("Low risk detected. Continue with your wellness journey!");
        }
        
        saveQuestionnaireResult(result);
        
        cout << "\n📊 Your total score: " << totalScore << "/50" << endl;
        cout << "⚠️  Risk Level: " << result.riskLevel << endl;
        
        return result;
    }

    static vector<QuestionnaireResult> getQuestionnaireHistory(const string& patientId) {
        vector<QuestionnaireResult> results;
        ifstream file("questionnaire_results.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 4) {
                if (tokens[0] == patientId) {
                    QuestionnaireResult result;
                    result.patientId = tokens[0];
                    result.date = tokens[1];
                    result.totalScore = stoi(tokens[2]);
                    result.riskLevel = tokens[3];
                    results.push_back(result);
                }
            }
        }
        return results;
    }

    static void saveQuestionnaireResult(const QuestionnaireResult& result) {
        ofstream file("questionnaire_results.txt", ios::app);
        if (file.is_open()) {
            file << result.patientId << "," << result.date << "," 
                 << result.totalScore << "," << result.riskLevel << "\n";
            file.close();
        }
    }
};

// ================= REMINDER SYSTEM =================
class ReminderSystem {
public:
    static string getDailyQuote() {
        vector<string> quotes = {
            "Your mental health is a priority. Your happiness is essential. Your self-care is a necessity.",
            "It's okay to not be okay. What's important is that you don't give up.",
            "Healing is not linear. Progress is progress, no matter how small.",
            "You are stronger than you think, braver than you believe, and smarter than you know.",
            "Taking time for yourself is not selfish. It's essential for your well-being.",
            "Every day may not be good, but there's something good in every day.",
            "Your current situation is not your final destination. The best is yet to come.",
            "Be kind to your mind. It's the only one you've got.",
            "Small steps every day lead to big results over time.",
            "You are worthy of love, care, and happiness."
        };
        
        srand(time(nullptr));
        return quotes[rand() % quotes.size()];
    }
};

// ================= PATIENT CLASS =================
class Patient : public User {
private:
    string patientId;
    int age;
    string diagnosis;
    string contactInfo;

public:
    Patient(const string& uname, const string& pwd, const string& n, 
            const string& id, int age, const string& diagnosis, const string& contact)
        : User(uname, pwd, "patient", n), patientId(id), age(age), diagnosis(diagnosis), contactInfo(contact) {}

    void displayMenu() override {
        int choice;
        do {
        	DisplayManager::displayPatientArt();    // ASCII art only
            DisplayManager::displayCenterInfo();    // MIND CARE header

            
            DisplayManager::setColor(14);
            cout << "\nWelcome back, " << name << "! 🌟" << endl;
            DisplayManager::resetColor();
            
            DisplayManager::printMenuOption(1, "Track Mood");
            DisplayManager::printMenuOption(2, "View Mood History");
            DisplayManager::printMenuOption(3, "View Appointments");
            DisplayManager::printMenuOption(4, "Complete Wellness Questionnaire");
            DisplayManager::printMenuOption(5, "View Questionnaire Results");
            DisplayManager::printMenuOption(6, "Receive Daily Inspiration");
            DisplayManager::printMenuOption(7, "Logout");
            
            DisplayManager::setColor(11);
            cout << "\nEnter your choice (1-7): ";
            DisplayManager::resetColor();
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1: {
                    DisplayManager::printHeader("MOOD TRACKER");
                    int rating;
                    string notes;
                    cout << "How are you feeling today? (1-10, where 10 is excellent): ";
                    cin >> rating;
                    cin.ignore();
                    cout << "Any notes about your mood today (optional): ";
                    getline(cin, notes);
                    trackMood(rating, notes);
                    DisplayManager::pressEnterToContinue();
                    break;
                }
                case 2:
                    DisplayManager::printHeader("MOOD HISTORY");
                    viewMoodHistory();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 3:
                    DisplayManager::printHeader("YOUR APPOINTMENTS");
                    viewAppointments();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 4:
                    DisplayManager::printHeader("WELLNESS QUESTIONNAIRE");
                    QuestionnaireManager::conductQuestionnaire(patientId);
                    DisplayManager::pressEnterToContinue();
                    break;
                case 5:
                    DisplayManager::printHeader("QUESTIONNAIRE RESULTS");
                    viewQuestionnaires();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 6:
                    DisplayManager::printHeader("DAILY INSPIRATION");
                    receiveDailyReminder();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 7:
                    logout();
                    return;
                default:
                    DisplayManager::printError("Invalid choice! Please try again.");
                    DisplayManager::pressEnterToContinue();
            }
        } while (true);
    }

    void trackMood(int rating, const string& notes) {
        MoodTracker::addMoodEntry(patientId, rating, notes);
        DisplayManager::printSuccess("Mood tracked successfully! 📊");
    }

    void viewMoodHistory() {
        MoodTracker::analyzeMoodTrends(patientId);
    }

    void viewAppointments() {
        auto appointments = AppointmentManager::getAppointmentsByPatient(patientId);
        if (appointments.empty()) {
            DisplayManager::printWarning("No appointments scheduled.");
        } else {
            for (const auto& app : appointments) {
                cout << " Date: " << app.date << " |  Time: " << app.time 
                          << " |  Status: " << app.status << endl;
            }
        }
    }

    void viewQuestionnaires() {
        auto results = QuestionnaireManager::getQuestionnaireHistory(patientId);
        if (results.empty()) {
            DisplayManager::printWarning("No questionnaire results available.");
        } else {
            for (const auto& result : results) {
                cout << " Date: " << result.date << " |  Score: " << result.totalScore 
                          << " |️  Risk Level: " << result.riskLevel << endl;
            }
        }
    }

    void receiveDailyReminder() {
        cout << " Today's Inspiration: " << ReminderSystem::getDailyQuote() << endl;
    }

    string getPatientId() const { return patientId; }

    static Patient* getPatientById(const string& id) {
        ifstream file("patients.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 6) {
                if (tokens[0] == id) {
                    return new Patient(tokens[1], "", tokens[2], tokens[0], stoi(tokens[3]), tokens[4], tokens[5]);
                }
            }
        }
        return nullptr;
    }

    static void savePatientToFile(const Patient& patient) {
        ofstream file("patients.txt", ios::app);
        if (file.is_open()) {
            file << patient.patientId << "," << patient.username << "," << patient.name << ","
                 << patient.age << "," << patient.diagnosis << "," << patient.contactInfo << "\n";
            file.close();
        }
    }
};

// ================= THERAPIST CLASS =================
class Therapist : public User {
private:
    string therapistId;
    string specialization;

public:
    Therapist(const string& uname, const string& pwd, const string& n, 
              const string& id, const string& specialization)
        : User(uname, pwd, "therapist", n), therapistId(id), specialization(specialization) {}
void displayMenu() override {
    int choice;
    do {
        
        DisplayManager::displayTherapistArt();  // This shows the ASCII art only
        DisplayManager::displayCenterInfo();    // This shows the MIND CARE header
        
        DisplayManager::setColor(10);
        cout << "\nWelcome, Dr. " << name << endl;
        DisplayManager::resetColor();
        
        DisplayManager::printMenuOption(1, "View Patient History");
        DisplayManager::printMenuOption(2, "Add Session Notes");
        DisplayManager::printMenuOption(3, "View Patient Mood Trends");
        DisplayManager::printMenuOption(4, "View Questionnaire Results");
        DisplayManager::printMenuOption(5, "View Appointments");
        DisplayManager::printMenuOption(6, "Logout");
        
        DisplayManager::setColor(11);
        cout << "\nEnter your choice (1-6): ";
        DisplayManager::resetColor();
        cin >> choice;
        
        string patientId;
        switch (choice) {
            case 1:
                DisplayManager::printHeader("PATIENT HISTORY");
                cout << "Enter Patient ID: ";
                cin >> patientId;
                viewPatientHistory(patientId);
                DisplayManager::pressEnterToContinue();
                break;
            case 2:
                DisplayManager::printHeader("SESSION NOTES");
                cout << "Enter Patient ID: ";
                cin >> patientId;
                cin.ignore();
                {
                    string notes;
                    cout << "Enter session notes: ";
                    getline(cin, notes);
                    addSessionNotes(patientId, notes);
                }
                DisplayManager::pressEnterToContinue();
                break;
            case 3:
                DisplayManager::printHeader("MOOD TRENDS");
                cout << "Enter Patient ID: ";
                cin >> patientId;
                viewMoodTrends(patientId);
                DisplayManager::pressEnterToContinue();
                break;
            case 4:
                DisplayManager::printHeader("QUESTIONNAIRE RESULTS");
                cout << "Enter Patient ID: ";
                cin >> patientId;
                viewQuestionnaireResults(patientId);
                DisplayManager::pressEnterToContinue();
                break;
            case 5:
                DisplayManager::printHeader("APPOINTMENTS");
                viewAppointments();
                DisplayManager::pressEnterToContinue();
                break;
            case 6:
                logout();
                return;
            default:
                DisplayManager::printError("Invalid choice! Please try again.");
                DisplayManager::pressEnterToContinue();
        }
    } while (true);
}


    void viewAppointments() {
        auto appointments = AppointmentManager::getAppointmentsByTherapist(therapistId);
        if (appointments.empty()) {
            DisplayManager::printWarning("No appointments scheduled.");
        } else {
            for (const auto& app : appointments) {
                cout << " Patient: " << app.patientId << " |  Date: " << app.date 
                          << " |  Time: " << app.time << " |  Status: " << app.status << endl;
            }
        }
    }

    void viewPatientHistory(const string& patientId) {
        Patient* patient = Patient::getPatientById(patientId);
        if (patient) {
            cout << "\n=== PATIENT PROFILE ===" << endl;
            cout << " Name: " << patient->getName() << endl;
            cout << " Patient ID: " << patientId << endl;
            delete patient;
        } else {
            DisplayManager::printError("Patient not found!");
        }
    }

    void addSessionNotes(const string& patientId, const string& notes) {
        ofstream file("session_notes_" + patientId + ".txt", ios::app);
        if (file.is_open()) {
            file << "Therapist: " << name << " | Date: " << getCurrentDate() << "\n";
            file << "Notes: " << notes << "\n\n";
            file.close();
            DisplayManager::printSuccess("Session notes added successfully! 📝");
        }
    }

    void viewMoodTrends(const string& patientId) {
        MoodTracker::analyzeMoodTrends(patientId);
    }

    void viewQuestionnaireResults(const string& patientId) {
        auto results = QuestionnaireManager::getQuestionnaireHistory(patientId);
        if (results.empty()) {
            DisplayManager::printWarning("No questionnaire results available.");
        } else {
            for (const auto& result : results) {
                cout << " Date: " << result.date << " |  Score: " << result.totalScore 
                          << " |️  Risk Level: " << result.riskLevel << endl;
            }
        }
    }

    string getTherapistId() const { return therapistId; }

    static Therapist* getTherapistById(const string& id) {
        ifstream file("therapists.txt");
        string line;
        
        while (getline(file, line)) {
            vector<string> tokens = splitString(line, ',');
            if (tokens.size() >= 4) {
                if (tokens[0] == id) {
                    return new Therapist(tokens[1], "", tokens[2], tokens[0], tokens[3]);
                }
            }
        }
        return nullptr;
    }

    static void saveTherapistToFile(const Therapist& therapist) {
        ofstream file("therapists.txt", ios::app);
        if (file.is_open()) {
            file << therapist.therapistId << "," << therapist.username << "," 
                 << therapist.name << "," << therapist.specialization << "\n";
            file.close();
        }
    }
};

// ================= RECEPTIONIST CLASS =================
class Receptionist : public User {
public:
    Receptionist(const string& uname, const string& pwd, const string& n)
        : User(uname, pwd, "receptionist", n) {}

    void displayMenu() override {
        int choice;
        do {
        	DisplayManager::displayReceptionistArt();  // ASCII art only
            DisplayManager::displayCenterInfo();       // MIND CARE header
            
            DisplayManager::setColor(13);
            cout << "\nWelcome, " << name << "! 💼" << endl;
            DisplayManager::resetColor();
            
            DisplayManager::printMenuOption(1, "Add Patient Record");
            DisplayManager::printMenuOption(2, "Edit Patient Record");
            DisplayManager::printMenuOption(3, "Schedule Appointment");
            DisplayManager::printMenuOption(4, "Generate Invoice");
            DisplayManager::printMenuOption(5, "Search Patient Records");
            DisplayManager::printMenuOption(6, "Generate Reports");
            DisplayManager::printMenuOption(7, "Logout");
            
            DisplayManager::setColor(11);
            cout << "\nEnter your choice (1-7): ";
            DisplayManager::resetColor();
            cin >> choice;
            
            switch (choice) {
                case 1:
                    DisplayManager::printHeader("ADD PATIENT RECORD");
                    addPatientRecord();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 2:
                    DisplayManager::printHeader("EDIT PATIENT RECORD");
                    editPatientRecord();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 3:
                    DisplayManager::printHeader("SCHEDULE APPOINTMENT");
                    scheduleAppointment();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 4:
                    DisplayManager::printHeader("GENERATE INVOICE");
                    generateInvoice();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 5:
                    DisplayManager::printHeader("SEARCH PATIENT RECORDS");
                    searchPatientRecords();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 6:
                    DisplayManager::printHeader("GENERATE REPORTS");
                    generateReports();
                    DisplayManager::pressEnterToContinue();
                    break;
                case 7:
                    logout();
                    return;
                default:
                    DisplayManager::printError("Invalid choice! Please try again.");
                    DisplayManager::pressEnterToContinue();
            }
        } while (true);
    }

    void addPatientRecord() {
        string username, password, name, patientId, diagnosis, contact;
        int age;
        
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Initial Diagnosis: ";
        getline(cin, diagnosis);
        cout << "Enter Contact Information: ";
        getline(cin, contact);
        
        Patient patient(username, password, name, patientId, age, diagnosis, contact);
        Patient::savePatientToFile(patient);
        User::saveUserToFile(patient);
        
        DisplayManager::printSuccess("Patient record added successfully! 👤");
    }

    void editPatientRecord() {
        string patientId;
        cout << "Enter Patient ID to edit: ";
        cin >> patientId;
        
        // Simple implementation for demo
        DisplayManager::printWarning("Edit feature simplified for demo. Full implementation would include file editing.");
    }

    void scheduleAppointment() {
        string patientId, therapistId, date, time;
        
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cout << "Enter Therapist ID: ";
        cin >> therapistId;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter Time (HH:MM): ";
        cin >> time;
        
        if (AppointmentManager::scheduleAppointment(patientId, therapistId, date, time)) {
            DisplayManager::printSuccess("Appointment scheduled successfully! ");
        } else {
            DisplayManager::printError("Failed to schedule appointment. Time conflict or invalid data.");
        }
    }

    void generateInvoice() {
    DisplayManager::printHeader("GENERATE INVOICE");
    
    string patientId, therapistId;
    double amount;
    
    cout << "Enter Patient ID: ";
    cin >> patientId;
    cout << "Enter Therapist ID: ";
    cin >> therapistId;
    cout << "Enter Amount: $";
    cin >> amount;
    
    // Generate invoice number
    string invoiceNumber = "INV" + to_string(rand() % 10000);
    string currentDate = getCurrentDate();
    
    // Display invoice
    cout << "\n════════════════ INVOICE ════════════════" << endl;
    cout << "Invoice Number: " << invoiceNumber << endl;
    cout << "Date: " << currentDate << endl;
    cout << "Patient ID: " << patientId << endl;
    cout << "Therapist ID: " << therapistId << endl;
    cout << "Amount: $" << fixed << setprecision(2) << amount << endl;
    cout << "Status: UNPAID" << endl;
    cout << "══════════════════════════════════════════" << endl;
    
    // Save to file
    ofstream file("invoices.txt", ios::app);
    if (file.is_open()) {
        file << invoiceNumber << "," << currentDate << "," << patientId << "," 
             << therapistId << "," << amount << ",UNPAID\n";
        file.close();
    }
    
    DisplayManager::printSuccess("Invoice generated successfully! 🧾");
}

    void searchPatientRecords() {
        string searchTerm;
        cout << "Enter search term (Patient ID or Name): ";
        cin >> searchTerm;
        
        ifstream file("patients.txt");
        string line;
        bool found = false;
        
        cout << "\n=== SEARCH RESULTS ===" << endl;
        while (getline(file, line)) {
            if (line.find(searchTerm) != string::npos) {
                cout << "🔍 " << line << endl;
                found = true;
            }
        }
        
        if (!found) {
            DisplayManager::printWarning("No records found.");
        }
    }

    void generateReports() {
    int reportType;
    
    DisplayManager::printHeader("GENERATE REPORTS");
    cout << "Select report type:" << endl;
    DisplayManager::printMenuOption(1, "Patient List Report");
    DisplayManager::printMenuOption(2, "Appointment Schedule Report");
    DisplayManager::printMenuOption(3, "Therapy Sessions Report");
    DisplayManager::printMenuOption(4, "Financial Report");
    
    cout << "Enter your choice (1-4): ";
    cin >> reportType;
    
    switch (reportType) {
        case 1:
            generatePatientReport();
            break;
        case 2:
            generateAppointmentReport();
            break;
        case 3:
            generateTherapyReport();
            break;
        case 4:
            generateFinancialReport();
            break;
        default:
            DisplayManager::printError("Invalid report type!");
    }
}

void generatePatientReport() {
    DisplayManager::printHeader("PATIENT LIST REPORT");
    
    ifstream file("patients.txt");
    string line;
    int patientCount = 0;
    
    cout << "=== PATIENT LIST REPORT ===" << endl;
    cout << "Generated on: " << getCurrentDate() << endl;
    cout << "══════════════════════════════════════════" << endl;
    
    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');
        if (tokens.size() >= 6) {
            cout << "ID: " << tokens[0] << " | Name: " << tokens[2] 
                 << " | Age: " << tokens[3] << " | Diagnosis: " << tokens[4] << endl;
            patientCount++;
        }
    }
    
    cout << "══════════════════════════════════════════" << endl;
    cout << "Total Patients: " << patientCount << endl;
    DisplayManager::printSuccess("Patient report generated! 📋");
}

void generateAppointmentReport() {
    DisplayManager::printHeader("APPOINTMENT REPORT");
    
    ifstream file("appointments.txt");
    string line;
    int appointmentCount = 0;
    
    cout << "=== APPOINTMENT SCHEDULE REPORT ===" << endl;
    cout << "Generated on: " << getCurrentDate() << endl;
    cout << "══════════════════════════════════════════" << endl;
    
    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');
        if (tokens.size() >= 6) {
            cout << "Appointment: " << tokens[0] << " | Patient: " << tokens[1] 
                 << " | Therapist: " << tokens[2] << " | Date: " << tokens[3] 
                 << " | Time: " << tokens[4] << " | Status: " << tokens[5] << endl;
            appointmentCount++;
        }
    }
    
    cout << "══════════════════════════════════════════" << endl;
    cout << "Total Appointments: " << appointmentCount << endl;
    DisplayManager::printSuccess("Appointment report generated! 📅");
}

void generateTherapyReport() {
    DisplayManager::printHeader("THERAPY SESSIONS REPORT");
    
    // Count mood entries as therapy sessions
    ifstream file("mood_entries.txt");
    string line;
    int sessionCount = 0;
    
    cout << "=== THERAPY SESSIONS REPORT ===" << endl;
    cout << "Generated on: " << getCurrentDate() << endl;
    cout << "══════════════════════════════════════════" << endl;
    
    while (getline(file, line)) {
        sessionCount++;
    }
    
    cout << "Total Therapy Sessions Tracked: " << sessionCount << endl;
    cout << "══════════════════════════════════════════" << endl;
    DisplayManager::printSuccess("Therapy sessions report generated! 🩺");
}

void generateFinancialReport() {
    DisplayManager::printHeader("FINANCIAL REPORT");
    
    ifstream file("invoices.txt");
    string line;
    double totalRevenue = 0.0;
    int invoiceCount = 0;
    
    cout << "=== FINANCIAL REPORT ===" << endl;
    cout << "Generated on: " << getCurrentDate() << endl;
    cout << "══════════════════════════════════════════" << endl;
    
    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');
        if (tokens.size() >= 6) {
            double amount = stod(tokens[4]);
            totalRevenue += amount;
            invoiceCount++;
            cout << "Invoice: " << tokens[0] << " | Amount: $" << amount 
                 << " | Status: " << tokens[5] << endl;
        }
    }
    
    cout << "══════════════════════════════════════════" << endl;
    cout << "Total Invoices: " << invoiceCount << endl;
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
    cout << "Average per Invoice: $" << (invoiceCount > 0 ? totalRevenue/invoiceCount : 0) << endl;
    
    DisplayManager::printSuccess("Financial report generated! ");
}
};

// ================= IMPLEMENT REMAINING FUNCTIONS =================
User* User::authenticateUser(const string& username, const string& password) {
    ifstream file("users.txt");
    string line;
    
    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');
        if (tokens.size() >= 4) {
            if (tokens[0] == username && tokens[1] == password) {
                if (tokens[2] == "patient") {
                    return new Patient(tokens[0], tokens[1], tokens[3], "", 0, "", "");
                } else if (tokens[2] == "therapist") {
                    return new Therapist(tokens[0], tokens[1], tokens[3], "", "");
                } else if (tokens[2] == "receptionist") {
                    return new Receptionist(tokens[0], tokens[1], tokens[3]);
                }
            }
        }
    }
    return nullptr;
}

// ================= MAIN FUNCTION =================
int main() {
    #ifdef _WIN32
        system("title MIND CARE - Mental Health Management System");
    #endif
    
    DisplayManager::clearScreen();
    DisplayManager::displayWelcomeArt();
    DisplayManager::displayCenterInfo();
    
    DisplayManager::loadingAnimation(3);
    
    // Create sample data if files don't exist
    ifstream testFile("users.txt");
    if (!testFile.good()) {
        // Create sample patient
        Patient patient1("khadija_hassan", "password123", "Khadija Hassan", "P001", 28, "Anxiety", "khadija@gmail.com");
        Patient::savePatientToFile(patient1);
        User::saveUserToFile(patient1);
        
        // Create sample therapist
        Therapist therapist1("dr_moshin", "therapy123", "Mohsin Zaffar", "T001", "Cognitive Behavioral Therapy");
        Therapist::saveTherapistToFile(therapist1);
        User::saveUserToFile(therapist1);
        
        // Create sample receptionist
        Receptionist receptionist1("reception", "admin123", "Najm ul Hassan");
        User::saveUserToFile(receptionist1);
        
        DisplayManager::printSuccess("Sample data created successfully!");
    }
    testFile.close();
    
    int loginAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    
    while (loginAttempts < MAX_ATTEMPTS) {
        DisplayManager::printHeader("LOGIN PORTAL");
        
        string username, password;
        
        DisplayManager::setColor(11);
        cout << " Username: ";
        DisplayManager::resetColor();
        cin >> username;
        
        DisplayManager::setColor(11);
        cout << " Password: ";
        DisplayManager::resetColor();
        cin >> password;
        
        User* user = User::authenticateUser(username, password);
        
        if (user) {
            DisplayManager::printSuccess("Login successful! Welcome to MIND CARE.");
            DisplayManager::loadingAnimation(2);
            
            // Clear login details from screen
            DisplayManager::clearScreen();
            
            if (user->getRole() == "patient") {
                Patient* patient = dynamic_cast<Patient*>(user);
                if (patient) {
                    patient->displayMenu();
                }
            } else if (user->getRole() == "therapist") {
                Therapist* therapist = dynamic_cast<Therapist*>(user);
                if (therapist) {
                    therapist->displayMenu();
                }
            } else if (user->getRole() == "receptionist") {
                Receptionist* receptionist = dynamic_cast<Receptionist*>(user);
                if (receptionist) {
                    receptionist->displayMenu();
                }
            }
            
            delete user;
            break;
        } else {
            loginAttempts++;
            DisplayManager::printError("Invalid username or password! Attempts remaining: " + 
                                      to_string(MAX_ATTEMPTS - loginAttempts));
            
            if (loginAttempts >= MAX_ATTEMPTS) {
                DisplayManager::printError("Maximum login attempts exceeded. System exiting.");
                DisplayManager::loadingAnimation(2);
                DisplayManager::displayGoodbyeArt();
                return 1;
            }
            
            DisplayManager::pressEnterToContinue();
        }
    }
    
    return 0;
}