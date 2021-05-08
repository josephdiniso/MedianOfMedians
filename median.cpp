#include <iostream>
#include <vector>
#include <math.h>

#include "median.hpp"

#define LOG(x) std::cout << x << std::endl;

//TODO: Remove vector from all method calls
int Median::partition5(std::vector<int> &list, int left, int right) {
	int i = left + 1;
	while (i <= right) {
		int j = i;
		while (j > left && list[j - 1] > list[j]) {
			std::swap(list[j - 1], list[j]);
			j--;
		}
		i++;
	}
	return floor((left + right) / 2);
}

int Median::pivot(std::vector<int> &list, int left, int right) {
	if ((right - left) < 5) {
		return partition5(list, left, right);
	}
	for (int i = left; i <= right; i += 5) {
		int sub_right = i + 4;
		if (sub_right > right) {
			sub_right = right;
		}
		int median5 = partition5(list, i, sub_right);
		std::swap(list[median5], list[left + floor((i - left) / 5)]);
	}
	int mid = (right - left) / 10 + left + 1;
	return select(list, left, int(left + floor((right - left) / 5)), mid);
}


int Median::partition(std::vector<int> &list, int left, int right, int pivot_index, int n) {
	int pivot_value = list[pivot_index];
	std::swap(list[pivot_index], list[right]);
	int store_index = left;
	for (int i = left; i <= right - 1; ++i) {
		if (list[i] < pivot_value) {
			std::swap(list[store_index], list[i]);
			store_index++;
		}
	}
	int store_index_eq = store_index;
	for (int i = store_index; i <= right - 1; ++i) {
		if (list[i] == pivot_value) {
			std::swap(list[store_index_eq], list[i]);
			store_index_eq++;
		}
	}
	std::swap(list[right], list[store_index_eq]);
	if (n < store_index) {
		return store_index;
	}
	if (n <= store_index_eq) {
		return n;
	}
	return store_index_eq;
}

int Median::select(std::vector<int> &list, int left, int right, int n) {
	while (true) {
		if (left == right) {
			return left;
		}
		int pivot_index = pivot(list, left, right);
		pivot_index = partition(list, left, right, pivot_index, n);
		if (n == pivot_index) {
			return n;
		} else if (n < pivot_index) {
			right = pivot_index - 1;
		} else {
			left = pivot_index + 1;
		}
	}
}

float Median::calc_median(std::vector<int> &list) {
	if (list.size() % 2 == 0) {
		return (float(list[select(list, 0, list.size() - 1, list.size() / 2)]) +
		        float(list[select(list, 0, list.size() - 1, list.size() / 2) - 1])) / 2;
	}
	return list[select(list, 0, list.size() - 1, list.size() / 2)];
}