#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) 
    {
        cout << "Error when opening the input file" << endl;
        return 1;
    }

    if (!outputFile) 
    {
        cout << "Error when opening the output file" << endl;
        return 1;
    }

    string str;
    vector<string> passwords;

    while (getline(inputFile, str))
    {
        passwords.push_back(str);
    }

    regex rgx("(?=.*[A-Z]+)(?=.*[a-z]+)(?=.*[0-9]+)[A-Za-z0-9!%:?()_+=$^&\\.\\-]{8,}");

    for (int i = 0; i < passwords.size(); i++)
    {
        if (regex_match(passwords.at(i), rgx))
        {
            outputFile << passwords.at(i) << endl;
            cout << "This is a strong password:\t" << passwords.at(i) << endl;
        }
        else
        {
            cout << "This is not a strong password:\t"<< passwords.at(i) << endl;
        }
    }

    cout << endl;
    cout << "The results are output to a file" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}