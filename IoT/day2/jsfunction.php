<script>
    window.onload = function() {  // JS가 전부 로드되었을 때 사용할 수 있게 해주어야함!
        var mybtn1 = document.getElementById('mybtn1');
        mybtn1.addEventListener('click', () => {
            console.log("나는 JS함수1이다.");
        });  // Arrow Function - 익명 함수 

        var mybtn2 = document.getElementById('mybtn2');
        mybtn2.addEventListener('click', myfunction);

        var mybtn3 = document.getElementById('mybtn3');
        mybtn3.addEventListener('click', myfunction);

        function myfunction(e) { 
            if(e.srcElement.id == "mybtn2") {
                console.log("btn2");
            }
            else if(e.srcElement.id == "mybtn3"){
                console.log("btn3");
            }
        }

    }

    // 함수를 어떻게 쓰느냐는 결국 케바케

    function myf1() {

    }

</script>

<input id=mybtn1 type=button value=누르기1>
<input id=mybtn2 type=button value=누르기2>
<input id=mybtn3 type=button value=누르기3>

<?php
    myfunction();

    function myfunction() {
        echo "안녕";
    }
?>