#include <iostream> //入出力
#include <random> //乱数生成
#include <vector> //可変長配列
#include <algorithm> //ソート

#define DECK 6 //使用するデッキ数
#define CARD 52 //トランプのカードの数(ジョーカーを除く)
#define NUM DECK*CARD //カードの総数

//カードシュークラス
class Shoe{

	private:
		//基本的にカードシューはprivate
		int card_shoe[NUM]; //カード配列
		int card_num; //カード枚数

	public:
		//コンストラクタ
		Shoe(){
			//配列を全て-1で初期化
			for(int i = 0; i < NUM; i++){
				//-1の代入
				card_shoe[i] = -1;
			}
			//乱数生成器
			std::random_device rnd;
			//配列にカードを順番に格納(iのカードをどこに挿入するかを決める)
			for(int i = 0; i < NUM; i++){
				//iのカードが挿入されるまでループ
				while(1){
					//乱数によって挿入位置を選定
					int place = rnd()%(NUM); //挿入位置
					//乱数で決めた挿入位置が空であるか確認
					if(card_shoe[place] == -1){
						//カードの格納
						card_shoe[place] = i;
						break; //ループを抜ける
					}
				}
			}
			card_num = NUM; //カード枚数の設定
		}
		//カードシューを表示(デバッグ用)
		void show_shoe(bool type){
			//typeで表示範囲を操作(trueならカード枚数分表示)
			if(type){
				//カード配列を先頭から表示する
				for(int i = 0; i < card_num; i++){
					//標準出力
					std::cout << card_shoe[i] << ' ';
				}
				//改行
				std::cout << std::endl;
				//falseなら配列全体
			}else{
				//カード配列を先頭から表示する
				for(int i = 0; i < NUM; i++){
					//標準出力
					std::cout << card_shoe[i] << ' ';
				}
				//改行
				std::cout << std::endl;
			}
		}
		//カードを1枚取り出す
		int take_card(){
			//カード枚数が0だった場合,エラーとして出力
			if(card_num == 0){
				//標準出力
				std::cout << "NoStackError\nShoe.card_num" << std::endl;
				return -1; //返り値として-1
			}
			//カード配列の先頭を格納
			int top = card_shoe[0];
			//カード配列を先頭から順に変更
			for(int i = 0; i < card_num-1; i++){
				//要素を1つずつずらす
				card_shoe[i] = card_shoe[i+1];
			}
			//必要なくなった範囲には-1を代入
			card_shoe[card_num-1] = -1;
			card_num--; //カード枚数を1減らす
			return top; //先頭にあった要素を返り値とする
		}
};

//プレイヤークラス
class Player{

	private:
		//手札関連はprivateとする
		std::vector<int> hand; //手札配列
		int hand_num; //手札枚数

	public:
		//コンストラクタ
		Player(){
			//変数の初期化
			hand_num = 0; //手札枚数を0で初期化
		}
		//スコアの計算
		int calc(){
			//メモリの動的確保
			int *data; //配列用ポインタ
			data = new int[hand_num]; //手札枚数確保
			//手札配列からデータを取得,1-10の値として格納
			for(int i = 0; i < hand_num; i++){
				//配列の値が10以下(0-9)であれば1を加えて格納
				if(hand[i]%13 < 10){
					//1-13のカードとして扱うために1加えている
					data[i] = hand[i]%13+1;
				//配列の値が10以上(10-12)であれば10を格納
				}else{
					//ここで10を格納しているのは,11-13のカードのことである
					data[i] = 10;
				}
			}
			//ソート
			std::sort(data,data+hand_num);
			//返り値用変数(計算結果)
			int score = 0;
			//2番目から順にスコアを足していく(1番目は判定が必要)
			for(int i = 1; i < hand_num; i++){
				//スコアにデータを加える
				score += data[i];
			}
			//先頭が1であるか判定
			if(data[0] == 1){
				//1をどう扱うか判定する
				if(score+11 < 22){ //11として扱ってもバーストしない場合
					//11を加える
					score += 11;
				//11として扱うとバーストする場合
				}else{
					//スコアに1を加える
					score += 1;
				}
			//先頭が1でないなら,スコアにデータをそのまま加える
			}else{
				//スコアにデータを加える
				score += data[0];
			}
			//バーストである場合は0を返す
			if(score > 21){
				//スコアに0を代入
				score = 0;
			}

			delete[] data; //メモリの解放
			return score; //計算結果を返す
		}
		//カードの追加
		void hit(Shoe *shoe){ //shoeオブジェクトポインタ
			//配列の最後にカードを追加する
			hand.push_back(shoe -> take_card());
			hand_num++; //手札枚数を増やす
		}
		//手札を表示
		void show_hand(){
			//標準出力
			std::cout << "hand: ";
			//配列の最初から最後までを順に表示
			for(int i = 0; i < hand_num; i++){
				//カードの種類(スペード,ハート,ダイヤ,クラブ)を探索
				int type = (hand[i]%52)/13; //デッキごとに分けた後,13で割った数(0-3)で4種類を分割
				//分岐条件にtypeをそのまま利用
				switch(type){
					//0であればスペードのs
					case 0:
						std::cout << 's';
						break;
					//1であればハートのh
					case 1:
						std::cout << 'h';
						break;
					//2であればダイヤのd
					case 2:
						std::cout << 'd';
						break;
					//3であればクラブのc
					case 3:
						std::cout << 'c';
						break;
					//0-3でない場合はエラー処理
					default:
						//標準出力
						std::cout << "DefTypeError\nPlayer.show_hand" << std::endl;
						break;
				}
				//標準出力
				std::cout << hand[i]%13+1 << ' ';
			}
			//改行
			std::cout << std::endl;
			std::cout << "score: " << calc() << std::endl; //スコアの表示
		}
		//ゲーム実行
		bool play(Shoe *shoe){
			//バーストするまでループ処理
			while(calc()){
				//入力
				std::string str; //文字列型
				std::cin >> str; //文字列を入力
				//hitが入力された場合
				if(str == "hit"){
					//カードの配布
					hit(shoe);
					//手札の表示
					std::cout << "====================" << std::endl;
					std::cout << "player" << std::endl;
					show_hand();
					std::cout << "====================" << std::endl;
				//standが入力された場合
				}else if(str == "stand"){
					//返り値をtrueとして終了
					return true;
				}
			}
			//バーストしているのでfalseを返して終了
			return false;
		}
};

//ディーラークラス
class Dealer{

	private:
		//手札関連はprivateとする
		std::vector<int> hand; //手札配列
		int hand_num; //手札枚数

	public:
		//コンストラクタ
		Dealer(){
			//変数の初期化
			hand_num = 0; //手札枚数を0で初期化
		}
		//スコアの計算
		int calc(){
			//メモリの動的確保
			int *data; //配列用ポインタ
			data = new int[hand_num]; //手札枚数確保
			//手札配列からデータを取得,1-10の値として格納
			for(int i = 0; i < hand_num; i++){
				//配列の値が10以下(0-9)であれば1を加えて格納
				if(hand[i]%13 < 10){
					//1-13のカードとして扱うために1加えている
					data[i] = hand[i]%13+1;
				//配列の値が10以上(10-12)であれば10を格納
				}else{
					//ここで10を格納しているのは,11-13のカードのことである
					data[i] = 10;
				}
			}
			//ソート
			std::sort(data,data+hand_num);
			//返り値用変数(計算結果)
			int score = 0;
			//2番目から順にスコアを足していく(1番目は判定が必要)
			for(int i = 1; i < hand_num; i++){
				//スコアにデータを加える
				score += data[i];
			}
			//先頭が1であるか判定
			if(data[0] == 1){
				//1をどう扱うか判定する
				if(score+11 < 22){ //11として扱ってもバーストしない場合
					//11を加える
					score += 11;
				//11として扱うとバーストする場合
				}else{
					//スコアに1を加える
					score += 1;
				}
			//先頭が1でないなら,スコアにデータをそのまま加える
			}else{
				//スコアにデータを加える
				score += data[0];
			}
			//バーストである場合は0を返す
			if(score > 21){
				//スコアに0を代入
				score = 0;
			}

			delete[] data; //メモリの解放
			return score; //計算結果を返す
		}
		//カードの追加
		void hit(Shoe *shoe){ //shoeオブジェクトポインタ
			//配列の最後にカードを追加する
			hand.push_back(shoe -> take_card());
			hand_num++; //手札枚数を増やす
		}
		//手札を表示
		void show_hand(){
			//標準出力
			std::cout << "hand: ";
			//配列の最初から最後までを順に表示
			for(int i = 0; i < hand_num; i++){
				//カードの種類(スペード,ハート,ダイヤ,クラブ)を探索
				int type = (hand[i]%52)/13; //デッキごとに分けた後,13で割った数(0-3)で4種類を分割
				//分岐条件にtypeをそのまま利用
				switch(type){
					//0であればスペードのs
					case 0:
						std::cout << 's';
						break;
					//1であればハートのh
					case 1:
						std::cout << 'h';
						break;
					//2であればダイヤのd
					case 2:
						std::cout << 'd';
						break;
					//3であればクラブのc
					case 3:
						std::cout << 'c';
						break;
					//0-3でない場合はエラー処理
					default:
						//標準出力
						std::cout << "DefTypeError\nPlayer.show_hand" << std::endl;
						break;
				}
				//標準出力
				std::cout << hand[i]%13+1 << ' ';
			}
			//改行
			std::cout << std::endl;
			std::cout << "score: " << calc() << std::endl; //スコアの表示
		}
		//ゲーム実行
		void play(Shoe *shoe){
			//スコアが16以下の場合hitを続ける
			while(calc() < 17 && calc() > 0){
				//ヒットする
				hit(shoe);
				std::cout << "hit" << std::endl;
				//手札の表示
				std::cout << "====================" << std::endl;
				std::cout << "dealer" << std::endl;
				show_hand();
				std::cout << "====================" << std::endl;
			}
		}
};

void score(Player player, Dealer dealer){

	if(player.calc() > dealer.calc()){
		std::cout << "Player Win!" << std::endl;
	}else if(player.calc() < dealer.calc()){
		std::cout << "Player Lose" << std::endl;
	}else{
		std::cout << "Push" << std::endl;
	}
}

//メイン関数
int main(){
	//カードシューオブジェクトの生成
	Shoe shoe;
	//プレイヤーオブジェクトの生成
	Player player;
	//ディーラーオブジェクトの生成
	Dealer dealer;

	//カードの配布
	std::cout << "====================" << std::endl;
	//プレイヤーに1枚目を配布
	player.hit(&shoe);
	//手札の表示
	std::cout << "====================" << std::endl;
	std::cout << "player" << std::endl;
	player.show_hand();
	std::cout << "====================" << std::endl;

	//ディーラーに1枚目を配布
	dealer.hit(&shoe);
	//手札の表示
	std::cout << "====================" << std::endl;
	std::cout << "dealer" << std::endl;
	dealer.show_hand();
	std::cout << "====================" << std::endl;

	//プレイヤーに2枚目を配布
	player.hit(&shoe);
	//手札の表示
	std::cout << "====================" << std::endl;
	std::cout << "player" << std::endl;
	player.show_hand();
	std::cout << "====================" << std::endl;

	//ディーラーに2枚目を配布
	dealer.hit(&shoe);

	//プレイヤーの実行
	//バーストしているかどうか判別
	if(player.play(&shoe)){ //バーストしていない場合
		//ディーラーの手札を表示
		std::cout << "====================" << std::endl;
		std::cout << "dealer" << std::endl;
		dealer.show_hand();
		std::cout << "====================" << std::endl;

		//ディーラーの自動実行
		dealer.play(&shoe);
		//結果の表示
		score(player,dealer);
	//バーストしている場合
	}else{
		//標準出力
		std::cout << "Burst Player Lose" << std::endl;
	}
	std::cout << "====================" << std::endl;
	return 0;
}