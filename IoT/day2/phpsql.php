<?php
    $name = "남승호";
    $age = 25;
    $height = 171.5;
    $gender = "남";

    $conn = mysqli_connect('localhost', 'root', '', 'mydatabase1');
    $query = "Insert into person(name, age, height, gender) values('$name', $age, $height, '$gender')";

    $result = mysqli_query($conn, $query);
    if($result) {
        echo "입력 성공!";
    }
    else {
        echo "입력 실패";
    }

?>