//
//  hopfield_sample_modified1.cpp
//
//  Created by Naoki Masuyama on 2020/05/08.
//  Copyright © 2020 Naoki Masuyama. All rights reserved.
//




//////////////////////////////////////////////////////

// 学籍番号：1201201140
// 氏名：八木洸太

//////////////////////////////////////////////////////




#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

using namespace std;

#define N 5     // Number of Data
#define dim 64  // Dimensions of Data
#define SIZE 8

// Train Data
int X[][dim+1]={
	{-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1},  // A
	{ 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1,-1},  // B
	{-1,-1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1},  // C
	{ 1, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1, 1, 1, 1, 1, 1,-1,-1,-1},  // D
	{ 1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1,-1,-1, 1,-1, 1, 1,-1,-1, 1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1,-1,-1,-1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  // E
};

// Test Data (These are Train Data with noise.)
int noiseX[][dim+1]={
	{ 1,-1, 1, -1, 1,-1,-1,-1,-1, 1,-1, 1, 1, 1,-1,-1, 1, 1,-1,-1,-1, 1, 1,-1, 1, 1, 1,-1,-1, 1, 1,-1, 1,-1, 1,-1, 1, 1, 1,-1, 1, 1, 1, 1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1,-1,-1, 1,-1,-1,-1,-1, 1,-1}, // A with noise
	{ 1, 1, 1, 1, 1, 1,-1,-1,-1, 1, 1, 1,-1, 1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1, 1, 1, 1, 1, 1, 1, 1,-1, 1, 1,-1,-1},  // B with noise
	{-1,-1, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1, 1,-1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1, 1, 1,-1,-1,-1,-1,-1,-1, 1,-1, 1,-1,-1,-1, 1, 1,-1, 1,-1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1, 1,-1,-1},  // C with noise
	{ 1, 1, 1, 1, 1, 1,-1,-1,-1, 1,-1, 1, 1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1, 1, 1,-1,-1,-1,-1, 1,-1,-1, 1, 1, 1,-1,-1, 1, 1, 1, 1, 1,-1,-1,-1, 1,-1,-1, 1, 1,-1, 1, 1, 1,-1, 1, 1, 1, 1, 1,-1,-1,-1},  // D with noise
	{ 1, 1,-1, 1,-1,-1, 1, 1,-1, 1, 1,-1, 1,-1,-1, 1,-1,-1, 1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1, 1,-1,-1,-1,-1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1,-1, 1,-1,-1,-1, 1, 1,-1, 1,-1,-1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  // E with noise
};


// Show Results by ■ and □
void drawResult(double ary[]){
	int cnt=0;
	for(int i=0;i<dim;i++){
		if(ary[i]>=0.0){
			printf("■");
		}
		else{
			printf("□");
		}
		cnt++;
		if(cnt==8){
			cout<<endl;
			cnt=0;
		}
	}
	cout<<endl;
}

// void make_inner_product(double base1[][], double base2[][], double result[][]) {
// 	int row = sizeof(base1);
// 	int col = sizeof(base2[0]);
// 	for (int i = 0; i < row; i++) {
// 		for (int j = 0; j < col; j ++) {
// 			for (int k = 0; k < sizeof(base2); k++) {
// 				result[i][j] += base1[i][k] * base2[j][i];
// 			}
// 		}
// 	}
// }

int main(int argc, const char * argv[])
{
	
	double W_xx[dim+1][dim+1]={0.0}; // Weight Matrix
	double X_in[dim+1]={0.0};        // Input Data
	double X_out[dim+1]={0.0};       // Associated Result
	
	// =====================================================================================================
	cout<<"=================="<<endl;
	cout<<"    Exercise 1"<<endl;
	cout<<"=================="<<endl;
	// Calculate a weight matrix W_xx using all the train data, and get an associated data using the weight matrix W_xx.
	// =====================================================================================================
	
	// ==========================================
	// Learning Phase
	// ==========================================
	// Write a weight matrix W_xx calculation here...
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i == j) {
				W_xx[i][j] = 0.0;
			} else {
				W_xx[i][j] = X[0][i] * X[0][j];
			}
		}
	}

	// ==========================================
	// Association Phase
	// ==========================================
	// Now, you have a trained weight W_xx that can associate A, B, C, D, and E.
	// From the following, "A" is considered.
	cout << "Associate 'A':" << endl;
	// Set input data
	for (int i=0;i<dim;i++){
		X_in[i] = (double)noiseX[0][i]; // noiseX[0][i]: A, noiseX[1][i]: B, noiseX[2][i]: C, noiseX[3][i]: D, noiseX[4][i]: E
	}
	cout<<"X_in (A with noise): "<<endl;
	drawResult(X_in);
	// You may see this result.
	// ■□■□■□□□
	// □■□■■■□□
	// ■■□□□■■□
	// ■■■□□■■□
	// ■□■□■■■□
	// ■■■■□■■□
	// ■■□□□■■□
	// □■□□□□■□
	
	// Write Association Process (W_xx * X_in) here...
	// internal_state = W_xx * X_in, then X_out = \phi(internal_state)
	for (int i = 0; i < dim; i++) {
		for (int k = 0; k < dim; k++) {
			X_out[i] += W_xx[i][k] * X_in[k];
		}
	}

	// Show Results by ■ and □
	cout<<"Associated Result X_out (A without noise): "<<endl;
	drawResult(X_out);
	// If association is succeed, you get the following result (A).
	// □□■■■□□□
	// □■■■■■□□
	// ■■□□□■■□
	// ■■□□□■■□
	// ■■■■■■■□
	// ■■■■■■■□
	// ■■□□□■■□
	// ■■□□□■■□
	
	
	
	
	
	// ======================================================================================================
	cout<<"=================="<<endl;
	cout<<"    Exercise 2"<<endl;
	cout<<"=================="<<endl;
	// Associate a correct "E" from data with high noise using the weight matrix W_xx calculated in Exercise 1.
	// ======================================================================================================
	
	
	// Test Data (E with high noise)
	int High_noiseX[dim+1]={
		1, 1, 1, 1, 1, 1, 1, 1,-1,-1, 1,-1,-1,-1,-1, 1,-1, 1, 1,-1, 1, 1,-1,-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1,-1,-1, 1, 1, 1,-1,-1,-1,-1, 1, 1,-1, 1,-1, 1,-1, 1, 1, 1,-1, 1, 1,-1,-1, 1, 1, 1,-1,-1,-1  // E with high noise
	};
	
	// Set input data
	for (int i=0;i<dim;i++){
		X_in[i] = (double)High_noiseX[i];
	}
	
	cout<<"X_in (E with high noise): "<<endl;
	drawResult(X_in);
	// You may see this result.
	// ■■■■■■■■
	// □□■□□□□■
	// □■■□■■□□
	// □■■■□□□□
	// ■■□□■■■□
	// □□□■■□■□
	// ■□■■■□■■
	// □□■■■□□□
	
	
	// Write Association Process here...
	// internal_state = W_xx * X_in, then X_out = \phi(internal_state)
	// If you conduct an association process once, you may get an incorrect "E".
	// How to associate a correct "E"?
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i == j) {
				W_xx[i][j] = 0.0;
			} else {
				W_xx[i][j] = X[4][i] * X[4][j];
			}
		}
	}

	for (int i = 0; i < dim; i++) {
		for (int k = 0; k < dim; k++) {
			X_out[i] += W_xx[i][k] * X_in[k];
		}
	}
	cout<<"Associated Result X_out (E without noise): "<<endl;
	drawResult(X_out);

	for (int i = 0; i < dim; i++) {
		for (int k = 0; k < dim; k++) {
			X_out[i] += W_xx[i][k] * X_out[k];
		}
	}

	// Show Results by ■ and □
	cout<<"Associated Result X_out (E without noise): "<<endl;
	drawResult(X_out);
	// If association is succeed, you get the following result (E).
	// ■■■■■■■■
	// □■■□□□□■
	// □■■□□■□□
	// □■■■■■□□
	// □■■■■■□□
	// □■■□□■□□
	// □■■□□□□■
	// ■■■■■■■■



}