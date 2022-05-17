// 1201201140
// 八木洸太

#include <iostream>
#include <vector>
#include <random>

// トランプ1組のカード枚数
#define NUM_CARDS 52 
// プレイヤとディーラの区別用
enum HOLDER { 
PLAYER, // 0
DEALER  // 1
};

using namespace std;


class Card_holder {

	private:
	int holder;
	// 引いた全カード（カード履歴）
	vector<int> all_cards;
	// 引いた全カードの合計値
	int total_point;
	bool bust;

	public:
	Card_holder(int holder) {
		holder = holder;
		total_point = 0;
		bust = false;
	}


	int get_total_point() {
		return total_point;
	};

	bool is_bust() {
		return bust;
	};


	int point_of(int card) {
	int rank = card % 13 + 1;
	// 数字が10，11(J)，12(Q)，13(K) のカード： 10とする
		if(rank >= 11) {
	rank = 10;
	}
	// 数字が1(A) のカード
	if (rank == 1) {
	// プレイヤー
	if (holder == PLAYER && total_point < 10) {
		rank = 11;
	}
	// ディーラーは常に１とする
	}

	// この時のランクがポイントになる
		return rank;
	};

	// これまで引いた全カード表示
	void print_all_cards() {
		char int_to_suit[4] = {'S', 'H', 'D', 'C'};
		int curr_card, rank;
		char suit;
		for (int i = 0; i < all_cards.size(); i++) {
		curr_card = all_cards[i];
		rank = curr_card % 13 + 1;
		suit = int_to_suit[curr_card / 13];
		cout << suit <<  rank << endl;
		} 
	}

// 新しいカードを1枚引く
	void hit(vector<int>& deck) {
		int new_card;
		new_card = deck.back();
		deck.pop_back();

	// 引いたカードをカード履歴に追加
	all_cards.push_back(new_card);
	
		total_point += point_of(new_card);
	// ゲーム終了
		if(total_point > 21) {
	bust = true;
	}
	}
};

class Trump {
	private:
	vector<int> cardlist;

	public:
	Trump() {
		for(int i = 0; i < NUM_CARDS; i++) {
		cardlist[i] = -1;
		}
		//乱数生成
		std::random_device rnd;
		//配列にカードを順番に格納(iのカードをどこに挿入するかを決める)
		for(int i = 0; i < NUM_CARDS; i++) {
			//iのカードが挿入されるまでループ
			while(1) {
				//乱数によって挿入位置を選定
				int place = rnd()%(NUM_CARDS); //挿入位置
				//乱数で決めた挿入位置が空であるか確認
				if(cardlist[place] == -1) {
				//カードの格納
				cardlist[place] = i;
				break; //ループを抜ける
				}
			}
		}
	}

	vector<int> get_card_list() {
		return cardlist;
	}
};


int main() {
// 	// 1-13のカード4種類をランダムにシャッフル
// // TODO: クラスにする？
// 	vector<int> cardlist(NUM_CARDS);
// 	for(int i = 0; i < NUM_CARDS; i++) {
// 		//-1の代入
// 		cardlist[i] = -1;
// 	}

// 	// シャッフルされたカードを生成
// 	std::random_device rnd;
// 	for(int i = 0; i < NUM_CARDS; i++) {
// 		while(1) {
// 		int place = rnd() % (NUM_CARDS);
// 		if(cardlist[place] == -1) {
// 			cardlist[place] = i;
// 			break;
// 		}
// 		}
// 	}

	Trump trump;
	vector<int> cardlist = trump.get_card_list();

	Card_holder player(PLAYER);
	Card_holder dealer(DEALER);


	cout << "---Dealer Turn---" << endl;
	// ディーラーのカードを2枚引き，1枚公開
	// （ここでは１枚だけ引き，２枚引いたように見せている）
	cout << "Dealer:" << endl;
	dealer.hit(cardlist);
	dealer.print_all_cards();
	dealer.hit(cardlist);
	cout << "***" << endl;
	cout << endl;

	cout << "---Player Turn---" << endl;
	// プレイヤーはカードを2枚引き，２枚公開
	cout << "Player:" << endl;
	player.hit(cardlist);
	player.hit(cardlist);
	player.print_all_cards();
	cout << endl;

	char choice = 'h';
	while(!player.is_bust()) {
		cout << "Hit (h) or Stand (s)?:" << endl;
		cin >> choice;
		if(choice == 's') {
		break;
	}
	cout << "Player:" << endl;
		player.hit(cardlist);
		player.print_all_cards();
	};

	if(choice != 's') {
		player.print_all_cards();
		cout << "player bust" << endl;
		cout << "---Game Finished!---" << endl;
		goto PLAYER_LOSE_WITH_BUST;
	}


	// バーストしてなければディーラーのターン
	cout << "---Dealer Turn---" << endl;


	while(dealer.get_total_point() < 17) {
		dealer.hit(cardlist);
		cout << "Dealer:" << endl;  
		dealer.print_all_cards();  
	};

	if(dealer.is_bust()) {
		// dealer.print_all_cards();
		cout << "dealer bust" << endl;
		cout << "---Game Finished!---" << endl;
		goto PLAYER_WIN_WITH_DEALER_BUST;
	}

	cout << "---Game Finished!---" << endl;
	if(player.get_total_point() > dealer.get_total_point()) goto PLAYER_WIN ;
	if(player.get_total_point() == dealer.get_total_point()) goto NO_GAME;
	if(player.get_total_point() < dealer.get_total_point()) goto PLAYER_LOSE;

	PLAYER_WIN:
		cout << "Player win" << "(Player:" << player.get_total_point() << ", Dealer:" << dealer.get_total_point() << ")" << endl;
		return 0;
	PLAYER_WIN_WITH_DEALER_BUST:
		cout << "Player win" << "(Player:" << player.get_total_point() << ", Dealer:" << dealer.get_total_point() << ")(Dealer Bust)" << endl;
		return 0;
	PLAYER_LOSE:
		cout << "Player lose" << "(Player:" << player.get_total_point() << ", Dealer:" << dealer.get_total_point() << ")" << endl;
		return 0;
	PLAYER_LOSE_WITH_BUST:
		cout << "Player lose" << "(Player:" << player.get_total_point() << ", Dealer:" << dealer.get_total_point() << ")(Player Bust)" << endl;
		return 0;
	NO_GAME:
		cout << "Push" << "(Player:" << player.get_total_point() << ", Dealer:" << dealer.get_total_point() << ")" << endl;
		return 0;
}
