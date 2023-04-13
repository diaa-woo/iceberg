<script>
    function mysubmit() {
        var txt1 = document.getElementById('txt1');
        var txt2 = document.getElementById('txt2');
        var myform = document.getElementById('myform');
        
        if(txt1.value != '' && txt2.value != '') {
            myform.submit();
        }
        else {
            if(txt1.value != '') {
                alert('이름을 입력해주세요!');
            }
            else {
                alert('나이를 입력해주세요!');
            }
        }
    }
</script>

<form id=myform method=post action=process.php>
    <input id=txt1 type=text name=input1>
    <input id=txt2 type=text name=input2>
    <input type=button value=확인 onclick=mysubmit()>
</form>