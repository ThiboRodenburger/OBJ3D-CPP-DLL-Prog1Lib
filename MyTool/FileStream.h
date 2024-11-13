#pragma once

#ifdef MYTOOL_EXPORTS
#define MYTOOL_API __declspec(dllexport)
#else
#define MYTOOL_API __declspec(dllimport)
#endif

#include "Macro.h"
#include <fstream> // fichier

#pragma warning(disable : 4251)

namespace Tools
{
	class MYTOOL_API FileStream
	{
		string fullPath;
		fstream stream;
		ios_base::openmode openMode;

	public:

		FileStream() = default;

		FileStream(const string& _fullPath, const bool _autoCreate = false, 
			const ios_base::openmode& _openMode = ios_base::in | ios_base::out | ios_base::binary);

	public:
		bool IsValid()const
		{
			return stream.is_open();
		}

	public:

		// Afficher un nombre n de lignes � partir d'un index
		string* ReadAll();

		string Read(const streamsize& _length, const streampos& _position = -1);

		string ReadLine(const streampos& _position = -1);

		bool Write(const string& _content, const streampos& _position=-1);

		streampos GetOffset(const u_int& _horizontal, const u_int& _vertical);

		int ComputeLineOfFile();

		streampos ComputeLenghOfFile();
	private:
		bool Write(const char* _content, const streamsize& _lengh, const streampos& _position);
	};
}
