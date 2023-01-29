#include <iostream>
using namespace std;
int count_six = 0;
int no_of_turn = 0;
bool lets_move(int **&arr,int player_no) {

	if (rand() % 7 == 6) {
		count_six++;
		arr[player_no][0]++;
		arr[player_no][1]++;
		no_of_turn++;
		if (count_six == 3)
			return 0;
		else
		lets_move(arr,player_no);
	}
	else {
		arr[player_no][0]++;
		no_of_turn++;
		return 0;
	}
	count_six=0;
	return 0;
}
int main() {
	int no_of_players = 0;
	cout << "\t\t  --Welcome To The Yalla Ludo-- " << endl;
	p:
	cout << "\t\tEnter How Many Players Want To Play : ";cin >> no_of_players;
	if (no_of_players == 1 || no_of_players > 4) {
		cout << "\t\t  Invalid Players..!!!" << endl;
		cout << "\t\t  Players always greater than one and less than five " << endl;
		goto p;
	}
	int** players_info = new int* [no_of_players];
	
	for (int i = 0;i < no_of_players;i++) {
		players_info[i] = new int[1];
	}

	for (int i = 0;i < no_of_players;i++) {
		for (int j = 0; j < 2;j++)
			players_info[i][j] = 0;
	}

	int next_turn = 0;
	bool check_turn_over = true;

	for (int i = 0;i <= 200;i++) {
		if (check_turn_over) {
			check_turn_over = lets_move(players_info, next_turn);
			i = no_of_turn;
		}
		if (!check_turn_over) {
			next_turn++;
			next_turn %= no_of_players;
			if (next_turn == no_of_players) { next_turn = 0; }
			check_turn_over = true;
		}
	}
	cout << "\t\t-----------------------------------" << endl;
	cout << "\t\t\t  Number of Turns" << endl;
	for (int i = 0;i < no_of_players;i++) {
			cout <<"\t\t\t  Player "<<i+1<<" : "<<players_info[i][0];
		cout << endl;
	}
	cout << "\t\t-----------------------------------" << endl;

	cout << "\t\t-----------------------------------" << endl;
	cout << "\t\t\t  Number of Six" << endl;
	for (int i = 0;i < no_of_players;i++) {
		cout << "\t\t\t  Player " << i + 1 << " : " << players_info[i][1];
		cout << endl;
	}
	cout << "\t\t-----------------------------------" << endl;

	return 0;
}

