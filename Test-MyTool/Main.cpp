#include <iostream>
#include "FileStream.h"
#include "DisplaySystem.h"
#include "Image.h"

using namespace Tools;

int main()
{
    FileStream _file = FileStream("bob.txt", true);
	Image _image("cat.jpg", 700,700);
	_image.ReadImage();
	_image.CopyImage("cat2.jpg");
    //_file.Write("\nBob1", _file.ComputeLenghOfFile());
    Console::DisplayRainbowCenterMultiLine(_file.ReadAll(), _file.ComputeLineOfFile());
    //DISPLAY(_file.ReadAll(), true);
}