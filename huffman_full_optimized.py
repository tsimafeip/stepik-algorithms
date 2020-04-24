from collections import Counter, namedtuple
import heapq


class MyLeaf(namedtuple("MyLeaf", ["data"])):
    def fill_codes(self, codes_dict, cur_way):
        codes_dict[self.data] = cur_way or "0"


class MyNode(namedtuple("MyNode", ["left", "right"])):
    def fill_codes(self, codes_dict, cur_way):
        self.left.fill_codes(codes_dict, cur_way + '0')
        self.right.fill_codes(codes_dict, cur_way + '1')


def huffman_encode(input_str):
    p_queue = []
    for letter, frequency in Counter(input_str).items():
        p_queue.append((frequency, len(p_queue), MyLeaf(letter)))

    heapq.heapify(p_queue)

    count = len(p_queue)
    while len(p_queue) > 1:
        left_priority, _count, left_node = heapq.heappop(p_queue)
        right_priority, _count, right_node = heapq.heappop(p_queue)
        count += 1
        heapq.heappush(p_queue, (left_priority + right_priority, count, MyNode(left_node, right_node)))

    codes_dict = {}
    if p_queue:
        _freq, _count, root = heapq.heappop(p_queue)
        root.fill_codes(codes_dict, "")
    return codes_dict


def huffman_decode(encoded_str, codes_dict):
    decoded_str = ''
    if encoded_str and codes_dict:
        cur_sequence = ''
        for symbol in encoded_str:
            cur_sequence += symbol
            if cur_sequence in codes_dict:
                decoded_str += codes_dict[cur_sequence]
                cur_sequence = ''

    return decoded_str


def main_decode():
    k, _ = map(int, input().split())
    code_letter_dict = dict(input().split(': ')[::-1] for _ in range(k))
    encoded_str = input()

    decoded = huffman_decode(encoded_str, code_letter_dict)
    print(decoded)


def main_encode():
    input_str = input()

    codes = huffman_encode(input_str)

    encoded = ''.join(codes[letter] for letter in input_str)
    print(f"{len(codes)} {len(encoded)}")
    for letter, code in codes.items():
        print(f"{letter}: {code}")
    print(encoded)


def test(n_iter=1000):
    import random
    import string

    for _ in range(n_iter):
        length = random.randint(0, 32)
        s = "".join(random.choice(string.ascii_letters) for _ in range(length))
        code = huffman_encode(s)
        reversed_code = dict((code, letter) for letter, code in code.items())
        encoded = "".join(code[ch] for ch in s)
        decoded = huffman_decode(encoded, reversed_code)
        assert decoded == s


if __name__ == '__main__':
    test()
