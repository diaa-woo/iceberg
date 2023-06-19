def dfs(computers, visited, node):
    visited[node] = True
    for i in range(len(computers)):
        if computers[node][i] == 1 and not visited[i]:
            dfs(computers, visited, i)

def solution(n, computers):
    answer = 0
    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            dfs(computers, visited, i)
            answer += 1
    return answer
        
n = int(input())
computers = []

for _ in range(n):
    row = list(map(int, input().split()))
    computers.append(row)
answer = solution(n, computers)

print(answer)