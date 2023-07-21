f = open('new.txt', 'r')
for i in range(11, 20):
    data = "%번째 줄입니다.\n" % i
    f.write(data)
f.close()