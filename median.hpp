//
// Created by jdiniso on 5/7/21.
//

#ifndef MEDIANOFMEDIANS_MEDIAN_HPP
#define MEDIANOFMEDIANS_MEDIAN_HPP

class Median {
private:
	int partition5(std::vector<int> &list, int left, int right);

	int select(std::vector<int> &list, int left, int right, int n);

	int pivot(std::vector<int> &list, int left, int right);

	int partition(std::vector<int> &list, int left, int right, int pivot_index, int n);

public:
	Median() {

	}

	float calc_median(std::vector<int> &list);
};

#endif //MEDIANOFMEDIANS_MEDIAN_HPP

