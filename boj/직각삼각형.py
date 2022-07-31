import sys

while(True):
    input_list = list(map(int, sys.stdin.readline().split()))
    sum_of_all = sum(input_list)
    if sum_of_all == 0:
        break
    input_list.sort()

    if (input_list[-1]**2 == input_list[0]**2 + input_list[1]**2):
        print("right")
    else:
        print("wrong")




