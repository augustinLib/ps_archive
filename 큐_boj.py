import sys

class Queue:
    def __init__(self):
        self.container = []
        
    def push(self, x):
        self.container.append(x)

    def pop(self):
        if (len(self.container) == 0):
            print(-1)
        else:
            temp = self.container[0]
            del self.container[0]
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
            

stack = Queue()
N = int(input())

for i in range(N):
    # 제한시간으로 인해 input() 대신 sys.stdin.readline() 사용
    # "\n"이 포함되기때문에 split으로 잘라준 이후 사용
    command = (sys.stdin.readline().split("\n"))[0]
    if (command.split(" ")[0] == "push"):
        stack.push(command.split(" ")[1])
        
    elif (command.split(" ")[0] == "front"):
        stack.front()
    elif (command.split(" ")[0] == "back"):
        stack.back()
    elif (command.split(" ")[0] == "size"):
        stack.size()
    elif (command.split(" ")[0] == "pop"):
        stack.pop()
    elif (command.split(" ")[0] == "empty"):
        stack.empty()
    else:
        print("error")