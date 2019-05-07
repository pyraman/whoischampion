#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
	cout<<"Who is champain"<<endl;

	srand(time(NULL));
	vector<string> lstPlayers;
	string szPlayer;
	ifstream playersFile ("./players.txt");

	if(playersFile.is_open() == false){
		cout<<"Missing players list file"<<endl;
		system("pause");
		return -1;
	}

	cout<<"Player list:"<<endl;
	while ( getline (playersFile, szPlayer) )
    {
      cout <<"\t"<< szPlayer << '\n';
	  lstPlayers.push_back(szPlayer);
    }
    playersFile.close();

	int nPlayerCount = lstPlayers.size();
	int nIndex = 0;
	while(nPlayerCount > 0){
		int nRand = rand();
		int nPlayerIndex = nRand % nPlayerCount;
		string szPlayer = lstPlayers.at(nPlayerIndex);

		if(nIndex % 2 == 0){
			cout<<endl;
			cout<<"Left Player: "<<szPlayer<<endl;
		}
		else{
			cout<<"Right Player: "<<szPlayer<<endl;
		}
		lstPlayers.erase(lstPlayers.begin() + nPlayerIndex);
		nPlayerCount = lstPlayers.size();
		nIndex++;
	}

	cin >> szPlayer;
	return 0;
}