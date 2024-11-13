#include "Image.h"

Image::Image(const string& _fullpath, const u_int _width, const u_int _height)
{
	file = FileStream(_fullpath, false, ios_base::binary);
	width = _width;
	height = _height;
	
	data = new char* [height];
	for (u_int _i = 0; _i < height; _i++)
	{
		data[_i] = new char[width];
	}

}

Image::~Image()
{
	for (u_int _i = 0; _i < height; _i++)
	{
		delete[] data[_i];
	}
	delete[] data;
}

void Image::ReadImage()
{
	string _content = file.Read(5, 0);
	/*u_int _lines = file.ComputeLineOfFile();
	u_int _index = 0;

	for (u_int _i = 0; _i < _lines; _i++)
	{
		for (u_int _j = 0; _j < width; _j++)
		{
			data[_i][_j] = _content[_i][_j];
		}
	}

	delete[] _content;*/
}

void Image::CopyImage(const string& _fullpath)
{
	FileStream _file = FileStream(_fullpath, true);
	for (u_int _i = 0; _i < height; _i++)
	{
		_file.Write(data[_i], width);
	}
}
