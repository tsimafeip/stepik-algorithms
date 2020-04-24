#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

class Node {
public:
    int cost, weight;

    double get_ratio() const {
        return (double) cost / weight;
    }

    bool operator<(const Node &another_node) {
		// division could be replaced by mutplication. it speeds up the algorithm.
        return get_ratio() > another_node.get_ratio();
    }
};

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	
    int things_amount, available_space;
    std::cin >> things_amount >> available_space;

    std::vector<Node> things(things_amount);
    for (std::size_t i = 0; i < things_amount; i++) {
        std::cin >> things[i].cost >> things[i].weight;
    }

    // sorting things by the profit ratio. 
	// could be replaced by min-heap usage.
    std::sort(things.begin(), things.end());

    double max_cost = 0;
    for (auto thing : things) {
        if (available_space >= thing.weight) {
            max_cost += thing.cost;
            available_space -= thing.weight;
        } else {
            max_cost += available_space * thing.get_ratio();
            break;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << max_cost << std::endl;
}