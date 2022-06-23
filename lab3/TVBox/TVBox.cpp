#include <iostream>
#include "CTVSet.h"
#include "CRemoteControl.h"

int main()
{
    CTVSet tv;
    CRemoteControl remoteControl = CRemoteControl(tv, std::cin, std::cout);

    while (!std::cin.eof() && !std::cin.fail())
    {
        remoteControl.HandleCommand();
    }
}
