<?php 
    if($_POST['input1'] != "" && $_POST['input2'] != "" ) {
        // 정상처리
        echo $_POST['input1']."<BR>";
        echo $_POST['input2']."<BR>";
    } else {
        // 예외
        echo "<script>";
        echo "alert('에러발생');";
        echo "history.back();";
        echo "</script>";
    }

    
?>