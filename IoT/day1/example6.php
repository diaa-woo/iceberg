<?php
	if($_GET['num'] == 0) {
		echo "로그인이 이미 완료되었습니다!";	
	} 
	else if($_GET['num'] == 1){
		echo "
			아이디: <input type=text><br>
			패스워드: <input type=text><br>
			<input type=button value=로그인><br>
		";
	}
	else if($_GET['num'] == 2){
		echo "
			아이디: <input type=text><br>
			패스워드: <input type=text><br>
			학번: <input type=text><br>
			<input type=button value=로그인><br>
		";
	}
?>