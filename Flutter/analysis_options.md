# analysis_options

## 뭐냐 앤
<p>일종의 룰, 하나의 프로젝트를 서로 공유하면서 null safety 등으로 사용되지 않는 위젯들을 차단시켜주는 커스텀 규칙이다. 이를 활용해 유연한 팀 작업을 이뤄낼 수 있다.</p>

```yaml
linter:  # 얘가 메인
  rules:
    prefer_const_constructors: false  #이 업데이트가 생겨진 후 몇몇의 위젯들에 const를 붙이라는 경고가 발생하는데, 이 규칙은 그딴걸 무시하게 해준다.
```