import os

# Workiong Directory 확인
print(os.getcwd())

path = os.getcwd() + '\\data.txt'
fp = open(path)
str = fp.read()
print(str, end='')
fp.close()