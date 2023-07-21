f = open('new.txt', 'r')
lines = f.readlines()
for line in lines:
    print(line)
f.close()