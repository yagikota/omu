package main

import (
	"fmt"
	"math"
)

const (
	// 行列の次元
	N = 6
	// 収束半径
	E = 0.00000000001

	MaxCal = 100
)

// QR分解で固有値、固有ベクトルを求める
// 収束に時間かかる
func main() {
	// a := [][]float64{{5.0, 4.0, 1.0, 1.0},
	// 				{4.0, 5.0, 1.0, 1.0},
	// 				{1.0, 1.0, 4.0, 2.0},
	// 				{1.0, 1.0, 2.0, 4.0}}

	// a := [][]float64{{6,-1,-2},
	// 				{4,1,-2},
	// 				{5,-1,-1}}

	// 視覚特性
	// a := [][]float64{
	// 	{11, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 3, 0, 0, 1},
	// 	{0, 11, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1, 0, 0, 1},
	// 	{0, 0, 11, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1, 0, 0, 1},
	// 	{3, 3, 3, 9, 0, 0, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	// 	{0, 0, 0, 0, 12, 0, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	// 	{0, 0, 0, 0, 0, 12, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	// 	{3, 3, 3, 1, 1, 1, 7, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	// 	{0, 0, 0, 0, 0, 0, 0, 13, 0, 1, 0, 0, 3, 0, 0, 1},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 13, 3, 0, 0, 3, 0, 0, 3},
	// 	{3, 3, 3, 1, 1, 1, 1, 1, 1.0/3.0, 5, 0, 0, 1, 0, 0, 1},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 1, 0, 0, 1.0/3.0},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 1, 0, 0, 1},
	// 	{1.0/3.0, 1, 1, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1, 1, 1, 3, 0, 0, 1},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 1},
	// 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 1},
	// 	{1, 1, 1, 1, 1, 1, 1, 1, 1.0/3.0, 1, 3, 1, 1, 1, 1, 1},
	// 	};

	// 固有値、固有ベクトルを求めたい行列
	a := [][]float64{
		{1.0, 1.0, 5.0, 3.0, 9.9, 7.0},
		{1.0, 1.0, 1.0, 1.0 / 5.0, 1.0 / 3.0, 1.0 / 3.0},
		{1.0 / 5.0, 1.0, 1.0, 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0},
		{1.0 / 3.0, 5.0, 3.0, 1.0, 1.0, 3.0},
		{1.0 / 9.0, 3.0, 3.0, 1.0, 1.0, 3.0},
		{1.0 / 7.0, 3.0, 3.0, 1.0 / 3.0, 1.0 / 3.0, 1.0},
	}

	// QR分解のQの初期化
	q := initNthMatrixWithZero(N)
	// QR分解のRの初期化
	r := initNthMatrixWithZero(N)

	x := identNthMatrix(N)
	newX := initNthMatrixWithZero(N)

	for k := 0; k < MaxCal; k++ {
		// QR分解 A=QR
		decomp(a, q, r)
		// 行列の積A=RQ
		multiply(r, q, a)
		// 行列の積newX=XQ
		multiply(x, q, newX)

		// 収束判定(行列の左下が0, つまり右三角行列になればbreak)
		e := 0.0
		for i := 1; i < N; i++ {
			for j := 0; j < i; j++ {
				e += math.Abs(a[i][j])
			}
		}
		if e < E {
			fmt.Println("ok")
			break
		}
		x = newX
	}

	fmt.Println("\n固有値")
	disp_eigenvalue(a)
	fmt.Println("\n固有ベクトル")
	for i := 0; i < N; i++ {
		fmt.Println(x[i])
	}
}

func initNthMatrixWithZero(n int) [][]float64 {
	matrix := make([][]float64, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]float64, n)
	}
	return matrix
}

func identNthMatrix(n int) [][]float64 {
	matrix := initNthMatrixWithZero(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				matrix[i][j] = 1.0
			}
		}
	}
	return matrix
}

// QR分解
func decomp(a [][]float64, q [][]float64, r [][]float64) {
	x := make([]float64, N)

	for k := 0; k < N; k++ {
		for i := 0; i < N; i++ {
			x[i] = a[i][k]
		}

		for j := 0; j < k; j++ {
			t := 0.0
			for i := 0; i < N; i++ {
				t += a[i][k] * q[i][j]
			}
			r[j][k] = t
			r[k][j] = 0.0
			for i := 0; i < N; i++ {
				x[i] -= t * q[i][j]
			}
		}

		s := 0.0
		for i := 0; i < N; i++ {
			s += x[i] * x[i]
		}
		r[k][k] = math.Sqrt(s)
		for i := 0; i < N; i++ {
			q[i][k] = x[i] / r[k][k]
		}
	}
}

// 行列の積
func multiply(a [][]float64, b [][]float64, c [][]float64) {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			s := 0.0
			for k := 0; k < N; k++ {
				s += a[i][k] * b[k][j]
			}
			c[i][j] = s
		}
	}
}

// 対角要素を表示
func disp_eigenvalue(a [][]float64) {
	for i := 0; i < N; i++ {
		fmt.Printf("%14.10f\t", a[i][i])
	}
	fmt.Println("")
}
