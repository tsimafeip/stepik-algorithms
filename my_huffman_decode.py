def main():
    k, _ = map(int, input().split())
    code_letter_dict = dict(input().split(': ')[::-1] for _ in range(k))
    encoded_str = input()

    decoded_str = ''
    cur_sequence = ''
    for symbol in encoded_str:
        cur_sequence += symbol
        if cur_sequence in code_letter_dict:
            decoded_str += code_letter_dict[cur_sequence]
            cur_sequence = ''
    print(decoded_str)

if __name__ == '__main__':
    main()
