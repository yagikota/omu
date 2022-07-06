// 1201201140
// 八木洸太
// 課題に関するコメント: 
// Card_holder, Trumpというクラスを作り，オブジェクト指向を意識してコーディイングした．
// シャッフルされたカードを作成する際，std::suffleを使用しようとしたが，C++のバージョンの関係でreplit上では使用できなかったので，自前で実装した．

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

// プレイヤーとディーラーのクラス
class Card_holder {
	private:
	int holder;
	// 引いた全カード（カード履歴）
	vector<int> all_cards;
	// 引いた全カードの合計値
	int total_point;
	bool bust;
	char int_to_suit[4];

	public:
	Card_holder(int holder) {
		holder = holder;
		total_point = 0;
		bust = false;
		int_to_suit[0] = 'S';
		int_to_suit[1] = 'H';
		int_to_suit[2] = 'D';
		int_to_suit[3] = 'C';
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
		int curr_card, rank;
		char suit;
		for (int i = 0; i < all_cards.size(); i++) {
		curr_card = all_cards[i];
		rank = curr_card % 13 + 1;
		suit = int_to_suit[curr_card / 13];
		cout << suit <<  rank << endl;
		} 
	}

	void hit(vector<int>& deck) {
		int new_card;
		// 新しいカードを1枚引き，デッキから削除
		new_card = deck.back();
		deck.pop_back();

		// 引いたカードをカード履歴に追加
		all_cards.push_back(new_card);
		// ポイント加算
		total_point += point_of(new_card);
		// ゲーム終了
		if(total_point > 21) {
			bust = true;
		}
	}
};

// トランプのクラス
class Trump {
	private:
	vector<int> cardlist;

	public:
	Trump() {
		for(int i = 0; i < NUM_CARDS; i++) {
			cardlist.push_back(-1);
		}

		std::random_device rnd;
		for(int i = 0; i < NUM_CARDS; i++) {
			while(1) {
				// 乱数によって挿入位置を決定
				int place = rnd()%(NUM_CARDS);
				// 空いていれば挿入
				if(cardlist[place] == -1) {
					// iがトランプのrankとsuitの情報を持っている
					cardlist[place] = i;
					break;
				}
			}
		}
	}

	vector<int> get_card_list() {
		return cardlist;
	}
};


int main() {
	// シャッフルされたトランプの生成
	Trump trump;
	vector<int> cardlist = trump.get_card_list();
	// プレイヤーとディーラーの生成
	Card_holder player(PLAYER);
	Card_holder dealer(DEALER);


	// ディーラーがカードを2枚引き，1枚公開
	cout << "---Dealer Turn---" << endl;
	cout << "Dealer:" << endl;
	dealer.hit(cardlist);
	dealer.print_all_cards();
	dealer.hit(cardlist);
	cout << "***" << endl;
	cout << endl;


	// プレイヤーはカードを2枚引き，２枚公開
	cout << "---Player Turn---" << endl;
	cout << "Player:" << endl;
	player.hit(cardlist);
	player.hit(cardlist);
	player.print_all_cards();
	cout << endl;


	// プレイヤーのターン
	char choice = 'h';
	while(!player.is_bust()) {
		cout << "Hit (h) or Stand (s)?:" << endl;
		cin >> choice;
		if(choice == 's') break;
		cout << "Player:" << endl;
		player.hit(cardlist);
		player.print_all_cards();
	};

	if(choice != 's') {
		cout << "player bust" << endl;
		cout << "---Game Finished!---" << endl;
		goto PLAYER_LOSE_WITH_BUST;
	}


	// ディーラーのターン
	cout << "---Dealer Turn---" << endl;
	cout << "Dealer:" << endl;  
	dealer.print_all_cards();  

	while(dealer.get_total_point() < 17) {
		dealer.hit(cardlist);
		cout << "Dealer:" << endl;  
		dealer.print_all_cards();  
	};

	if(dealer.is_bust()) {
		// cout << "Dealer:" << endl;  
		// dealer.print_all_cards();
		cout << "dealer bust" << endl;
		cout << "---Game Finished!---" << endl;
		goto PLAYER_WIN_WITH_DEALER_BUST;
	}


	// ゲーム終了の処理
	cout << "---Game Finished!---" << endl;
	if(player.get_total_point() > dealer.get_total_point()) goto PLAYER_WIN;
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
