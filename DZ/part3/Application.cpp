#include "Application.h"

Application::Application() : operation(0), base1(nullptr), base2(nullptr), result(nullptr) {}

void Application::run() {
    try {
        bool key = true;
        while (key) {
            std::cout << "_____Main Menu_____" << std::endl;
            std::cout << "1 - XorArray_run\n2 - SortArray_run\n0 - Exit\n" << std::endl;
            std::cin >> operation;
            switch (operation) {
            case 1:
                XorArray_run();
                break;
            case 2:
                SortArray_run();
                break;
            case 0:
                key = false;
                break;
            default:
                std::cout << "Error! Command doesn't exist!\n";
                std::cout << std::endl;
                break;
            }
        }
    }
    catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }
}

void Application::SortArray_run() {
    base1 = new SortArray();
    base2 = new SortArray();
    result = new SortArray();

    std::cout << "Enter arrays:" << std::endl;
    base1->enter();
    base2->enter();
    base1->print();
    base2->print();

    bool check = true;
    do {
        std::cout << "\n_____SortArray menu_____" << std::endl;
        std::cout << " 1: generate new arrays\n"
            << " 2: check Add method\n"
            << " 3: check Sort method\n"
            << " 4: exit\n" << std::endl;
        std::cin >> operation;
        switch (operation) {
        case 1:
            base1->enter();
            base2->enter();
            base1->print();
            base2->print();
            break;
        case 2:
            *result = *base1;
            std::cout << "Addition of SortArray_1 and SortArray_2" << std::endl;
            result->Add(*base2);
            result->print();
            break;
        case 3:
            *result = *base1;
            std::cout << "Ascending sort of SortArray_1" << std::endl;
            result->Sort(1);
            result->print();
            std::cout << "Descending sort of SortArray_1" << std::endl;
            result->Sort(-1);
            result->print();
            break;
        case 4:
            check = false;
            break;
        default:
            std::cout << "Error! Command doesn't exist!\n";
            std::cout << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (check);

    delete result;
    delete base2;
    delete base1;
}

void Application::XorArray_run() {
    base1 = new XorArray();
    base2 = new XorArray();
    result = new XorArray();

    std::cout << "Enter arrays:" << std::endl;
    base1->enter();
    base2->enter();
    base1->print();
    base2->print();

    bool check = true;
    do {
        std::cout << "\n_____XorArray menu_____" << std::endl;
        std::cout << " 1: generate new arrays\n"
            << " 2: check Add method\n"
            << " 3: check Sort method\n"
            << " 4: exit\n" << std::endl;
        std::cin >> operation;
        switch (operation) {
        case 1:
            base1->enter();
            base2->enter();
            base1->print();
            base2->print();
            break;
        case 2:
            *result = *base1;
            std::cout << "Addition of XorArray_1 and XorArray_2" << std::endl;
            result->Add(*base2);
            result->print();
            break;
        case 3:
            *result = *base1;
            std::cout << "Sort of XorArray_1" << std::endl;
            std::cout << "Enter the order of the arithmetic root" << std::endl;
            double a;
            std::cin >> a;
            result->Sort(a);
            result->print();
            break;
        case 4:
            check = false;
            break;
        default:
            std::cout << "Error! Command doesn't exist!\n";
            std::cout << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (check);

    delete result;
    delete base2;
    delete base1;
}
