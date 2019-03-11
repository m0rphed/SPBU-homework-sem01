#include "userInterface.h"
#include "Dictionary.h"
#include <iostream>

using namespace std;

void startDialogInterface()
{

    cout << "\nCommands:" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Add a value to the dictionary" << endl;
    cout << "2 - Find a value in the dictionary by key" << endl;
    cout << "3 - Check if the key exists in the dictionary" << endl;
    cout << "4 - Delete value from the dictionary" << endl;

    auto *dictionaryOnAvlTree = new AVLTree();
    int command = -1;

    while (command)
    {
        cout << "Enter a command:" << endl;
        cin >> command;

        ValueType value;
        KeyType key;

        switch (command)
        {
            case 1:
                cout << "Enter the value you'd like to add" << endl;
                cin >> value;

                cout << "Enter the key" << endl;
                cin >> key;

                dictionaryOnAvlTree->add(key, value);

                break;

            case 2:
                cout << "Enter the key" << endl;
                cin >> key;
                cout << "The value: " << dictionaryOnAvlTree->findNode(key) << endl;
                break;

            case 3:
                cout << "Enter the key" << endl;
                cin >> key;

                if (dictionaryOnAvlTree->exists(key))
                {
                    cout << "The key is found" << endl;
                }
                else
                {
                    cout << "The key is not found" << endl;
                }
                break;

            case 4:
                cout << "Enter the key" << endl;
                cin >> key;

                if (dictionaryOnAvlTree->deleteByKey(key))
                {
                    cout << "The node is deleted successfully" << endl;
                }
                else
                {
                    cout << "The key is not found" << endl;
                }
                break;

            default:
                cout << "No such command. \n\tEnter command again, please :)" << endl;
                break;
        }
    }

    delete dictionaryOnAvlTree;
}
