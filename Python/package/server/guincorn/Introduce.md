# guincorn란?

서버 애플리케이션을 만들면서(Flask, Django) 배포를 결정하는 순간부터 이 gunicorn과 uWSGI라는 기술이 보여지기 시작한다. 얘네는 대체 뭔 일을 하는지 알아보자

## WSGI란?
파이썬 애플리케이션(Python Script)이 **웹 서버와 통신하기 위한 인터페이스**이다. 웹서버에서의 요청을 해석하여 파이썬 애플리케이션 쪽으로 던지는 역할을 수행한다.

## Gunicorn란? 쓰는 이유는?
Gunicorn은 Python WSGI로 WEB Server(Nginx)로부터 서버사이드 요청을 받으면 WSGI를 통해 서버 애플리케이션(Flask, Django)로 전달해주는 역할을 수행한다. Django의 runserver 역시도 똑같은 역할을 수행하지만 보안적으로나 성능적으로 검증이 되지 않았기 때문에 production 환경에서는 수행이 불가하다.(개발용으론 유용하다고 한다)(Flask는 그런거 몰라)

## Prodution 환경에 적합한 Gunicorn
WSGI는 멀티 스레드를 만들 수 있기에 Request 요청이 많아지더라도 효율적으로 처리할 수 있다. 이에 Production 환경에 적합하다.

<img src="https://k.kakaocdn.net/dn/c8411Q/btq9e5z4ovy/w0FxZDTT0gXKxk3OtjRe4k/img.png">

WSGI 기술로는 uWSGI 와 Gunicorn이 있는데, 성능적 측면으로는 Gunicorn이 더 좋다고 한다. 짜란~

