#include <iostream>
#include <iterator>
#include <vector>

#define uint unsigned int

std::vector<uint> heap;

void siftDown(uint i) {
	while (2 * i + 1 < heap.size()) {
		uint left_son_index = 2 * i + 1;
		uint right_son_index = 2 * i + 2;
		uint j = left_son_index;

		if (right_son_index < heap.size() && heap[right_son_index] > heap[left_son_index])
			j = right_son_index;

		// invariant fixed
		if (heap[i] >= heap[j])
			break;

		std::swap(heap[i], heap[j]);
		i = j;
	}
}

void siftUp(uint i) {
	while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
		std::swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

uint extractMax() {
	uint max = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	siftDown(0);
	return max;
}

void insert(uint num_to_insert){
	heap.push_back(num_to_insert);
	siftUp(heap.size() - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int operations_num;
    std::cin >> operations_num;

    std::string cur_operation;
    uint num_to_insert;
    std::vector<uint> out;

    for (int i = 0; i < operations_num; i++) {
        std::cin >> cur_operation;
        if (cur_operation == "ExtractMax") {
			out.push_back(extractMax());
        } else{
            std::cin >> num_to_insert;
            insert(num_to_insert);
        }
    }

    copy(out.begin(), out.end(), std::ostream_iterator<uint>(std::cout, "\n"));
}