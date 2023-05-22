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