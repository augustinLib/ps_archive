import sys

N = int(sys.stdin.readline())

container = list(map(int, sys.stdin.readline().split()))
# 집합으로 변경
container = set(container)

# 입력 시 더 빠르게
M = int(sys.stdin.readline())
# 여러개 입력받기
finded = list(map(int, sys.stdin.readline().split()))
for i in range(0, M):
	if finded[i] in container:
		print(1)
	elif finded[i] not in container:
		print(0)
