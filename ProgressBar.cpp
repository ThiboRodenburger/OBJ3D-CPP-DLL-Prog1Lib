#include "pch.h"
#include "ProgressBar.h"

Tools::ProgressBar::SoundBar(const string& _name, const int _currentSound, const int _soundMax)
{
	name = _name;
	currentSound = _currentSound;
	soundMax = _soundMax;
}

void Tools::ProgressBar::IncreaseVolume()
{
	currentSound++;
	if (currentSound >= 50)
	{
		currentSound = 50;
	}
}
void Tools::ProgressBar::TurnDownVolume()
{
	currentSound--;
	do
	{
		if (currentSound <= 0)
		{
			currentSound = 0;
		}
	} while (true);

}

