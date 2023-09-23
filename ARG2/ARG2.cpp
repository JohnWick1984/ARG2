// ARG2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) 
{
    setlocale(0, "");
    if (argc != 3) {
        cout << "Использование: " << argv[0] << " <f> <C:\\Users\\Евгений\\Documents\\Учеба Академия ТОР\\ООП С++\\ООП С++\\ARG2\\ARG2\\1.txt>" << endl;
        return 1;
    }

    char charToReplace = argv[1][0];
    string filePath = argv[2];

    ifstream inputFile(filePath);
    if (!inputFile) 
    {
        cerr << "Не удалось открыть файл: " << filePath << endl;
        return 1;
    }

    string fileContents((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    for (char& c : fileContents)
    {
        if (c == charToReplace) 
        {
            c = '*';
        }
    }

    ofstream outputFile(filePath);
    if (!outputFile) 
    {
        cerr << "Не удалось открыть файл для записи: " << filePath << endl;
        return 1;
    }

    outputFile << fileContents;
    outputFile.close();

    cout << "Все вхождения символа '" << charToReplace << "' были заменены на '*'" << std::endl;

    return 0;
}
