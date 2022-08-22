import hashlib


class HashTable:

    def __init__(self):
        # 해시 테이블 0으로 초기화
        self.hash_table = [0 for i in range(8)]


    # 문자열을 정수로 바꿔주어 key가 되게끔 함
    def get_key(self, data):
        # SHA-256 알고리즘 사용
        hash_convert = hashlib.sha256()
        hash_convert.update(data.encode())
        # 16진수로 return
        return int(hash_convert.hexdigest(), 16)


    # 간단하게 나머지를 이용한 해시 함수 구현
    def hash_function(self, key):
        return key % 8

    # 데이터를 해시 테이블에 저장하는 함수
    def save(self, data, value):
        # 키 생성
        key = self.get_key(data)
        # 생성된 키를 해시 함수에 투입
        hash_value = self.hash_function(key)

        # 해시 테이블의 해당 해시 값 부분이 비어있지 않으면(초기화한 값 0이 아니면)
        if self.hash_table[hash_value] != 0:
            for index in range(len(self.hash_table[hash_value])):
                # 한 hash address 안에 리스트가 있고, 그 리스트 안에는
                # key와 value값으로 이루어진 리스트가 또 존재함
                # ([key, value]를 요소로 가지는 연결 리스트)

                # 해시 값이 같을 때, chaining 기법으로 연결 된 연결 리스트를 순회하다가
                # key값도 같은 요소가 있을 시 해당 key의 value값 update
                if self.hash_table[hash_value][index][0] == key:
                    self.hash_table[hash_value][index][1] = value
                    return

            # 해시 값이 같을 때, key값이 같은 요소가 없었으면
            # 해당 해시 값을 인덱스로 하는 해시 테이블에 [key, value]를 요소로 하는 연결 리스트 추가
            self.hash_table[hash_value].append([key, value])

        # 해시 테이블의 해당 해시 값 부분이 비어있으면(초기화한 값 0이면)
        else:
            # [key, value]를 요소로 하는 연결 리스트 추가
            self.hash_table[hash_value] = [[key, value]]

    # 해시 테이블의 데이터 조회하는 함수
    def read(self, data):
        # 키 생성
        key = self.get_key(data)
        # 생성된 키를 해시 함수에 투입
        hash_value = self.hash_function(key)

        # 해시 테이블의 해당 해시 값 부분이 비어있지 않으면(초기화한 값 0이 아니면)
        if self.hash_table[hash_value] != 0:
            for index in range(len(self.hash_table[hash_value])):
                # 해시 테이블의 해당 해시 값 부분에 key값도 같은 요소가 있으면
                # 해당 key값의 value값 return
                if self.hash_table[hash_value][index][0] == key:
                    return self.hash_table[hash_value][index][1]
            return None

        # 해당 해시 값 부분에 데이터가 들어가 있지 않으면
        # 데이터가 없는 것이기 때문에 none값 return
        else:
            return None


