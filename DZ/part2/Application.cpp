#include "Application.h"

Application::Application() : operation(0), base1(nullptr), base2(nullptr), result(nullptr) {}

void Application::run() {
    try {
        bool key = true;
        while (key) {
            std::cout << "_____Main Menu_____" << std::endl;
            std::cout << "1 - Money\n2 - String\n0 - Exit\n" << std::endl;
            std::cin >> operation;
            switch (operation) {
            case 1:
                Money_run();
                break;
            case 2:
                String_run();
                break;
            case 0:
                key = false;
                break;
            }
        }
    }
    catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }
}

void Application::Money_run() {
    base1 = new Money();
    base2 = new Money();
    result = new Money();
    auto* object1 = dynamic_cast<Money*>(base1);
    auto* object2 = dynamic_cast<Money*>(base2);
    std::cout << "Enter two amounts (rubles, kopecks): amount_1  amount_2" << std::endl;
    std::cin >> *object1;
    std::cin >> *object2;
    std::cout << *object1 << std::endl;
    std::cout << *object2 << std::endl;
    static bool check = true;
    do {
        std::cout << "_____Money menu_____" << std::endl;
        std::cout << " 1: generate new amount\n"
            " 2: check Add method (a+b)\n"
            " 3: check Subtract method (a-b)\n"
            " 4: check Multiply method (a*b)\n"
            " 5: check Divide method (a/b)\n"
            " 6: check Divide and Multiply method with number\n"
            " 7: check bool operators\n"
            " 8: exit\n" << std::endl;
        std::cin >> operation;
        switch (operation) {
        case 1:
            std::cin >> *object1;
            std::cin >> *object2;
            std::cout << *object1 << std::endl;
            std::cout << *object2 << std::endl;
            break;
        case 2:
            std::cout << *object1 << " + " << *object2 << " = ";
            base1->Add(base2, result);
            if (auto* res = dynamic_cast<Money*>(result)) {
                std::cout << *res << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to Money." << std::endl;
            }
            break;
        case 3:
            std::cout << *object1 << " - " << *object2 << " = ";
            if (auto* res = dynamic_cast<Money*>(result)) {
                *res = object1->Subtract(*object2);
                std::cout << *res << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to Money." << std::endl;
            }
            break;
        case 4:
            std::cout << *object1 << " * " << *object2 << " = ";
            if (auto* res = dynamic_cast<Money*>(result)) {
                *res = object1->Multiply(*object2);
                std::cout << *res << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to Money." << std::endl;
            }
            break;
        case 5:
            std::cout << *object1 << " / " << *object2 << " = ";
            if (auto* res = dynamic_cast<Money*>(result)) {
                *res = object1->Divide(*object2);
                std::cout << *res << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to Money." << std::endl;
            }
            break;
        case 6:
            float a;
            std::cout << "Input number:" << std::endl;
            std::cin >> a;
            if (auto* res = dynamic_cast<Money*>(result)) {
                std::cout << *object1 << " * " << a << " = ";
                *res = object1->Multiply(a);
                std::cout << *res << std::endl;
                std::cout << std::endl;
                std::cout << *object1 << " / " << a << " = ";
                *res = object1->Divide(a);
                std::cout << *res << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to Money." << std::endl;
            }
            break;
        case 7:
            if (*object1 == *object2) {
                std::cout << *object1 << " = " << *object2 << std::endl;
            }
            if (*object1 >= *object2) {
                std::cout << *object1 << " >= " << *object2 << std::endl;
            }
            if (*object1 <= *object2) {
                std::cout << *object1 << " <= " << *object2 << std::endl;
            }
            if (*object1 > *object2) {
                std::cout << *object1 << " > " << *object2 << std::endl;
            }
            if (*object1 < *object2) {
                std::cout << *object1 << " < " << *object2 << std::endl;
            }
            break;
        case 8:
            check = false;
            break;
        default:
            std::cout << "Error! Command doesnt exist!\n";
            std::cout << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (check);
    delete result;
    delete base1;
    delete base2;
}

void Application::String_run() {
    base1 = new String();
    base2 = new String();
    result = new String();
    auto* object1 = dynamic_cast<String*>(base1);
    auto* object2 = dynamic_cast<String*>(base2);
    std::cout << "Enter two strings: string_1  string_2" << std::endl;
    std::cin >> *object1 >> *object2;
    std::cout << *object1 << std::endl;
    std::cout << *object2 << std::endl;
    static bool check = true;
    do {
        std::cout << "_____Money menu_____" << std::endl;
        std::cout << " 1: generate new string\n"
            " 2: check Add method (a+b)\n"
            " 3: check Insert method\n"
            " 4: check Delete_part_str method\n"
            " 5: check Search_part_str method\n"
            " 6: exit\n" << std::endl;
        std::cin >> operation;
        switch (operation) {
        case 1:
            std::cin >> *object1;
            std::cin >> *object2;
            std::cout << *object1 << std::endl;
            std::cout << *object2 << std::endl;
            break;
        case 2:
            std::cout << "'" << *object1 << "'  +  '" << *object2 << "'  =  '";
            base1->Add(base2, result);
            if (auto* res = dynamic_cast<String*>(result)) {
                std::cout << *res << "'" << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to String." << std::endl;
            }
            break;
        case 3:
            int a;
            std::cout << "Enter the position of the line you want to insert into:" << std::endl;
            std::cin >> a;
            std::cout << "Insert  '" << *object2 << "'  to  '" << *object1 << "'  in the position  '" << a << "'  =  '";
            if (auto* res = dynamic_cast<String*>(result)) {
                *res = object1->Insert(a, *object2);
                std::cout << *res << "'" << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to String." << std::endl;
            }
            break;
        case 4:
            std::cout << "Delete line  '" << *object2 << "'  from line  '" << *object1 << "'  = '";
            if (auto* res = dynamic_cast<String*>(result)) {
                *res = object1->Delete_part_str(*object2);
                std::cout << *res << "'" << std::endl;
            }
            else {
                std::cerr << "Error: Failed to cast result to String." << std::endl;
            }
            break;
        case 5:
            std::cout << "Search for the first occurrence of string  '" << *object2 << "'  in string  '" << *object1 << "'  = ";
            int d;
            d = object1->Search_part_str(*object2);
            std::cout << d << std::endl;
            break;
        case 6:
            check = false;
            break;
        default:
            std::cout << "Error! Command doesnt exist!\n";
            std::cout << std::endl;
            break;
        }
    } while (check);
    delete base1;
    delete base2;
    delete result;
}