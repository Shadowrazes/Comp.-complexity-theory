﻿#include <iostream>
#include "Sorting/Bubble.h"
#include "Sorting/Select.h"
#include "Sorting/Merge.h"
#include "Input/KeyboardInput.h"

typedef unsigned short int UInt;

UInt StartWindow() {
    std::cout << "Choose an algorithm: " << std::endl;
    std::cout << "1) Bubble Sort" << std::endl;
    std::cout << "2) Select Sort" << std::endl;
    std::cout << "3) Merge Sort" << std::endl;
    std::cout << "18) Exit" << std::endl << std::endl;
    std::cout << "Choise: ";

    UInt choice = 0;
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

int main()
{
    bool shutdown = false;

    Input::KeyboardInput window;

    while (!shutdown) {
        try {
            switch (StartWindow()) {
            case 1: {
                Sorting::Bubble bubble(window.Input());
                bubble.Sorting();
                bubble.Output();
            }
            case 2: {
                Sorting::Select select(window.Input());
                select.Sorting();
                select.Output();
            }
            case 3: {
                Sorting::Merge merge(window.Input());
                merge.Sorting();
                merge.Output();
            }
            case 18: {
                shutdown = true;
                break;
            }
            default:
                throw std::invalid_argument("A numbers was expected, but a string was received");
            }
        }
        catch (std::exception) {
            std::cout << "Incorrect input, try again" << std::endl;
        }
    }
    
    return 0;
}

