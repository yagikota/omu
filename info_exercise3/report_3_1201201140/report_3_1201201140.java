// 1201201140
// 八木洸太

// ファイル読み込みのためのimport
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.lang.Math;
import java.util.Arrays;


public class report_3_1201201140 {
	// double型2次元配列を表示する関数
	public static void show(double[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[0].length; j++) {
				System.out.print(A[i][j] + ", ");
			}
			System.out.println();
		}
	}

	// String型1次元配列を表示する関数
	public static void show(String[] a) {
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + ", ");
		}
		System.out.println();
	}

	// Comparableインターフェースを実装
	// https://web.plus-idea.net/2016/02/java-object-sort/
	public static class Sort implements Comparable<Sort> {
		// ユークリッド距離
		double first;
		// ラベルのインデックス
		int second;

		public Sort(double first, int second) {
			this.first = first;
			this.second = second;
		}
		// 昇順にソート, 値が同じ場合、インデックスで昇順にソート
		public int compareTo(Sort num) {
			if (this.first <= num.first) {
				return -1;
			} else {
				return 1;
			}
		}
	}

	// xとyのユークリッド距離を算出
	public static double getDist(double[] x, double[] y) {
		double pow_dist = 0.0;
		for (int i = 0; i < x.length; i++) {
			pow_dist += Math.pow(x[i] - y[i], 2);
		}
		return Math.sqrt(pow_dist);
	}

	public static String[] getKthNearestIris(double[][] X, String[] y, int k, double[] x) {
		Sort[] sort = new Sort[X.length];
		for (int i = 0; i < X.length; i++) {
			double dist = getDist(X[i], x);
			sort[i] = new Sort(dist, i);
		}
		Arrays.sort(sort);

		// ソートしたものから先頭k個のラベルを抽出
		String[] irisList = new String[k];
		for (int i = 0; i < k; i++) {
			int idx = sort[i].second;
			irisList[i] = y[idx];
		}
		return irisList;
	}

	// 出現回数が最大の要素を返す
	static String mostFrequent(String arr[])
	{
		Arrays.sort(arr);
		int max_count = 1;
		String res = arr[0];
		int curr_count = 1;

		for (int i = 1; i < arr.length; i++) {
			if (arr[i].equals(arr[i - 1]))
				curr_count++;
			else
				curr_count = 1;

			if (curr_count > max_count) {
				max_count = curr_count;
				res = arr[i - 1];
			}
		}
		// 予測結果と近傍内クラスラベルを表示
		System.out.println(res + ":" + Arrays.toString(arr));
		return res;
	}

	// k近傍法
	// X, yを訓練データとし，入力xに対しk近傍法を実行し，予測結果を返す．
	public static String knn(double[][] X, String[] y, int k, double[] x) {
		// ここを適切に完成させる
		String[] irisList = getKthNearestIris(X, y, k, x);
		return mostFrequent(irisList);
	}

	public static void main(String[] args) {
		// 変数設定
		int n = 150; // 対象数 n
		int m = 4; // 次元数 m
		double[][] X = new double[n][m]; // データ行列 X の宣言
		String[] y = new String[n]; // 教師ラベルの配列

		// データの読込
		try {
			File file = new File("iris.data"); // ファイルのパスを指定する

			// BufferedReaderクラスのreadLineメソッドを使って1行ずつ読み込み表示する
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String row;

			// ここで X と y にデータを格納する (ここを適切に完成させる)
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
					y[i] = row_list[4];
					i++;
				};
			}
			fileReader.close(); // ファイルを閉じてリソースを開放する
		} catch (IOException e) {
			e.printStackTrace();
		}

		// データ行列 X と正解ラベル y の表示
		System.out.println("\nデータX");
		show(X);
		System.out.println("\n教師ラベル");
		show(y);
		
		// パラメータ k を定める．
		int k = 5;

		// 以下でleave-one-out交差検証法でk近傍法の性能を確認する．(ここを適切に完成させる)
		System.out.println("\n予測結果と近傍内クラスラベル");
		int correctCounter = 0;
		for (int i = 0; i < n; i++) {
			double[] x = X[i];

			// Xとyを再定義
			double[][] newX = new double[n - 1][m - 1];
			String[] newY = new String[n - 1];
			for (int j = 0; j < n - 1; j++) {
				if (j == i) {
					continue;
				}
				newX[j] = X[j];
				newY[j] = y[j];
			}
			String iris = knn(newX, newY, k, x);
			// ラベルを判定
			if (iris.equals(y[i])) {
				correctCounter++;
			}
		}
		// 予測精度
		double prediction = (double)correctCounter / (double)n;
		System.out.println("Prediction Accuracy = " + prediction);
	}
}
