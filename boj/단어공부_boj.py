import sys

words = input().lower()

words_list = list(set(words))
words_count = []

for i in words_list:
  count = words.count(i)
  words_count.append(count)

if words_count.count(max(words_count)) >= 2:
  print("?")
else:
  print(words_list[(words_count.index(max(words_count)))].upper())