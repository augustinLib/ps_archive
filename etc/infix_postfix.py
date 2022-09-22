class ArrayStack:

    def __init__(self):
        self.data = []

    def size(self):
        return len(self.data)

    def isEmpty(self):
        return self.size() == 0

    def push(self, item):
        self.data.append(item)

    def pop(self):
        return self.data.pop()

    def peek(self):
        return self.data[-1]


def splitTokens(exprStr):
    tokens = []
    val = 0
    valProcessing = False
    for c in exprStr:
        if c == ' ':
            continue
        if c in '0123456789':
            val = val * 10 + int(c)
            valProcessing = True
        else:
            if valProcessing:
                tokens.append(val)
                val = 0
            valProcessing = False
            tokens.append(c)
    if valProcessing:
        tokens.append(val)

    return tokens


def infixToPostfix(tokenList):
    prec = {
        '*': 3,
        '/': 3,
        '+': 2,
        '-': 2,
        '(': 1,
    }
    
    opStack = ArrayStack()
    postfixList = []
    
    # 문자열 순회
    for token in tokenList:
        # 피연산자 만날 시 : 바로 출력
        if type(token) is int:
            postfixList.append(token)
            
        # 여는 괄호 만날 시 : stack에 push
        elif token == '(':
            opStack.push(token)
            
        # 닫는 괄호 만날 시 : 여는 괄호가 나올 때까지 pop
        elif token == ')':
            while(True):
                parenPop = opStack.pop()
                
                # 연산자의 경우에는 출력
                if parenPop != '(':
                    postfixList.append(parenPop)
                # 여는 괄호가 pop되면 반복문 종료
                else:
                    break
                
        # 연산자 만날 시
        else:
            # 스택이 비어있을 때는 push (해당 조건 제외시 IndexError)
            if opStack.isEmpty():
                opStack.push(token)
                
            
            # 스택이 비어있지 않을 때
            else:
                # 스택에 있는 연산자가 만난 연산자보다 우선순위가 높거나 같으면 스택 연산자 pop
                # 이후 pop된 연산자는 출력, 만난 연산자는 push
                while(prec[opStack.peek()] >= prec[token]):
                    opPop = opStack.pop()
                    postfixList.append(opPop)
                    
                    if opStack.isEmpty():
                        break
                # 스택에 있는 연산자가 만난 연산자보다 우선순위가 낮으면 push
                opStack.push(token)

                
    # 문자열 순회가 끝난 이후, 스택에 남아있는 연산자 pop
    while not opStack.isEmpty():
        finalPop = opStack.pop()
        postfixList.append(finalPop)


    return postfixList


def postfixEval(tokenList):
    # 스택 초기화
    postStack = ArrayStack()

    # tokenList 순회
    for token in tokenList:
        # 연산자 만날 시
        # 앞의 두 피연산자 pop
        # 이후 계산하여 다시 넣음
        if token == "+":
            second = postStack.pop()
            first = postStack.pop()
            tempResult = first + second
            postStack.push(tempResult)

        elif token == "-":
            second = postStack.pop()
            first = postStack.pop()
            tempResult = first - second
            postStack.push(tempResult)

        elif token == "*":
            second = postStack.pop()
            first = postStack.pop()
            tempResult = first * second
            postStack.push(tempResult)

        elif token == "/":
            second = postStack.pop()
            first = postStack.pop()
            tempResult = int(first / second)
            postStack.push(tempResult)

        # 피연산자 만날 시
        else:
            postStack.push(token)

    # tokenList 순회 이후 stack에 남은 값 반환
    result = postStack.pop()
    return result



def solution(expr):
    tokens = splitTokens(expr)
    postfix = infixToPostfix(tokens)
    val = postfixEval(postfix)
    return val


expr = "3+2*1-5/2"
solution(expr)