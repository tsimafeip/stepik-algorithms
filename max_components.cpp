#include <iostream>
#include <vector>

#define uint unsigned int

int main() {
    uint num;
    std::cin >> num;

	uint component = 1;
	std::vector<uint> components;
	while (component < num - component) {
		components.push_back(component);
		num -= component++;
	}

	if (num)
		components.push_back(num);

    std::cout << components.size() << std::endl;
    for (uint component: components) 
        std::cout << component << " ";
}