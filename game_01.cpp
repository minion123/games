#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct zawodnik {
	int dist;
	string name;
};


int best_player(int ilosc, zawodnik * Lista) {

    int best_dist = 100;
	int naj =0;
	for (int i=0; i < ilosc; i++ )
	{

		if (Lista[i].dist < best_dist )
		{
			naj = i;
			best_dist = Lista[i].dist;
		}

	}

	return naj;
}

/**
 * The code below will read all the game information for you.
 * On each game turn, information will be available on the standard input, you will be sent:
 * -> the total number of visible enemies
 * -> for each enemy, its name and distance from you
 * The system will wait for you to write an enemy name on the standard output.
 * Once you have designated a target:
 * -> the cannon will shoot
 * -> the enemies will move
 * -> new info will be available for you to read on the standard input.
 **/
int main()
{

    // game loop
    while (1) {
        int count; // The number of current enemy ships within range
        cin >> count; cin.ignore();
        
        int small_distance =  20;
        
      zawodnik Lista[50];
      
      int petla = count - 1;
      for (int i = 0; i < count; i++) {
      //   while(true)   {
            
            string enemy; // The name of this enemy
            int dist; // The distance to your cannon of this enemy
            cin >> enemy >> dist; cin.ignore(); cin.clear();
            Lista[i].name = enemy;
            Lista[i].dist = dist;
            
     
            if(i == petla)
            {
                
                int szukaj_zawodnika =  best_player( count,  Lista);
                
                cout << Lista[szukaj_zawodnika].name << endl;
                
            }
            
      
        }
         
 
    }
}