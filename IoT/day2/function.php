<?php
    myfunction();  // 콜
    myfunction2(20);  // 매개변수 전달
    $value = myfunction3(20);  // return int
    $value2 = myfunction(10,20);  //return String

    echo $value."<BR>";
    echo $value2."<BR>";

    $add = add(10,20);
    echo "10 + 20 = ".$add;

    function myfunction() {
        echo "호출되었습니다.<BR>";
    }

    function myfunction2($num) {
        echo $num."입니다<BR>";
    }

    function myfunction3($num) {
        $num--;
        return $num;
    }

    function myfunction4($num1, $num2) {
        return $num1.$num2;
    }

    function add($num1, $num2) {
        return $num1 + $num2;
    }

?>