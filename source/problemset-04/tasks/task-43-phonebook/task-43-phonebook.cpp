#include "task-43-phonebook.h"

#include <gtest/gtest.h> // Google Test Framework

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <locale>
#include <windows.h> // винда

using namespace std;

const int fixedSize = 100;

void processData(const string &filename, Record *phoneBook, int &size)
{
    ifstream data(filename, ios::in);

    if (!data.is_open())
    {
        // File not found. The database is considered empty.
        cout << "Фаил не найден => телефонный справочник считается пустым." << endl;
        size = 0;
        return;
    }

    while (!data.eof() && size < fixedSize)
    {
        string temp;
        getline(data, temp);

        if (!temp.empty())
        {
            phoneBook[size].name = temp;

            getline(data, temp);
            phoneBook[size].phoneNumber = stoll(temp);
            ++size;
        }
    }

    data.close();
    cout << "Успешно прочитано " << size << " записей." << endl;
}


void saveData(const string &filename, Record *phoneBook, const int &size)
{
    setlocale(LC_ALL, "Russian");
    fstream output;
    output.open(filename, ios::out | ios::trunc);

    if (!output.is_open())
    {
        throw runtime_error("\nОшибка: запись в фаил невозможна\n");
    }

    for (int i = 0; i < size; ++i)
    {
        output << phoneBook[i].name;
        output << "\n";
        output << phoneBook[i].phoneNumber;
        output << "\n";
    }

    output.close();
    cout << "Все данные были успешно сохранены в фаил: " << filename << endl;
}


void addRecord(const string &newName, const long &newNumber, Record *phoneBook, int &size)
{
    setlocale(LC_ALL, "Russian");

    if (newName.empty() || newNumber == 0)
    {
        cout << "Ошибка: невозможно добавить пустые поля!" << endl;
        return;
    }

    // overflow case
    if (size + 1 > fixedSize)
    {
        cout << "Ошибка: переполнение телефонного справочника :)" << endl;
        return;
    }

    phoneBook[size].name = newName;
    phoneBook[size].phoneNumber = newNumber;
    ++size;
}


string findName(const long &number, const Record *phoneBook, const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        if (phoneBook[i].phoneNumber == number)
        {
            return phoneBook[i].name;
        }
    }

    // If name not found
    return "";
}


long findNumber(const string &name, const Record *phoneBook, const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        if (phoneBook[i].name == name)
        {
            return phoneBook[i].phoneNumber;
        }
    }
    // If number not found
    return -1;
}


void printAll(const Record *phoneBook, const int &size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << i + 1 << ") " << phoneBook[i].name << " : " << phoneBook[i].phoneNumber << endl;
    }
}


void phoneBookUserInterface()
{
    // Define a all I/O file names
    const string filename = "phoneBook-data.txt";

    // Create phone book "database" of records
    Record phoneBook[fixedSize];
    int size = 0;

    processData(filename, phoneBook, size);

    cout << "<== Телефонный справочник ==>" << endl;

    cout << "Доступны следующие операции:" << endl;

    cout << "\t0 => Выйти" << endl;
    cout << "\t1 => Добавить запись (имя и телефон)" << endl;
    cout << "\t2 => Распечатать все имеющиеся записи" << endl;
    cout << "\t3 => Найти телефон по имени" << endl;
    cout << "\t4 => Найти имя по телефону" << endl;
    cout << "\t5 => Сохранить текущие данные в файл" << endl;

    int command = 0;

    do
    {
        cout << "Введите комманду:" << endl;
        cin >> command;

        string newName;
        string temp;

        long newNumber = 0;

        switch (command)
        {
            case 0:
                cout << "< ВЫХОД >" << endl;
                break;

            case 1:
                cout << "< Добавление записи >" << endl;
                cout << "Введите имя:" << endl;
                cin >> newName;

                cout << "Введите номер телефона:" << endl;
                cin >> temp;
                newNumber = stol(temp);

                addRecord(newName, newNumber, phoneBook, size);
                break;

            case 2:
                cout << "< Вывод всех записей >" << endl;
                printAll(phoneBook, size);
                break;

            case 3:
                cout << "< Поиск по имени >" << endl;
                cin >> newName;
                newNumber = findNumber(newName, phoneBook, size);

                if (newNumber != -1)
                {
                    cout << "\tПо имени: " << newName << " -> была найдена запись." << endl;
                    cout << "\tТелефонный номер: " << newNumber << endl;
                    break;
                }
                else
                {
                    cout << "Записей не найденно." << endl;
                    break;
                }

            case 4:
                cout << "< Поиск по номеру телефона >" << endl;
                cin >> newNumber;
                newName = findName(newNumber, phoneBook, size);

                if (!newName.empty())
                {
                    cout << "\tПо номеру телефона: " << newNumber << " -> была найдена запись." << endl;
                    cout << "\tИмя (ФИО / nickname): " << newName << endl;
                    break;
                }
                else
                {
                    cout << "Записей не найденно." << endl;
                    break;
                }

            case 5:
                cout << "< Сохранение данных >" << endl;
                saveData(filename, phoneBook, size);
                break;

            default:
                cout << "Неверная комманда!" << endl;
                break;
        }
    } while (command != 0);
}


int main(int argc, char **argv)
{
    // Allow RUSSIAN in console
    setlocale(LC_ALL, "Russian");

    // Ха-ха, всё равно Русский работает только в режиме отладки. Windows -- ты целый мир!
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    // phoneBookUserInterface();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}