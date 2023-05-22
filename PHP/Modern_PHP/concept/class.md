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