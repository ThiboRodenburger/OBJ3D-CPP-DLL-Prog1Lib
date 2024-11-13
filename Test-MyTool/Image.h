#pragma once
#include "FileStream.h"

using namespace Tools;

class Image
{
	u_int width;
	u_int height;
	FileStream file;
	char** data;

public:
	Image(const string& _fullpath, const u_int _width, const u_int _height);
	~Image();

	void ReadImage();
	void CopyImage(const string& _fullpath);

};

