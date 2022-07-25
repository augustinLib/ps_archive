import sys

class Deque:
    def __init__(self):
        self.container = []
        
    def push_front(self, x):
        self.container.insert(0, x)

    def push_back(self, x):
        self.container.append(x)

    def pop_front(self):
        if (len(self.container) == 0):
            print(-1)
        else:
            temp = self.container[0]
            del self.container[0]
            print(temp)

    def pop_back(self):
        if (len(self.container) == 0):
            print(-1)
        else:
            temp = self.container[-1]
            del self.container[-1]
            print(temp)


    def size(self):
        print(len(self.container))
        
    def front(self):
        if (len(self.container) == 0):
            print(-1)
        else:
            print(self.container[0])

    def back(self):
        if (len(self.container) == 0):
            print(-1)
        else:
            print(self.container[-1])

    def empty(self):
        if (len(self.container) == 0):
            print(1)
        else:
            print(0)
            

deque = Deque()
N = int(input())

for i in range(N):
    # 제한시간으로 인해 input() 대신 sys.stdin.readline() 사용
    # "\n"이 포함되기때문에 split으로 잘라준 이후 사용
    command = (sys.stdin.readline().split("\n"))[0]
    if (command.split(" ")[0] == "push_front"):
        deque.push_front(command.split(" ")[1])
    elif (command.split(" ")[0] == "push_back"):
        deque.push_back(command.split(" ")[1])
    elif (command.split(" ")[0] == "front"):
        deque.front()
    elif (command.split(" ")[0] == "back"):
        deque.back()
    elif (command.split(" ")[0] == "size"):
        deque.size()
    elif (command.split(" ")[0] == "pop_front"):
        deque.pop_front()
    elif (command.split(" ")[0] == "pop_back"):
        deque.pop_back()
    elif (command.split(" ")[0] == "empty"):
        deque.empty()


    else:
        print("error")