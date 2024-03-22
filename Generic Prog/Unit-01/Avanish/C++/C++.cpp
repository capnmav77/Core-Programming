#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

using namespace std;
namespace fs = std::filesystem;// alias for filesystem operations

vector<string> split(const string& str, char delim = ' ') {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

string join(const vector<string>& parts, char delim = '/') {
    if (parts.empty()) return "";
    string result = parts[0];
    for (size_t i = 1; i < parts.size(); ++i) {
        result += delim + parts[i];
    }
    return result;
}

void printHistory(const vector<string>& history) {
    for (const auto& cmd : history) {
        cout << cmd << endl;
    }
}

void changeDirectory(const string& newDir, string& currentPath) {
    if (!fs::exists(newDir)) {
        cerr << "Error: Directory does not exist." << endl;
        return;
    }
    if (!fs::is_directory(newDir)) {
        cerr << "Error: Not a directory." << endl;
        return;
    }
    if (fs::current_path(newDir)) {
        cerr << "Error: Failed to change directory." << endl;
        return;
    }
    currentPath = newDir; // Update current directory path
}

int main(int argc, char** argv) {
    string cmd;
    clearScreen();
    vector<string> history;
    string currentPath = fs::current_path().string(); // Get current directory path

    while (true) {
        cout << currentPath << ">";
        cin >> cmd;
        vector<string> splitCmd = split(cmd);
        int length = splitCmd.size();

        if (length == 0) {
            cout << "Enter" << endl;
            continue;
        }

        history.push_back(cmd);
        string control = splitCmd[0];

        if (control == "cd") {
            if (length > 1) {
                changeDirectory(splitCmd[1], currentPath);
            }
            else {
                changeDirectory(fs::current_path().string(), currentPath); // Go to current directory
            }
        }
        else if (control == "ls") {
            // Implement ls command
        }
        else if (control == "cls") {
            clearScreen();
        }
        else if (control == "touch") {
            // Implement touch command
        }
        else if (control == "cp") {
            // Implement cp command
        }
        else if (control == "hist") {
            printHistory(history);
        }
        else if (control == "clrhist") {
            history.clear();
        }
        else if (control == "exit") {
            exit(0);
        }
        else {
            // Unknown command
        }
    }

    return 0;
}



// #include<iostream>
// #include<bits/stdc++.h>
// #include <filesystem> 


// #ifdef _WIN32
// #include <windows.h> 
// #else
// #include <cstdlib> 
// #endif

// void clearScreen() {
// #ifdef _WIN32
//     system("cls"); 
// #else
//     system("clear"); 
// #endif
// }



// using namespace std;
// namespace fs = std::filesystem;


// /*
// cd
// ls
// touch 
// cp
// histroy
// clear histroy
// */

// vector<string> split(string str,char ch=' ')
// {
//     vector<string> __split;
//     stringstream ss(str);

//     string word;
//     while(getline(ss, word, ch))
//     {
//         __split.push_back(word);
//     }

//     return __split;
// }

// string str_merge(vector<string> s,char ch=' ')
// {
//     string str="";
//     if(s.size()==0)
//     return "";
//     for(int i=0;i<s.size()-1;++i)
//     {
//         str+=s[i];
//         str.push_back(ch);
//     }
//     str+=s[s.size()-1];
//     return str;
// }

// void printHistory(const vector<string> &h )
// {
//     for(int i=0;i<h.size()-1;++i)
//     {
//         cout<<h[i]<<endl;
//     }
//     return;
// }

// void changeDirectory(const string &newDir) {
//     if (!fs::exists(newDir)) {
//         cerr << "Error: Directory does not exist." << endl;
//         return;
//     }
//     if (!fs::is_directory(newDir)) {
//         cerr << "Error: Not a directory." << endl;
//         return;
//     }
//     if (fs::current_path(newDir)) {
//         cerr << "Error: Failed to change directory." << endl;
//     }
// }

// int main(int argc,char **argv)
// {
//     string cmd;
//     clearScreen();
//     vector<string> history;
//     vector<string> split_path = split(argv[0],'\\');
//     split_path.pop_back();
//     string path = str_merge(split_path,'\\');
//     while(true)
//     {
//         cout<<path<<">";
//         cin>>cmd;
//         vector<string> split_cmd = split(cmd);
//         int length  =  split_cmd.size();
//         if(length==0)
//         {
//             cout<<"Enter"<<endl;
//             continue;
//         }
//         history.push_back(cmd);
//         string control = split_cmd[0];

//         if (control=="cd")
//         {
//             if (length > 1) {
//                 changeDirectory(splitCmd[1]);
//             } else {
//                 changeDirectory(fs::current_path().string()); 
//             }
//         }
//         else if(control=="ls")
//         {

//         }
//         else if(control=="cls")
//         {
//             clearScreen();
//         }
//         else if(control=="touch")
//         {

//         }
//         else if(control=="cp")
//         {

//         }
//         else if(control=="hist")
//         {
//             printHistory(history);
//         }
//         else if(control=="clrhist")
//         {
//             history.clear();

//         }
//         else if(control=="exit")
//         {
//            exit(0);
//         }
//         else{

//         }
//     }
// }