#pragma once
/*
	=============CREDIT=============
	- Author : Quentin OBJ3D
*/

#ifdef MYTOOL_EXPORTS
#define MYTOOL_API __declspec(dllexport)
#else
#define MYTOOL_API __declspec(dllimport)
#endif

#include <iostream>

using namespace std;

typedef unsigned int u_int;

/// <summary>
/// Structure avec x (ligne) y (colonne) pour la position du curseur
/// </summary>
struct Coord
{
	int x;
	int y;
};

namespace Tools
{
	namespace Consol
	{
		/// <summary>
		/// Permet de définir la position du curseur dans la console
		/// </summary>
		/// <param name="_x">ligne</param>
		/// <param name="_y">Colonne</param>
		/// <param name="_cursor"> Affiche ou non la barre '|' du curseur</param>
		MYTOOL_API void SetCursorPosition(const u_int& _x, const u_int& _y, const bool _cursor = false);

		/// <summary>
		/// Permet de récupérer la position du centre de la console
		/// </summary>
		/// <returns>Retourne les coordonnées X (ligne) et Y (colonne)</returns>
		MYTOOL_API Coord GetCenterConsole();

		/// <summary>
		/// Permet d'afficher au centre de la console une ligne de texte avec la possibilité de décaler l'affichage du centre (padding)
		/// et de choisir quelle touche il faut appuyer pour quitter l'affichage.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_text">Le texte à afficher</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		/// <param name="_exitKey">Touche à appuyer pour quitter (Echap par défaut)</param>
		MYTOOL_API void DisplayCenterLine(const string& _text, const Coord& _padding = { 0, 0 }, const int _exitKey = 27);

		/// <summary>
		/// Permet d'afficher au centre de la console une ligne de texte avec la possibilité de décaler l'affichage du centre (padding)
		/// et de retourner la touche sélectionné.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_text">Le texte à afficher</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		MYTOOL_API void DisplayCenterLineWithInput(const string& _text, const Coord& _padding, int& _input);

		/// <summary>
		/// Permet d'afficher au centre de la console des lignes de textes avec la possibilité de décaler l'affichage du centre (padding)
		/// et de choisir quelle touche il faut appuyer pour quitter l'affichage.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_textArray">Liste des mots à afficher par ligne</param>
		/// <param name="_size">Taille de la liste _textArray</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		/// <param name="_exitKey">Touche à appuyer pour quitter (Echap par défaut)</param>
		MYTOOL_API void DisplayCenterMultiLine(const string* _textArray, const u_int& _size, const Coord& _padding = { 0, 0 }, const int _exitKey = 27);

		/// <summary>
		/// Permet d'afficher au centre de la console des lignes de textes avec la possibilité de décaler l'affichage du centre (padding)
		/// et de retourner la touche sélectionné.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_textArray">Liste des mots à afficher par ligne</param>
		/// <param name="_size">Taille de la liste _textArray</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		MYTOOL_API void DisplayCenterMultiLineWithInput(const string* _textArray, const u_int& _size, int& _input, const Coord& _padding = { 0, 0 });

		/// <summary>
		/// Permet d'afficher au centre de la console une ligne de texte en arc-en-ciel avec la possibilité de décaler l'affichage du centre (padding)
		/// et de choisir quelle touche il faut appuyer pour quitter l'affichage.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_text">Le texte à afficher</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		/// <param name="_sync">Tout les charactère change de la même couleur</param>
		/// <param name="_exitKey">Touche à appuyer pour quitter (Echap par défaut)</param>
		MYTOOL_API void DisplayRainbowCenterLine(const string& _text, const Coord& _padding = { 0, 0 }, const bool _sync = false, const int _exitKey = 27);

		/// <summary>
		/// Permet d'afficher au centre de la console des lignes de textes avec la possibilité de décaler l'affichage du centre (padding)
		/// et de choisir quelle touche il faut appuyer pour quitter l'affichage.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_textArray">Liste des mots à afficher par ligne</param>
		/// <param name="_size">Taille de la liste _textArray</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		/// <param name="_sync">Tout les charactère change de la même couleur</param>
		/// <param name="_exitKey">Touche à appuyer pour quitter (Echap par défaut)</param>
		MYTOOL_API void DisplayRainbowCenterMultiLine(const string* _textArray, const u_int& _size, const Coord& _padding = { 0, 0 }, const bool _sync = false, const int _exitKey = 27);

		/// <summary>
		/// Permet d'afficher au centre de la console des lignes de textes avec la possibilité de décaler l'affichage du centre (padding)
		/// et de retourner la touche sélectionné.
		/// Attention à ne pas mettre de endl ou de '\n'
		/// </summary>
		/// <param name="_textArray">Liste des mots à afficher par ligne</param>
		/// <param name="_size">Taille de la liste _textArray</param>
		/// <param name="_padding">Décale l'affichage du centre</param>
		/// <param name="_sync">Tout les charactère change de la même couleur</param>
		MYTOOL_API void DisplayRainbowCenterMultiLineWithInput(const string* _textArray, const u_int& _size, int& _input, const Coord& _padding = { 0, 0 }, const bool _sync = false);
	}
}