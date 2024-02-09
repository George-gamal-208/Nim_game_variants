#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int Ncoins = 23;
const int max_move = 3;
const int no_good_move = -1;
int comuter_pile = 0;
int Human_pile = 0;
int P = 0;
enum player{Human,Computer};
player whoseturn=Human;
int Getusermove() {
	int ntaken = 0;
	cin >> ntaken;
	Human_pile += ntaken;
	return ntaken;
}
void Winner(int ncoins) {
	if (ncoins == 0) {
		if (comuter_pile % 2 == 0)
			cout << "Computer wins" << endl;
		else if (Human_pile % 2 == 0)
			cout << "Human wins" << endl;
	}
}
int FindGoodMove(int ncoins, int C_pile,int H_pile);
bool isbadmove(int ncoins, int C_pile, int H_pile);
int Getcomputermove(int ncoins);
int main() {
	int ncoins = 0, ntaken = 0;
	ncoins = Ncoins;
	while (true) {
		if (ncoins == 0)
			break;
		switch (whoseturn) {
		case Human:
			cout << "enter number between 1 and 3" << endl;
			cout << "The number of rest coins =" << ncoins << endl;
			ntaken = Getusermove();
			whoseturn = Computer;
			cout << "Human has " << Human_pile << " coins" << endl;
			break;
		case Computer:
			cout << "computer turn" << endl;
			ntaken = Getcomputermove(ncoins);
			cout << ntaken << endl;
			whoseturn = Human;
			cout << "Computer has "<<comuter_pile << " coins" << endl;
			break;
		}
		ncoins -= ntaken;
	}
	Winner(ncoins);
}
int FindGoodMove(int ncoins, int C_pile,int H_pile) {
	
	if (ncoins == 1) {
		if (whoseturn == Human) {
			if (isbadmove(ncoins - 1, C_pile, H_pile + 1)) {
				whoseturn = Computer;
				return 1;
			}
		}
		else if (whoseturn == Computer) {
			if (isbadmove(ncoins - 1, C_pile+1, H_pile )) {
				whoseturn = Human;
				return 1;
			}
		}
	}
	else if (ncoins == 2) {
		for (int i = 1; i <= 2; i++) {
			if (whoseturn == Human) {
				if (isbadmove(ncoins - i, C_pile, H_pile+i )) {
					whoseturn = Computer;
					return i;
				}
			}
			else if (whoseturn == Computer) {
				if (isbadmove(ncoins - i, C_pile+i, H_pile )) {
					whoseturn = Human;
					return i;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (whoseturn == Human) {
				if (isbadmove(ncoins - i, C_pile,H_pile+i)) {
					whoseturn = Computer;
					return i;
				}
			}
			else if (whoseturn == Computer) {
				if (isbadmove(ncoins - i, C_pile+i, H_pile )) {
					whoseturn = Human;
					return i;
				}
			}
			
		}
	}
	return -1;
}
bool isbadmove(int ncoins, int C_pile,int H_pile) {
	
	if (whoseturn == Computer) {
		whoseturn = Human;
		P = C_pile;
	}
	else if (whoseturn == Human) {
		whoseturn = Computer;
		P = H_pile;
	}
	if (ncoins == 0 && P % 2 == 0)
		return true;
	if (ncoins == 0)
		return false;
	return(FindGoodMove(ncoins, C_pile, H_pile) == -1);
}
int Getcomputermove(int ncoins) {
	int ntaken = FindGoodMove(ncoins, comuter_pile,Human_pile);
	if (ntaken == -1)
		ntaken = 1;
	comuter_pile += ntaken;
	return ntaken;
}
