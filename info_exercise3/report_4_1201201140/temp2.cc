

#include <iostream>
#include <vector>
#include <random>
using namespace std;


//
// プレーヤーとディーラーを共通して扱うクラス
//

class Card_holder{

	private:
	int hand;
	bool bursted = false;

	public:

	bool stayed = false;

	int open_hand(){
		return hand;
	};

	int isbursted(){
		return bursted;
	};


	int valueof(int card){
		int cardtonum;
		int cardtotype;

		cardtonum = card % 13 + 1;
		cardtotype = card/13;

		cout << "Card is " << cardtonum << " of " << cardtotype << endl;

		if(cardtonum >= 11) cardtonum = 10;

		return cardtonum;

	};

	void hit(vector<int>& deck){
		int new_card;
		new_card = deck.back();
		deck.pop_back();
		hand = hand + valueof(new_card);
		if(hand > 21) bursted = true;

	};

};



int main() {

	//
	// 1-13のカード4種類をランダムにシャッフル
	//

	vector<int> cardlist(13*4);

	for(int i = 0; i < 13*4; i++) cardlist[i] = i;

	random_device seed_gen;
	mt19937 engine(seed_gen());
	shuffle(cardlist.begin(), cardlist.end(), engine);

	Card_holder player;
	Card_holder dealer;


	//
	// ディーラーのカードを一枚公開
	//

	cout << "dealer card" << endl;
	dealer.hit(cardlist);

	//
	// プレーヤーのターン
	//

	cout << "Player turn" << endl;
	cout << "player card" << endl;
	player.hit(cardlist);
	player.hit(cardlist);
	cout << "player hand is " << player.open_hand() << endl;


	char stay = 'n';

	while(!player.isbursted()){
		cout << "if stay, type y" << endl;
		cin >> stay;
		if(stay == 'y') break;
		player.hit(cardlist);
		cout << "player hand is " << player.open_hand() << endl;
	};

	if(stay != 'y') {
		cout << "player bursted" << endl;
		goto PLAYER_LOSE;
	}



	//
	// バーストしてなければディーラーのターン
	//

	cout << "dealer turn" << endl;


	while(dealer.open_hand() < 17){
		dealer.hit(cardlist);
		cout << "dealer hand is " << dealer.open_hand() << endl;;

	};

	if(dealer.isbursted()) {
		cout << "dealer bursted" << endl;
		goto PLAYER_WIN;
	}


	//
	// 勝敗判定
	//

	cout << "Result" << endl;
	cout << "player card is " << player.open_hand() << endl;
	cout << "dealer card is " << dealer.open_hand() << endl;


	if(player.open_hand() > dealer.open_hand()) goto PLAYER_WIN ;
	if(player.open_hand() == dealer.open_hand()) goto NO_GAME;
	if(player.open_hand() < dealer.open_hand()) goto PLAYER_LOSE;



	PLAYER_WIN:
		cout << "player win" << endl;
		return 0;
	PLAYER_LOSE:
		cout << "player lose" << endl;
		return 0;
	NO_GAME:
		cout << "no game" << endl;
		return 0;


}

