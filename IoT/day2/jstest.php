<script>
    var num1 = '10';
    var num2 = '20';
    var arr1 = [];
    var arr2 = [1,2,3,4,5];
    arr2.push(6);

    var dict1 = {  // JS 구조체, 딕셔너리
        name: 'nockanda',  // 멤버변수
        age: 20
    };

    // var arr[];  - 규칙 위반

    console.log(JSON.stringify(dict1));
    console.log(dict1['name']);
</script>

<?php
    $num1 = '10';
    $num2 = '20';
    echo $num1+$num2;
?>