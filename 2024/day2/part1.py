f = open("input.txt")

safe_reports = 0

for line in f.read().split("\n"):
    increment = 0
    nums = list(map(int, line.split(" ")))
    is_safe = True
    increments = []
    for i in range(len(nums)-1):
        _incr = nums[i+1] - nums[i]
        if (increment != 0 and _incr * increment < 0) or _incr == 0:
            is_safe = False
            break
        elif increment == 0:
            increment = _incr
        if _incr not in increments:
            increments.append(abs(_incr))
    if is_safe:
        increments.sort()

        for i in increments:
            if i > 3:
                is_safe = False
                break

        #print(line, increments, is_safe)

        if is_safe:
            safe_reports += 1



print(safe_reports)



