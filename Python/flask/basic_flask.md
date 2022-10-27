# basic Flask

Flask는 웹 애플리케이션 개발을 위한 파이썬 프레임워크다.

뭐 사실 웹 개발과 관련된 프레임워크는 Django도 있지만, 너무 무겁기도 하고 주변에서 악평이 자자하길래..ㅋㅋ 임베디드 개발자인 내가 바로 만들기 쉬운 라이트 프레임워크 flask를 사용하게 되었다.

## 마이크로 웹 프레임워크 
Flask는 "micro" 프레임워크라는 점을 늘 강조해왔다. 즉, 최소한의 구성 요소와 요구 사항을 제공하기 때문에 시작하기 쉽고 필요에 따라 유연하게 사용하다. 하지만 그렇다해서 완전한 기능을 갖출 앱을 만들기에 제약을 가진다는 의미도 아니다.(실제로 지난 해커톤에선 파이썬 백엔더는 flask만 가지고 훌륭한 백엔드를 만들었던걸 본 적 있다.) 이 부분은 오히려 쉽게 확장할 수 있도록 설계되어 있기 때문에 개발하는 입장에서는 필요한 도구 및 라이브러리를 자유롭게 사용이 가능하다는 특장점이 있다. 

## Start!
만드는 방법은 다음과 같다.

### 가상환경 설치

```sh
python -m venv venv
```

다음 명령어를 사용하여 파이썬 가상환경을 만든다. 문장 맨 마지막의 `venv`는 다른 이름으로 교체할 수 있다.

### flask 설치
플라스크 설치는 정말 간단하다. pip 딱 한줄만 쓰면 다 설치해줌 ㄹㅇ

```sh
venv\Scripts\activate  # windows 기준
pip install flask
```

```sh
venv/bin/activate  # linux 기준
pip install flask
```

### 간단한 코드
프로젝트 폴더 안에 app.py를 만들고 아래와 같은 코드를 넣은 뒤 돌려준다.

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
    return 'Hello, World!'

if __name__ == '__main__':
    app.run(debug=True)
```

`app.run()` 괄호 안에 `debug=True`라고 명시해두면 해당 파일의 코드가 수정될 때마다 Flask가 변경된 것을 인식하고 다시 시작한다. 물론 프로덕션 환경에서는 해당 옵션을 제외하자.

어쨋든 이제 이 코드를 실행하면 http://127.0.0.1:5000에 돌아가고 있다는 명령어를 볼 수 있다! Flask는 항상 5000번 포트만 사용하니 이를 유념해두자

## Route
웹 브라우저에서 URL을 방문하면 서버에 요청을 보내고, 서버는 그 요청을 처리해서 브라우저에 응답을 반환한다. 그 반환된 결과를 HTML 문서로 보내주면 그 웹 페이지를 브라우저가 띄워줄 수 있다.

다만 react나 vue를 사용할 경우 프레임워크에서 라우트를 따로 분리해주기 때문에 잘 쓰이진 않을거 같다. 정말 간단한 HTML 문서만 올려주는 용도?

### 그래서 코드를 돌려볼까요

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
@app.route('/home')
def home():
    return 'Hello, World!'

@app.route('/user')
def user():
    return 'Hello, User!'
    
if __name__ == '__main__':
    app.run(debug=True)
```

이 코드를 돌렸을 시 http://127.0.0.1:5000 주소 뒤에 `'/'`을 붙이던, `/home`을 붙이던 똑같은 Hello, World!를 호출해준다.

## 동적 URL 다루기 
위에서는 route() decorator를 사용해서 고정된 URL을 뷰 함수에 바인딩하는 방법을 알아봤는데, 경우에 따라 변경되는 동적 URL을 사용하려면 어케 해얗 라까?

### `<variable_name>`
Flask에서는 뷰 함수에 바인딩 할 URL을 지정할 때 이를 명시하는게 가능하다. 그러면 이 변수는 뷰 함수에 인수 형태로 전달할 수 있다.

### 코드 ㄱㄱ

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
@app.route('/home')
def home():
    return 'Hello, World!'

@app.route('/user/<user_name>/<int:user_id>')
def user(user_name, user_id):
    return f'Hello, {user_name}({user_id})!'
    
if __name__ == '__main__':
    app.run(debug=True)
```

반환되는 값으로 f-string 포맷을 활용하여 문자열에 변수를 넣고 h1 태그를 적용할 수 있다.

이렇게 하면 `/user/diadntjr/1001`이라 치면 *Hello, diadntjr(1001)*라고 깔끔하게 출력될 것이다.

그리고 URL은 문자열이기 때문에 `<converter: variable_name>` 구문을 사용해서 URL에서 받은 변수 타입을 변형할 수 있다. converter로 사용할 수 있는 옵션은 다음과 같다.

- `string`(default): slash가 포함되지 않은 문자열
- `int`
- `float`
- `path`: `string`과 동일하지만 slash를 포함함
- `uuid`: UUID 형식
