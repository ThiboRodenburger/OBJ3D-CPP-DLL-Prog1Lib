#include "pch.h"
#include "FileStream.h"

Tools::FileStream::FileStream(const string& _fullPath, const bool _autoCreate,
	const ios_base::openmode& _openMode)
{
	openMode = _openMode;
	openMode |= ios_base::binary;
	fullPath = _fullPath;
	if (_autoCreate)
	{
		ifstream(_fullPath, ios_base::app);
	}
	stream = fstream(_fullPath, openMode);
}

string* Tools::FileStream::ReadAll()
{
	const u_int& _fileSize = ComputeLineOfFile();
	string* _contents = new string[_fileSize];
	for (u_int _i = 0; _i < _fileSize; _i++)
	{
		_contents[_i] = ReadLine(GetOffset(0, _i));
	}
	return _contents;
}

string Tools::FileStream::Read(const streamsize& _length, const streampos& _position)
{
	if (!IsValid()) return "";

	string _content(_length, '\0');

	if (_position != -1)
	{
		stream.seekg(_position);
	}
	stream.read(&_content[0], _length);
	return _content;
}

string Tools::FileStream::ReadLine(const streampos& _position)
{
	if (!IsValid()) return "";

	string _content = "";

	if (_position != -1)
	{
		stream.seekg(_position);
	}
	getline(stream, _content);
	return _content;
}

bool Tools::FileStream::Write(const string& _content, const streampos& _position)
{
	return Write(_content.c_str(), _content.size(), _position);
}


streampos Tools::FileStream::GetOffset(const u_int& _horizontal, const u_int& _vertical)
{
	u_int _index = 0, _l = 0;
	char _c;
	stream.seekg(0, stream.beg);
	while (_l != _vertical ) // Aller � la bonne ligne
	{
		if (stream.get(_c))
		{
			const int _bob = stream.tellg();
			if (_c == '\n') _l++;
			_index++;
		}
		else
		{
			break;
		}
	}
	stream.seekg(_index);
	const streampos& _pos = stream.tellg();

	stream.clear();
	stream.seekg(0, stream.beg);
	return _pos;
}

streampos Tools::FileStream::ComputeLenghOfFile()
{
	
	stream.seekp(0, stream.end);
	const streampos _lengh = stream.tellg();
	stream.seekp(0);
	return _lengh;
}

bool Tools::FileStream::Write(const char* _content, const streamsize& _lengh, const streampos& _position)
{
	if (!IsValid()) return false;

	string _remainingContent;

	if (_position != -1)
	{
		stream.seekp(_position);
		getline(stream, _remainingContent, '\0');

		stream.clear();
		stream.seekg(_position);
	}
	stream.write(_content, _lengh);

	if (!_remainingContent.empty())
	{
		stream.write(_remainingContent.c_str(), _remainingContent.size());
	}
	return stream.good();
}

int Tools::FileStream::ComputeLineOfFile()
{
	int _line = 0;
	char _c;
	while(stream.get(_c))
	{
		if (_c == '\n') _line++;
	}
	stream.clear();

	stream.seekg(0, stream.beg);
	return _line - 1;
}