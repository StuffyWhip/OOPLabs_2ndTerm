#include <iostream>
#include "Application.h"

Application::Application(const Money& m) { amount = m; }

void Application::menu() {
    std::cout << "------------------MENU------------------" << std::endl;
    std::cout << "1. Input of sums of money" << std::endl;
    std::cout << "2. Addition of sums of money" << std::endl;
    std::cout << "3. Subtraction" << std::endl;
    std::cout << "4. Division of sums of money" << std::endl;
    std::cout << "5. Multiplication by a fractional number" << std::endl;
    std::cout << "6. Dividing by a fractional number" << std::endl;
    std::cout << "7. Comparison of sums of money" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Please enter your number: ";
}

void Application::run() {
    bool flag = true;
    int number;
    while (flag) {
        menu();
        std::cin >> number;
        std::cout << std::endl;
        switch (number) {
        case 1:
        {
            Money money;
            std::cin >> money;
            amount = money;
            std::cout << "Your number: ";
            std::cout << amount << std::endl << std::endl;
        } break;

        case 2:
        {
            std::cout << "Enter the second sum:" << std::endl;
            Money money;
            std::cin >> money;
            std::cout << "Result: " << amount << " + " << money << " = ";
            amount.add(amount, money);
            std::cout << amount << std::endl << std::endl;
        } break;

        case 3:
        {
            std::cout << "Enter the deductible: " << std::endl;
            Money money;
            std::cin >> money;
            std::cout << "Result: " << amount << " - " << money << " = ";
            amount.sub(amount, money);
            std::cout << amount << std::endl << std::endl;
        } break;

        case 4:
        {
            Money money;
            std::cin >> money;
            std::cout << "Result: " << amount << " / " << money << " = ";
            std::cout << amount.del(amount, money) << std::endl << std::endl;
        } break;

        case 5:
        {
            double num;
            std::cout << "Fractional number: ";
            std::cin >> num;
            std::cout << "Result: " << amount << " * " << num << " = ";
            amount = amount * num;
            std::cout << amount << std::endl << std::endl;
        } break;

        case 6:
        {
            double num;
            std::cout << "Fractional number: ";
            std::cin >> num;
            std::cout << "Result: " << amount << " / " << num << " = ";
            amount = amount / num;
            std::cout << amount << std::endl << std::endl;
        } break;

        case 7:
        {
            Money money;
            std::cin >> money;
            if (money == amount)
                std::cout << money << " equals " << amount << std::endl << std::endl;
            if (money > amount)
                std::cout << money << " is more than " << amount << std::endl << std::endl;
            else if (money < amount)
                std::cout << money << " is less than " << amount << std::endl << std::endl;
        } break;

        case 8:
            flag = false;
            break;

        default:
            std::cout << "Incorrect input. Enter another number..." << std::endl << std::endl;
            break;
        }
    }
}