# Automata

## Automata 란?

<p> 오토마톤(Automaton)의 복수형이며, 추상적인 연산 장치 또는 '기계'(machine)이다. 오토마톤은 연산 능력을 갖춘 것이지만, 반드시 <b>물리적인 하드웨어를 필요로 하지는 않는다.</b> 기계라고 해서 꼭 우리가 보고 만질 수 있는 물리적인 것이여야 하는 것은 아니라는 뜻이다. 따라서 오토마타는 <b>추상적인 연산 장치(오토마톤)가 계산할 수 있는 것과 그렇지 않는 것에 대한 이론이다.</b></p>
 
<p> 이 이론이 생긴 계기는 계산 이론(Theory of Computation), 다양한 기계장치가 할 수 있는 것과 할 수 없는 것을 찾는 것에서 파생되었다.(또는 얼마나 효율적으로 풀 수 있느지에 대해서도) Computability라는 용어는 연산장치가 할 수 있는 것을 의미하고, Complexity(복잡성) 개념은 연산 장치가 할 수 있는 일이라면, 얼마나 효율적으로 할 수 있는지를 의미한다.</p>
 
<p> 오토마타 이론은 엘런 튜링의 영향이 매우 컸다. 그는 이 이론이 나오기 전부터 튜링 머신이라는 추상 기계를 연구했었다.</p>


## 형식 언어의 요소

<p> 형식 언어에는 정규 언어(regular language)와 문맥 자유 언어(context free language)등이 있다. 우리는 이를 알아보기 위해서 언어(language)를 이루는 요소들에 대해 정리할 필요가 있다.

### 개념 및 단어 정의

<p> - <b>심볼(Symbol):</b> 한글에서 자음과 모음, 10진수에선 0~9 숫자를 생각하면 된다. 언어를 이루는 가장 기본적인 요소이다.

<p> - <b>(*)알파벳(Alphabet):</b> 알파벳은 심볼의 집합이다. 단, <b>비어있지 않고 유한해야 한다.</b> 영어의 알파벳도 a라는 심볼부터 z라는 심볼까지 유한하며, 비어있지 않은 집합으로 구성되어 있다. 한글과 10진수도 마찬가지이다. 알파벳은 어떤 유한 오토마타를 구성하는 필수 요소 중 하나이다.</p>

<p> 오토마타 이론에서는, 알파벳을 표현할 때 시그마(Sigma) 심볼을 사용한다.</p>

<p> 즉, 영어 소문자 알파벳을 표현하기 위해서는 이런 식으로 표기한다.</p>
<p></p>

$\displaystyle\sum_{}^{}={(a,b,c,d, ... , z)}$

<p> 여기서 a,b,c 하나하나가 <b>심볼</b>이라면, a부터 z까지 모아놓은 <b>집합</b>이 곧 영어의 <b>알파벳</b>이 된다.</p>

<p>그리고 이진수 알파벳을 표현하기 위해서는 이런 식으로 표기한다.</p>
<p></p>

$\displaystyle\sum_{}^{}={(0,1)}$

<p> - <b> 문자열(Strings):</b> 문자열은 특정 알파벳으로부터 선택하여 열거한 <b>유한한</b> 심볼들이다.
<p></p>

$\displaystyle\sum_{}^{}={(a,b,c,d, ... , z)} : abcd, galaxy, helloworld$

<p> abcd, galaxy, helloworld, 이 세 문자열은 오직 영어 소문자 알파벳으로부터 선택한, 유한한 알파벳들의 연속이다.</p>
<p></p>

$\displaystyle\sum_{}^{}={(0,1)} : 001, 1110$

<p> 위의 두 문자열, 001, 1110과 마찬가지로 오직 0과 1로만 이루어진 유한한 알파벳들의 연속이다.</p>
<p> 또한, 문자열은 비어있을 수 있다. 이렇게 빈 문자열은 <b>앱실롱(epsilon)</b>으로 표기한다.(마치 공역 같은)</p>

> $\epsilon : epsilon$ (비어있는 문자열)

<p> 문자열은, 시그마의 제곱수(Powers of an alphabet)와 밀접한 관련이 있다.</p>

$\displaystyle\sum_{}^{}k{}$

<p> 시그마의 k제곱은, 그 알파벳에서 가능한, 길이가 k인 문자열들의 집합이다. 이 알파벳으로 예시를 들자면,</p>

$\displaystyle\sum_{}^{}1={0,1}$

<p> 0과 1이라는 심볼로 만들 수 있는, 길이가 1인 문자열은 0과 1밖에 없다.</p>

$\displaystyle\sum_{}^{}2={00, 01, 10, 11}$

<p> 마찬가지로 0과 1로 만들 수 있는, 길이가 2인 문자열은 4가지이다. </p>

$\displaystyle\sum_{}^{}0={\epsilon}$

<p> 참고로, 시그마의 0제곱은 빈 문자열인 앱실롱(epsilon)이다. 추가로, <b>클레이니 스타(Kleene Star)</b>에 대해 알아보자. 다음 단계인 언어를 이해하기 위해 필요한 개념이다. 클레이니 스타를 풀어내자면, <b>특정 알파벳으로 만들 수 있는 모든 문자열의 집합이다.</b>심볼이 a,b 두가지로 이루어진 예제를 보자면,</p>

$\displaystyle\sum_{}^{}={a,b}$

<p> 클레이니 스타를 편의상 <b>시그마 스타</b>라고 부르기도 한다. 위의 알파벳의 시그마 스타는 다음과 같다.</p>

$\sum_{}^{*}={\{a,b\}}^*=\{\epsilon,a,b,aa,ab,ba,bb,aaa,aab,aba,abb,baa,bab,bba,bbb,...\}$

<p>이렇게, a와 b로 만들 수 있는 모든 문자열 조합은 무한하다. 그 모든 문자열의 집합을 시그마 스타라고 부른다. 또한, <b>클레이니 플러스</b>라는 개념도 있다. 그러나 단순히 클레이니 스타에서 빈 문자열(epsilon)을 제외한 집합이다.</p>

$\sum_{}^{*}+={\{a,b\}}^+=\{a,b,aa,ab,ba,bb,aaa,aab,aba,abb,baa,bab,bba,bbb,...\}$

<p> 시그마 스타의 정의는 다음과 같다.</p>

$\displaystyle\sum_{}^{}*= \displaystyle\sum_{}^{}0 \cup \displaystyle\sum_{}^{}1 \cup \displaystyle\sum_{}^{}2 \cup \displaystyle\sum_{}^{}3 \cup ... = \displaystyle\cup_{i=0}^{\infty} \displaystyle\sum_{}^{}i$

<p> 이를 간단히 첨언하면, 주어진 심볼로 만들 수 있는, 길이가 0인 모든 문자열부터 길이가 무한대인 모든 문자열까지 포함하는 집합이다.</p>

<p> - <b>언어(language):</b> 특정 알파벳의 시그마 스타의 부분집합인 문자열의 집합만이 그 알파벳의 언어가 될 수 있다. 한마디로, 언어는 특정 알파벳의 시그마 스타의 부분집합이다.</p>

$L\;is\;a\;language\;over\;alphabet \displaystyle\sum_{}^{},\;only\;if\;L \subseteq \sum_{}^{}*$

<p> 비어있는 언어가 있을시, 다음과 같이 표기한다</p>

$L = \varnothing$

<p> 단, L이 앱실롱으로만 이루어진 언어라고 해도, 비어있는 언어는 아니다.</p>

$if \, L_1 = \{\epsilon\}\; and\;L_2 = \varnothing\;then\,L_1 \neq L_2 $

### 문자열의 연산

<p> 문자열에는, 연산의 개념이 포함되어 있다. 먼저, 문자열의 길이는 다음과 같이 나타낸다.</p>

$$ \vert abcd \vert$$

<p> 이렇듯 abcd라는 문자열의 길이는 저렇게 표기한다. 참고로 epsilon은 빈 문자열을 뜻하므로,<p>

$ \vert \epsilon \vert = 0$

<p> 두 개의 문자열을 합하는(concatenate) 연산도 가능하다. 두 문자열 사이에 하나를 붙이거나, 두 문자열을 연속으로 적어서 표기한다.(일반 사칙연산과 동일하다.)</p>

$Let\;a = hello,\;b = world, \; then \; ab = a\cdot b = helloworld$

<p> 참고로, 어떠한 문자열이든, 앞뒤로 빈 문자열을 포함하고 있다고 말할 수 있다. 즉, 위의 문자열 a에서,<p>

$hello = \epsilon hello = hello\epsilon = \epsilon hello \epsilon$

<p> 4가지 문자열은 모두 같다고 취급한다.</p>

<p> 문자열에 대해 알아둬야 할 개념이 있다. </p>
<ul>
    <li>prefix: 접두사</li>
    <li>suffix: 접미사</li>
    <li>substring: 특정 문자열의 일부분</li>
    <li>reversal: 뒤집은 문장</li>
    <li>palindrome: 문자열을 reversal 해도 같은 문장(다른 말로 회문이라고도 함)</li>
</ul>
<p> 예시로, 문자열 xyz가 있다고 할 때, z=xy를 만족하면 x는 z의 접두사가 되는 거고, y는 접미사가 되는 거다. 그리고 x,y 모두 z의 substring이 된다.</p>

### 언어(Language)의 연산

<p>언어는 집합의 개념과 동일하다.</p>

<p><b>Union: </b>합집합의 개념과 유사하다.</p>

$ L_1 \cup L_2 = \{u\;\vert\;u\in L_1\;or\;u\in L_2\}$ 

<p><b>Intersection: </b>교집합의 개념과 유사하다.</p>

$ L_1 \cap L_2 = \{u\;\vert\;u\in L_1\;and\;u\in L_2\}$ 

<p><b>Complementation: </b>여집합의 개념과 유사하다.</p>

$ L' = \sum_{}^{*} - \;L = \{u\;\vert\;u\notin L\}$ 

<p><b>Concatenation: </b>두 집합의 원소들을 서로 곱한 값들이다.</p>

$ L_1 \cdot L_2 = \{uv\;\vert\;u\in L_1\;and\;v\in L_2\}$ 

<p><b>Reversal: </b>기존 언어의 모든 문자열을 revalsal 처리한 값이다..</p>

$ L^R = \{u^R\;\vert\;u\in L\}$ 

## 출처
https://blog.naver.com/PostView.naver?blogId=bestowing&logNo=221636494349&parentCategoryNo=&categoryNo=32&viewDate=&isShowPopularPosts=false&from=postView