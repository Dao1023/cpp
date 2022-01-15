#include <iostream>
#include <string>
#include <vector>
// #include <stdio.h>

using namespace std;

class Person {
public:
    string name;
    string phone;

    int inputData(string name, string phone) {
        this->name = name;
        this->phone = phone;
        return 0;
    }
};

class Contacts {
public:
    int count = 3;
    int personAddIndex = 0;
    int maxNumOfPeople = 10;
    
    // Person *personArray = new Person[maxNumOfPeople];    // Person personArray[maxNumOfPeople];
    vector<Person> personVector;

    // 添加联系人
    int addPerson(string name, string phone) {
        Person person;
        person.inputData(name, phone);
        personVector.push_back(person);
        personAddIndex++;
        return 0;
    }

    // 删除联系人
    int removePerson(string name) {
        for (int i = 0; i < personVector.size(); ++i) {
            if (personVector[i].name == name) {
                personVector.erase(personVector.begin() + i);
            }
        }
        return 0;
    }

    int deleteAllPerson() {
        personVector.clear();
        return 0;
    }

    // 搜索联系人
    string searchPerson(string name) {
        for (int i = 0; i < personVector.size(); ++i) {
            if (personVector[i].name == name) {
                return personVector[i].phone;    
            }
        }
        return 0;
    }

    // 二分查找联系人（会先进行排序）
    string searchPersonByBinaryAlgorithm(string name) {
        
        sortContacts();

        string result = 0;
        int start = 0;
        int end = personVector.size();

        while (start < end) {
            int middle = (start + end) / 2;
            if (personVector[middle].name == name) {
                return personVector[middle].phone;
            }
            if (personVector[middle].name > name) {
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
        
        return result;
    }

    // 显示联系人总数
    int getPersonCount() {
        return personVector.size();
    }
    
    // 显示所有联系人
    int showAllOfPerson() {
        int index = 1;
        for (Person p:personVector) {
            cout << "index:" << index << endl;
            cout << "name:" << p.name << endl;
            cout << "phone:" << p.phone << endl;
            ++index;
        }
        return 0;
    }

    // 按名称排序联系人
    int sortContacts() {
        for (int i = 0; i < personVector.size(); ++i) {
            int min = i;
            for (int j = i+1; j < personVector.size(); ++j) {
                if (personVector[j].name < personVector[min].name) {
                    min = j;
                }
            }
            swap(personVector[i], personVector[min]);
        }
        return 0;
    }

};

// 加入提示词获取用户输入
string getInput(string input) {
    string output;
    cout << input;
    cin >> output;
    return output;
}

// 问候语
int contactsMenu() {
    cout << "***********************************************************" << endl;
    cout << "*                    OPERATING COMMAND                    *" << endl;
    cout << "*                                                         *" << endl;
    cout << "* exit: Exit without saving                               *" << endl;
    cout << "* add: Add a person                                       *" << endl;
    cout << "* remove: Remove a person                                 *" << endl;
    cout << "* clear: delelt all the person                            *" << endl;
    cout << "* search: Search contacts                                 *" << endl;
    cout << "* search!: Search contacts using binary search algorithm  *" << endl;
    cout << "* count: Show the contacts counts                         *" << endl;
    cout << "* show: Show all the contacts                             *" << endl;
    cout << "* sort: Sort contacts by name                             *" << endl;
    cout << "*                                                         *" << endl;
    cout << "*  Type 'help' for the OPERATING COMMAND.                 *" << endl;
    cout << "***********************************************************" << endl;
    return 0;
}


// 获取命令并操作
int runCode() {    
    Contacts contactsOne;
    contactsOne.addPerson("dao6", "6");
    contactsOne.addPerson("dao3", "3");
    contactsOne.addPerson("dao2", "2");
    contactsOne.addPerson("dao1", "1");
    contactsOne.addPerson("dao5", "5");
    contactsOne.addPerson("dao4", "4");


    while (1) {
        string userInput;
        cin >> userInput;
        if (userInput == "exit") {
            cout << "[server] Thanks for using." << endl; return 0;   
        }
        if (userInput == "add") {
            contactsOne.addPerson(getInput("name:"), getInput("phone:"));
            cout << "[server] Contact added successfully." << endl;
        }
        if (userInput == "remove") {
            contactsOne.removePerson(getInput("name:"));
            cout << "[server] Removed successfully." << endl;
        }
        if (userInput == "clear") {
            contactsOne.deleteAllPerson();
            cout << "[server] clear successfully." << endl;
        }
        if (userInput == "search") {
            cout << "phone:" << contactsOne.searchPerson(getInput("name:")) << endl;
            cout << "[server] Searched successfully." << endl;
        }
        if (userInput == "search!") {
            contactsOne.searchPersonByBinaryAlgorithm(getInput("name:"));
            cout << "[server] Searched successfully." << endl;
        }
        if (userInput == "count") {
            cout << contactsOne.getPersonCount() << endl;
            cout << "[server] Showed successfully." << endl;
        }
        if (userInput == "show") {
            contactsOne.showAllOfPerson();
            cout << "[server] Showed successfully." << endl;
        }
        if (userInput == "sort") {
            contactsOne.sortContacts();
            cout << "[server] Sorted successfully." << endl;
        }
        if (userInput == "help") {
            cout << "Your command is not supported." << endl;
            contactsMenu();
        }
    }
}

// 主函数
int main() {
    contactsMenu();
    runCode();

    return 0;
}