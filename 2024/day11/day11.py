import time
from collections import defaultdict

def blink(st, iterations=25):

    stones = defaultdict(int)

    for i in st:
        stones[i] += 1

    for i in range(1,iterations+1):
        stones_copy = defaultdict(int)
        for stone in stones:
            if stone == '0':
                stones_copy['1'] += stones[stone]
            elif len(stone) % 2 == 0:
                middle = int(len(stone) / 2)
                left = stone[:middle]
                stones_copy[str(int(left))] += stones[stone]
                right = stone[middle:]
                stones_copy[str(int(right))] += stones[stone]
            else:
                stones_copy[str(int(stone)*2024)] += stones[stone]
        stones = stones_copy

    ans = 0
    for stone in stones:
        ans += stones[stone]

    return ans

if __name__ == "__main__":
    _in = open("input.txt").read().split('\n')[0].split(' ')
    ex = open("example.txt").read().split('\n')[0].split(' ')


    e1 = blink(ex, 25)
    assert e1 == 55312, f"should be 55312, but is {e1}"

    start = time.time()
    p1 = blink(_in, 25)
    print("part 1: ", p1)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')

    start = time.time()
    p2 = blink(_in, 75)
    print("part 2: ", p2)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')
