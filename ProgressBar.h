#pragma once
#include <iostream>
#include <Windows.h>

#ifdef MYTOOL_EXPORTS
#define MYTOOL_API __declspec(dllexport)
#else
#define MYTOOL_API __declspec(dllimport)
#endif


#pragma warning(disable : 4251)

using namespace std;

#define CALBARD Sleep
namespace Tools
{
	/// <summary>
	/// Classe permettant de gérer une barre de progression
	/// </summary>
	class MYTOOL_API SoundBar
	{
		string name;
		int currentSound;
		int soundMax;

	public:
		inline string GetName() const
		{
			return name;
		}

		inline int GetCurrentSound() const
		{
			return currentSound;
		}

	public:
		SoundBar() = default;
		SoundBar(const string& _name, const int _currentsound, const int _soundMax);

	public:
		void IncreaseVolume();

		void TurnDownVolume();
	
	};
}

