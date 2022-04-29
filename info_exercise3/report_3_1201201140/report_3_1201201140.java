// ファイル読み込みのためのimport
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

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

	// k近傍法
	// X, yを訓練データとし，入力xに対しk近傍法を実行し，予測結果を返す．
	public static String knn(double[][] X, String[] y, int k, double[] x) {
		// ここを適切に完成させる
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
			while ((row = bufferedReader.readLine()) != null) {
				// 何らかの処理
			}
			fileReader.close(); // ファイルを閉じてリソースを開放する
		} catch (IOException e) {
			e.printStackTrace();
		}

		// データ行列 X と正解ラベル y の表示
		show(X);
		show(y);

		// パラメータ k を定める．
		int k = 5;

		// 以下でleave-one-out交差検証法でk近傍法の性能を確認する．(ここを適切に完成させる)


	}
}