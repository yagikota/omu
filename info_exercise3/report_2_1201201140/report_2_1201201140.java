// 1201201140
// 八木洸太

// ファイル読み込みのためのimport
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Arrays;
import java.lang.Math;

public class report_2_1201201140 {
	// 2次元配列を表示する関数
	public static void show(double[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[0].length; j++) {
				System.out.print(A[i][j] + ", ");
			}
			System.out.println();
		}
	}

	// get_random_int returns a random integer between min(inclusive) and max(exclusive).
	public static int get_random_int(int min, int max) {
		Random rand = new Random();
		return rand.nextInt(max - min + 1) + min; い
	}

	// TODO: ランダムな3整数にならない時がある
	// get_distinct_rand_int returns a list of size n which contains distinct random integer.
	public static int[] get_distinct_rand_int(int min, int max, int n) {
		int[] res = new int[n];
		int i = 0;
		while (i < n) {
			int rand_int = get_random_int(min, max);
			if (!Arrays.asList(res).contains(rand_int)){
				res[i] = rand_int;
				i++;
			}
		}
		return res;
	}

	// // クラスター中心行列 b のランダム初期化
	// // データ行列からC個の行を抽出し，初期クラスター中心行列 b を返す．
	public static double[][] b_init(double[][] X, int C) {
		// ここを適切に完成させる
		double[][] b = new double[C][X[0].length];
		int[] rand_int_list = get_distinct_rand_int(0, 149, C);
		for (int i = 0; i < C; i++) {
			b[i] = X[rand_int_list[i]];
		}
		return b;
	}

	public static double get_squared_dist(double[] x, double[] y, int n) {
		double res = 0.0;
		for (int i = 0; i < n; i++) {
			res += Math.pow((x[i] - y[i]), 2);
		}
		return res;
	}

	// // 最近隣クラスターへの割り当て
	// // クラスター中心行列 b とデータ行列 X から2乗距離行列dを算出し，
	// // dを元にメンバシップ行列uを算出して返す．
	public static double[][] u_nearest(double[][] b, double[][] X) {
		// ここを適切に完成させる
		// 2乗距離行列dを作成
		int C = 3;
		double[][] d = new double[C][X.length];
		for (int i = 0; i < b.length; i++) {
			double[] b_row = b[i];
			for (int j = 0; j < X.length; j++) {
				double[] x_row = X[j];
				d[i][j] = get_squared_dist(b_row, x_row, b_row.length);
			}
		}

		// メンバシップ行列uを算出
		double[][] u = new double[C][X.length];
		for (int j = 0; j < d[0].length; j++) {
			int min_i = 0;
			for (int i = 0; i < d.length; i++) {
				if (d[i][j] < d[min_i][j]) {
					min_i = i;
				}
			}
			u[min_i][j] = 1.0;
		}
		return u;
	}

	public static double sum(double[] x) {
		double sum = 0.0;
		for (int i = 0; i < x.length; i++) {
			sum += x[i];
		}
		return sum;
	}

	// // クラスター中心bの算出
	// // メンバシップ行列 u とデータ行列 X から
	// // 新しいクラスター中心 b を算出して返す．
	public static double[][] b_new(double[][] u, double[][] X) {
		// ここを適切に完成させる
		double[][] uX = new double[u.length][X[0].length];
		double[][] b = new double[u.length][X[0].length];

		// 行列uXの計算
		for (int i = 0; i < u.length; i++) {
			for (int j = 0; j < X[0].length; j++) {
				for (int k = 0; k < u[0].length; k++) {
					uX[i][j] += u[i][k] * X[k][j];
				}
			}
		}
		
		for (int i = 0; i < u.length; i++) {
			double cluster_cap = sum(u[i]);
			for (int j = 0; j < X[0].length; j++) {
				b[i][j] = uX[i][j] / cluster_cap;
			}
		}
		return b;
	}

	// // 収束判定
	// // u と u_old の差の絶対値によってクラスター割り当ての変化量を求める．
	// 変化がなければ true, そうでないなら false を返す．
	public static boolean convergence(double[][] u, double[][] u_old) {
		// ここを適切に完成させる
		double max_d = 0.0;
		for (int i = 0; i < u.length; i++) {
			for (int j = 0; j < u[0].length; j++) {
				max_d = Math.max(max_d, Math.abs(u[i][j] - u_old[i][j]));
			}
		}
		if (max_d == 0) {
			return true;
		} else {
			return false;
		}
	}

	public static void kmeans(double[][] X, int C) {
		int n = X.length;
		System.out.println("データ行列 X");
		show(X); // データ行列 X の表示
		double[][] u = new double[C][n]; // メンバシップ行列の宣言
		double[][] b = b_init(X, C); // 初期クラスター中心の設定
		System.out.println("初期クラスター中心 b");
		show(b); // 初期クラスター中心 b の表示
		for (int step = 0; step < 10; step++) {
			System.out.println("Step: " + step);
			double[][] u_old = u.clone(); // 前回のクラスター割り当て
			u = u_nearest(b, X); // 最近隣クラスターへの割り当て
			b = b_new(u, X); // クラスター中心bの算出
			if (convergence(u, u_old)) { // 収束判定
				break;
			}
		}
		System.out.println("クラスター割り当て u");
		show(u);
		System.out.println("クラスター中心 b");
		show(b);
	}

	public static void main(String[] args) {
		// 変数設定
		int n = 150; // 対象数 n
		int m = 4; // 次元数 m
		double[][] X = new double[n][m]; // データ行列 X の宣言

		// データの読込
		try {
			File file = new File("iris.data"); // ファイルのパスを指定する

			// BufferedReaderクラスのreadLineメソッドを使って1行ずつ読み込み表示する
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String row;

			// ここで X にデータを格納する (ここを適切に完成させる)
			// 何らかの処理
			int i = 0;
			while ((row = bufferedReader.readLine()) != null) {
				// 何らかの処理
				if (!(row.isEmpty())){
					String row_list[] = row.split(",");
					X[i][0] = Double.parseDouble(row_list[0]);
					X[i][1] = Double.parseDouble(row_list[1]);
					X[i][2] = Double.parseDouble(row_list[2]);
					X[i][3] = Double.parseDouble(row_list[3]);
					i++;
				};
			}
			fileReader.close(); // ファイルを閉じてリソースを開放する
		} catch (IOException e) { // 入出力例外発生時の処理
			e.printStackTrace(); // 標準エラー出力へ出力
		}

		// データ X に対し，クラスター数 C=3 として k-means法を実行．
		int C = 3;
		kmeans(X, C);

	// 	System.out.println("---b---");
	// 	double[][] b = b_init(X, C);
	// 	show(b);
	// 	System.out.println("---u---");
	// 	double[][] u = (u_nearest(b, X));
	// 	show(u);
	// 	System.out.println("---b_new---");
	// 	show(b_new(u, X));  
	}
}