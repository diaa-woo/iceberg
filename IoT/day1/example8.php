<table border=1 width=500>
	<tr>
		<td>이름</td>
		<td>나이</td>
	</tr>
	<?php
		$myarray = ["이름1", "이름2", "이름3", "이름4", "이름5"];
		for($i=0; $i<10; $i++) {
			echo "
				<tr>
					<td>myarray[$i]</td>
					<td>나이</td>
				</tr>
			"
		}
	?>
</table>