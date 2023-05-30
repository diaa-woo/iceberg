# class

객체지향 프로그래밍의 클래스와 인스턴스, 정적 메소드에 대해 알아본다.

```PHP
<?php
class Sample {
    //member variable
    private $name;
    private $age;

    // constructor
    public function __construct() {
        $this->name = "hwang";
        $this->age = "19";
    }

    // method
    public function tell() {
        echo "my name is {$this->name} .";
        echo " and my age is {$this->age} .";
    }
    
    // method. return $this
    public function add_age($age) {
        $this->age += $age;
        return $this;
    }

    // static method
    public static function factory() {
        return new Sample();
    }

    public static function factory2() {
        return self::factory();
    }
}

$sample = new Sample();
$sample->tell();

echo "<br />";
Sample::factory()->add_age(3)->tell();
?>
```

## 클래스 선언

**클래스 선언**은 `class` 키워드로 한다. 이후 바로 클래스 이름이 나온다. 클래스 이름은 **PSR(PHP 표준 권고 - PHP Standard Recommendation)-01**에 따라 대문자로 시작하고 단어간의 연결마다 대문자를 사용하는 **StudlyCaps** 형식을 따른다. Pascal Case라고 부르기도 한다.

```php
class Sample
```

## 인스턴스

클래스는 **특정 역할을 하는 타입**을 말한다. 내부적으로 멤버변수와 메소드를 가질 수 있다. 클래스 타입의 변수를 **인스턴스**라고 부른다.

```php
$sample = new Sample();
```

위 예시에서 `$sample`은 인스턴스, `Sample`은 타입을 정의하는 클래스다.

## 멤버 변수

**멤버 변수**는 클래스의 인스턴스가 가지는 속성이다. 클래스 안에서 선언된 변수를 멤버 변수라고 부른다. **프로퍼티(Property)**라고 부르기도 한다.

```php
// member variable
private $name;
private $age;
```

## 메소드

클래스 안에 정의된 함수를 **메소드**라고 부른다

```php
public function tell()
```

함수와 성격이 동일하며, 리턴값 또한 가질 수 있다.

## 생성자

**생성자**는 인스턴스가 처음 생성될 때 자동으로 실행되는 초기화 메소드이다. `__construct`라는 이름의 메소드가 무조건 생성자가 된다. (예약어)

다른 언어에서 생성자는 클래스 이름과 동일한 것과는 차이가 있으니 주의한다. 

## this

`$this`는 인스턴스 자신을 나타내는 키워드다 인스턴스에 속한 메소드나 멤버 변수를 호출할 때 `$this`로 참조한다.

멤버 변수에서 주의해야할 점이 하나 있다. PHP의 변수는 `$` 기호를 붙이지만, 멤버 변수에 **접근**할 때는 `$` 기호를 붙이지 않는다.

```php
$this->name = "hwang"
```

하지만 멤버 변수를 정의할 때는 `$` 기호를 붙여야 한다.

## 참조

**인스턴스의 멤버 변수나 메소드를 참조**할 때는 `->` 키워드를 쓴다. 배열에서 키, 값을 가지고 올 때는 사용하는 `=>`와 비슷하므로 헷갈리면 안된다. 다른 언어에서 `.`으로 가지고 오는 것과 헷갈려서도 안된다.

**내부**

```php
$this->name = "hwang";
```

**외부**

```php
$sample->tell();
```

## return $this
`return $this`는 인스턴스 자신을 리턴한다는 뜻이다. 주로 하나의 객체에 여러가지 메소드를 연쇄적으로 호출하는 메소드 체이닝을 사용할 때 사용한다.

```php
public function add_age($age) {
    $this->age += $age;
    return $this;
}
```

아래처럼 사용할 수 있다.

```php
add_age(3) -> tell()
```

## ""
`""` 문자열이나 히어닥 문법은 내부에서 변수를 치환할 수 있다. 이 때 만약 복합형 변수일 경우 `${변수}` 형식을 이용해서 복합형 변수의 값을 가져올 수 있다. 이 규칙은 클래스와 무관하게 PHP 전체에서 동일하다.

```php
public function tell() {
    echo "my name is {$this->name}.";
    echo " and my age is {$this->age} .";
}
```

## static

멤버 변수나 메소드 이름 앞에 `static`을 붙이면 정적인 속성을 갖는다. 정적인 변수나 메소드는 인스턴스에 속하지 않고 **클래스에 속한다**.

보충 설명을 하자면, 특정 인스턴스에 속하지 않기에 클래스의 객체가 입력 인수로 필요하지 않으며, 클래스의 객체를 생성하지 않고 정적 메서드를 호출할 수 있다.

정적 메서드를 사용하는 대표적인 이유는, 인스턴스를 생성하지 않고 함수를 실행시킬 수 있다는 특징 때문이다. 이런 접근 방식은 클래스의 내부 작업에 대한 캡슐화를 유지하지만 값을 반환하는 데 클래스의 인스턴스가 필요하지 않다는 특징이 있다.

```php
// static method
public static function factory() {
    return new Sample();
}
```

## 젱적 자원 호출

정적인 메소드나 프로퍼티를 호출할 때는 `->`를 사용하지 않고 `::`를 사용한다.

```php
Sample::factory()
```

## 정적 self

정적인 메소드나 프로퍼티를 내부에서 참조하는 것은 `self`를 이요한다. 즉 클래스의 데이터를 이용할 때는 `self`를, 인스턴스의 데이터를 이용할 때는 `$this`를 이용한다. 위에 소개했듯 정적 자원과 인스턴스는 확연히 다르기에, 잘 구분해줘야 한다.

```php
public static function factory2() {
    return self::factory();
}
```

## 코루틴

`static` 이라는 키워드가 메소드가 아닌 일반 함수 안에서 사용되면 함수 자체가 실행이 끝났음에도 상태를 가지고 있는 **코루틴**으로 작동한다. 같은 키워드지만 사용되는 곳에 따라 의미가 다르다.

```php
function func_static() {
    static $cnt = 1;
    echo $cnt;
    $cnt++;
}

func_static();
func_static();
```

결과는 다음과 같다 

```
1
2
```

## 팩토리 디자인 패턴

```php
// static method
public static function factory() 
{
    return new Sample();
}
```

php는 `new Sample() -> add_age()`처럼 생성자 호출 후 곧바로 다른 인스턴스의 메소드를 호출하는 **생성자 메서드 체이닝**이 불가능하다. 꼭 하고 싶다면 `(new Sample())->add_age()` 형식으로 생성자를 `()`로 감싸줘야 한다. 이러한 불편함 때문에 정적 팩토리 메소드를 만드는 경우가 많다.

추가적으로 팩토리 패턴은 생성자를 여러번 호출해도 인스턴스를 하나만 만드는 **싱글톤 패턴**과 결합되어 사용되는 경우도 있다. 아래는 *팩토리 + 싱글톤* 패턴의 예시이다.

```php
private static $sample = null;
public static function factory() {
    if(self::$sample == null) {
        self::$sample = new Sample();
    }

    return self::$sample;
}
```

정적 메소드 `factory()`를 통해 인스턴스를 생성할 경우, 이미 생성된 `Sample` 객체가 있으면 생성된 객체를 반환한다. 객체가 없다면 객체를 생성 후 반환한다.
