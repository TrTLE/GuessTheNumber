// GuessNumber.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	std::cout << "Hello World!\n";

	srand(time(NULL));

	bool numberFind = true;
	bool play = true;
	bool goodNumberEnter = true;
	int numberToFind;
	int numberUser;
	int userLife;
	string reponse;

	//Boucle principale
	while (play)
	{
		numberToFind = rand() % 20 + 1;
		userLife = 5;
		numberUser = 5;
		reponse = "";
		numberFind = true;

		//Boucle d'une partie
		while (numberFind && userLife > 0)
		{
			//Affichage du nombres de vies restantes
			if (userLife != 5)
			{
				cout << "Nouvel essai. Il vous reste " << userLife << " tentative";

				if (userLife > 1)
				{
					cout << "s";
				}

				cout << endl << endl;
			}

			//boucle de saisie de l'utilisateur d'un nouveau nombre
			do
			{
				goodNumberEnter = false;
				cout << "Saisir un nombre entre 1 et 20" << endl;
				cin >> numberUser;

				if (numberUser <= 0 || numberUser >= 21)
				{
					cout << "Le nombre que vous avez saisi n'est pas entre 1 et 20" << endl << endl;
					goodNumberEnter = true;
				}

			} while (goodNumberEnter);

			userLife--;

			//vérification si l'utilisateur à trouver le nombre mystère
			if (numberUser == numberToFind)
			{
				numberFind = false;

			}
			else
			{
				//afficher si la valeur à trouver est plus ou moins grande
				if (numberToFind > numberUser)
				{
					cout << "C'est plus" << endl;

				}
				else
				{
					cout << "C'est moins" << endl;
				}
			}

			numberUser = 0;
		}//FIN D'UNE PARTIE

		//affiche si l'utilisateur à trouver ou non le nombre mystère
		if (numberFind)
		{
			cout << "Dommage, vous réussirez la prochaine fois ;)" << endl;

		}
		else
		{
			cout << "BRAVO !!! vous avez trouvé le nombre secret" << endl << endl;
		}

		//boucle de saisie. Recommencer une nouvelle partie
		do
		{
			cout << "Une nouvelle partie ? oui - non" << endl;

			cin >> reponse;
		} while (reponse.compare("oui") != 0 && reponse.compare("non") != 0);

		//affiche une phrase en fonction d'une nouvelle partie ou non
		if (reponse.compare("oui") == 0)
		{
			cout << "Ok, c'est reparti ! Bonne chance ;)" << endl << endl;
		}
		else
		{
			cout << "Au revoir" << endl;
			play = false;
		}
	}

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
