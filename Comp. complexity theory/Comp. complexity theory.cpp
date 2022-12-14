#include <iostream>
#include <iostream>
#include "Sorting/Bubble.h"
#include "Sorting/Select.h"
#include "Sorting/Merge.h"
#include "Fourier/DiscreteFourier.h"
#include "Fourier/SemiFastFourier.h"
#include "Folding/SimpleFolding.h"
#include "Folding/DiscreteFourierFolding.h"
#include "Folding/SemiFastFourierFolding.h"
#include "Multiplication/SimpleMultipl.h"
#include "Multiplication/Karatsuba.h"
#include "Stealer/Stealer.h"
#include "Graphs/FordBellman.h"
#include "Graphs/Dijkstra.h"
#include "Graphs/Kruskal.h"
#include "Graphs/SalesmanHugo.h"

typedef unsigned short int UInt;

UInt StartWindow() 
{
    std::cout << "\n-----------------------------------------------------" << std::endl;
    std::cout << "\nChoose an algorithm: " << std::endl;
    std::cout << "1) Bubble Sort" << std::endl;
    std::cout << "2) Select Sort" << std::endl;
    std::cout << "3) Merge Sort" << std::endl;
    std::cout << "4) Discrete Fourier transform" << std::endl;
    std::cout << "5) Semi-fast Fourier transform" << std::endl;
    std::cout << "6) Simple folding" << std::endl;
    std::cout << "7) Discrete Fourier folding" << std::endl;
    std::cout << "8) Semi-fast Fourier folding" << std::endl;
    std::cout << "9) Multiplication" << std::endl;
    std::cout << "10) Karatsuba" << std::endl;
    std::cout << "13) Kruskal" << std::endl;
    std::cout << "14) Ford-Bellman" << std::endl;
    std::cout << "15) Dijkstra" << std::endl;
    std::cout << "16) Stealer" << std::endl;
    std::cout << "18) RGR" << std::endl << std::endl;
    std::cout << "19) Exit" << std::endl << std::endl;
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
                case 4:
                {
                    Fourier::DiscreteFourier discrFurier;
                    discrFurier.Input();
                    discrFurier.Output("Initial array: ");
                    discrFurier.DirectDFT();
                    discrFurier.ReverseDFT();
                    std::cout << "\nOperations: " << discrFurier.GetOperationCount() << std::endl;
                    break;
                }
                case 5:
                {
                    Fourier::SemiFastFourier semiFastFurier;
                    semiFastFurier.Input();
                    semiFastFurier.Output("Initial array: ");
                    semiFastFurier.DirectSFFT();
                    semiFastFurier.ReverseSFFT();
                    std::cout << "\nOperations: " << semiFastFurier.GetOperationCount() << std::endl;
                    break;
                }
                case 6:
                {
                    Folding::SimpleFolding simpleFolding;
                    simpleFolding.Input();
                    simpleFolding.Fold();
                    simpleFolding.Output("Initial arrays: ");
                    std::cout << "\nOperations: " << simpleFolding.GetOperationCount() << std::endl;
                    break;
                }
                case 7: 
                {
                    Folding::DiscreteFourierFolding discrFurierFolding;
                    discrFurierFolding.Input();
                    discrFurierFolding.Fold();
                    discrFurierFolding.Output();
                    std::cout << "\nOperations: " << discrFurierFolding.GetOperationCount() << std::endl;
                    break;
                }
                case 8:
                {
                    Folding::SemiFastFourierFolding semiFastFourierFolding;
                    semiFastFourierFolding.Input();
                    semiFastFourierFolding.Fold();
                    semiFastFourierFolding.Output();
                    std::cout << "\nOperations: " << semiFastFourierFolding.GetOperationCount() << std::endl;
                    break;
                }
                case 9:
                {
                    Multiplication::SimpleMultipl multipl;
                    multipl.Input();
                    multipl.Process();
                    multipl.Output();
                    break;
                }
                case 10:
                {
                    Multiplication::Karatsuba karatsuba;
                    karatsuba.Input();
                    karatsuba.Process();
                    karatsuba.Output();
                    break;
                }
                case 13:
                {
                    Graph::Kruskal kruskal;
                    kruskal.Input();
                    kruskal.Calculate();
                    kruskal.Output();
                    break;
                }
                case 14:
                {
                    Graph::FordBellman fordBellman;
                    fordBellman.Input();
                    fordBellman.Calculate();
                    fordBellman.Output();
                    break;
                }
                case 15:
                {
                    Graph::Dijkstra dijkstra;
                    dijkstra.Input();
                    dijkstra.Calculate();
                    dijkstra.Output();
                    break;
                }
                case 16:
                {
                    DynamicProg::Stealer stealer;
                    stealer.Input();
                    stealer.Steal();
                    std::cout << "\nComplexity: " << stealer.GetComplexitry() << "\n";
                    break;
                }
                case 18:
                {
                    Graph::Salesman salesman;
                    salesman.Input();
                    salesman.Calculate();
                    break;
                }
                case 19: 
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

