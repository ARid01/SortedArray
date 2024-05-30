//SortedArray.cpp - Andrew Ridgely 5/28/24
//Description: Array that automatically keeps items sorted using binary search operations.

#include <iostream>
#include <vector>

template <typename T> class SortedArray {
private:
	std::vector<T> arr;

	//O(logn) - Works
	int binarySearch(std::vector<T> v, T target) {
		int l = 0;
		int r = v.size() - 1;
		int m, e;

		while (l <= r) {
			m = l + (r - l) / 2;
			e = v[m];

			if (e == target) return m;
			else if (e < target) l = m + 1;
			else r = m - 1;
		}

		return -1;
	}

	//O(logn) - Works
	int binarySearch_LeftInsert(std::vector<T> v, T value) {
		int l = 0;
		int r = v.size() - 1;
		int m;

		while (l <= r) {
			m = l + (r - l) / 2;
			if (v[m] >= value)
				r = m - 1;
			else l = m + 1;
		}
		return l;
	}

public:
	//O(1) - Works
	SortedArray() {
		arr = std::vector<T>();
	}

	//O(n^2) - input loop * insertion - Works
	SortedArray(std::vector<T> input) {
		arr = std::vector<T>();
		for (T& i : input) {
			insert(i);
		}
	}

	//O(n) - Works
	SortedArray(SortedArray& copy) {
		arr = std::vector<T>(copy.getArray());
	}

	//O(n) (from vector insert) - Works
	void insert(T value) {
		arr.insert(arr.begin() + binarySearch_LeftInsert(arr, value), value);
	}

	//O(logn) - Works - Returns index or -1 if not found
	int find(T value) {
		return binarySearch(arr, value);
	}

	//O(n) (from vector erase) - Works
	bool remove(T value) {
		int ind = binarySearch(arr, value);
		if (ind < 0 || ind >= arr.size()) return false;
		else {
			arr.erase(arr.begin() + ind);
			return true;
		}
	}

	//O(1) - Works
	T valueAt(int index) {
		if (index < 0 || index >= arr.size()) return NULL;
		else return arr[index];
	}

	//O(1) - Works
	std::vector<T> getArray() {
		return arr;
	}

	//O(n) - Works
	void printArray() {
		for (int i = 0; i < arr.size(); i++) {
			if (i < arr.size() - 1) {
				std::cout << arr[i] << ", ";
			}
			else std::cout << arr[i] << std::endl;
		}
	}

	//O(1) - Works
	int size() {
		return arr.size();
	}

	//O(1) - Works
	bool empty() {
		return arr.empty();
	}

	//O(n) - Works
	static bool isSorted(std::vector<T>& v) {
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] > v[i + 1]) return false;
		}
		return true;
	}

	//O(1) - Works
	T& operator[] (int i) { return arr[i]; }
};
