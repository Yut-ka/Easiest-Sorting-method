#pragma once
#include <string>
#include <iostream>
#include <time.h>

int N=0;

std::string Exchange_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = N-1; j > i; j--) {
			if (Array[j - 1] > Array[j]) {
				int temp = Array[j - 1];
				Array[j - 1] = Array[j];
				Array[j] = temp;
				change++;
			}
			compare++;
		}
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare);
}

std::string Insert_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 1; i < N; ++i) {
		int temp = Array[i];
		int j = i - 1;
		while (j >= 0 && temp < Array[j]) {
			compare++;
			Array[j + 1] = Array[j];
			j--;
			change++;
		}
		compare++;
		Array[j + 1] = temp;
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare-1);
}

std::string Selection_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 0; i < N; ++i) {
		int temp = Array[i];
		int k = i;
		for (int j = i + 1; j < N; j++) {
			if (Array[j] < temp) { k = j; temp = Array[j]; }
			compare++;
		}
		if (k != i) change++;
		Array[k] = Array[i];
		Array[i] = temp;
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare );
}

int* Create_Array(int lenght) {
	int* Array = new int[lenght];
	srand(time(0));
	for (int i = 0; i < lenght; i++) {
		Array[i] = int(pow(-1, rand() % 2)) * rand() % 100;
	}
	return Array;
}