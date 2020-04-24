from collections import Counter
from queue import PriorityQueue

non_leaf_node_name = 'None'
codes_dict = {}
p_queue = PriorityQueue()


class MyNode:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def fill_codes(self, deep=0, cur_way=None):
        if cur_way is None:
            cur_way = []

        if self.left:
            cur_way.append('0')
            self.left.fill_codes(deep+1, cur_way)
            cur_way = cur_way[:deep]

        if self.data != non_leaf_node_name:
            joined = "".join(cur_way)
            codes_dict[self.data] = joined

        if self.right:
            cur_way.append('1')
            self.right.fill_codes(deep+1, cur_way)

    def __lt__(self, other):
        return self.data < other.data


def create_non_leaf_node():
    left_priority, left_node = p_queue.get()
    right_priority, right_node = p_queue.get()
    priority_sum = left_priority + right_priority
    node = MyNode(non_leaf_node_name)
    node.left = left_node
    node.right = right_node
    return priority_sum, node
    
def main():
    input_str = input()
    freq_dict = Counter(input_str)
    n = len(freq_dict)

    if n == 1:
        letter, freq = freq_dict.popitem()
        print(f"1 {freq}")
        print(f"{letter}: {0}")
        print('0' * freq)
    else:
        for letter, frequency in freq_dict.items():
            p_queue.put((frequency, MyNode(letter)))
        
        # 2*n - 1 - n - 1 - from lecture
        for _ in range(n-2):
            p_queue.put(create_non_leaf_node())

        _, root = create_non_leaf_node()
        root.fill_codes()
        
        encoded = ''.join(codes_dict[letter] for letter in input_str)

        print(f"{len(freq_dict)} {len(encoded)}")
        for letter, code in codes_dict.items():
            print(f"{letter}: {code}")
        print(encoded)


if __name__ == '__main__':
    main()