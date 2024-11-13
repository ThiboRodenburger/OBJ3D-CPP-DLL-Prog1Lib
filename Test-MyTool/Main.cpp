#include <iostream>
#include "FileStream.h"
#include "DisplaySystem.h"

using namespace Tools;

int main()
{
    FileStream _file = FileStream("bob.txt", true);

    //_file.Write("\nBob1", _file.ComputeLenghOfFile());
    Console::DisplayRainbowCenterMultiLine(_file.ReadAll(), _file.ComputeLineOfFile());
    //DISPLAY(_file.ReadAll(), true);
}