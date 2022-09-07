#include <iostream>
#include "Sorting/Bubble.h"
#include "Sorting/Select.h"
#include "Sorting/Merge.h"

int main()
{
    std::vector<int> a{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    Sorting::Bubble bubble(a);
    bubble.Sorting();
    bubble.Output();
    
    std::cout << std::endl << "-------------------------------------------" << std::endl;

    Sorting::Select select(a);
    select.Sorting();
    select.Output();

    std::cout << std::endl << "-------------------------------------------" << std::endl;

    Sorting::Merge merge(a);
    merge.Sorting();
    merge.Output();
}

