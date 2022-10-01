#include <iostream>
#include "Sorting/Bubble.h"
#include "Sorting/Select.h"
#include "Sorting/Merge.h"

#include <complex>
#include <iostream>

typedef unsigned short int UInt;

UInt StartWindow() 
{
    std::cout << "\nChoose an algorithm: " << std::endl;
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

    while (!shutdown) 
    {
        try 
        {
            switch (StartWindow()) 
            {
                case 1: 
                {
                    Sorting::Bubble bubble;
                    bubble.Input();
                    bubble.Sorting();
                    bubble.Output();
                    break;
                }
                case 2: 
                {
                    Sorting::Select select;
                    select.Input();
                    select.Sorting();
                    select.Output();
                    break;
                }
                case 3: 
                {
                    Sorting::Merge merge;
                    merge.Input();
                    merge.Sorting();
                    merge.Output();
                    break;
                }
                case 18: 
                {
                    shutdown = true;
                    break;
                }
                default:
                    throw std::invalid_argument("Unexpected input");
            }
        }
        catch (std::exception) 
        {
            std::cout << "Incorrect choise, try again" << std::endl;
        }
    }
    
    return 0;
}

