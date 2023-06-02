# Bash Shell Script Programming

셸 프로그래밍의 간단한 구문 & 문법들

## sh vs bash

sh(Bourne Shell)와 Bash(Bourne Again Shell)는 엄연히 다른 쉘 프로그램이며, sh의 호환성을 유지하면서 추가 기능을 제공한다. 

스크립트가 Bash 확장기능을 사용하였을 때는 sh에는 제대로 동작하지 않기에, 프로그램을 실행하려면 `sh` 대신 `bash`를 적어주어야 한다. 또한 코드 맨 윗줄에 이 줄을 넣어야 한다.

```bash
#!/bin/bash
```

만약 그렇게 하지 않을시 프로그램 실행에 문제가 발생할 수 있다.

## 하위 문서

[For_Loop](concept/for_loop.md)

## 참고

https://www.lesstif.com/lpt/bash-shell-script-programming-26083916.html