# User Control Command 1

## Commands

### passwd
passwd [option] 사용자 : <br>

 - 등록된 사용자(User) 암호지정 또는 변경
   - passwd 사용자 : 사용자(User) 계정의 패스워드 설정
   	 - ex) passwd hseok : hseok 계정의 패스워드를 설정함
   - Enter new password : 새로운 패스워드 입력
   - Retype new password : 재입력
 - d : 사용자 패스워드 제거, 패스워드 없이 로그인 가능
   - ex) passwd -d  : hseok 계정의 패스워드 제거
 - e : 다음 로그인시에 반드시 패스워드를 변경하도록 설정(일종의 알림)
   - ex) passwd -e : hseok 계정이 다음 로그인시 반드시 패스워드를 설정시킴
 - i : 패스워드 기간이 만료되고 나서 로그인 불가능 해지기 전까지의 기간 설정
   - ex) passwd -i (기간)
 - l : 패스워드에 잠금을 걸어 로그인을 막음
   - ex) passwd -l : (로그인 시) 안 돼, 돌아가 어림도 없어
 - n: 패스워드 변경 시 최소로 사용해야되는 날짜 수, 최소 날짜가 지나면 패스워드 변경 가능
   - ex) passwd -n (기간)
 - S: 패스워드 정보
   - 출력되는 정보들
	 1. 사용자명
	 2. 패스워드 상태
	    - P : 정상
		- NP : 패스워드 없음
		- L : 패스워드 잠김
	 3. 패스워드 최근 변경 날짜
	 4. 패스워드 변경 후 최소 유지일
	 5. 패스워드 만기일
	 6. 패스워드 만기전 경고일
	 7. 패스워드 만기 후 계정 사용 불가능까지의 유효기간. 
 - u: 패스워드 잠금 해제
	 - ex) passwd -u hseok : hseok의 패스워드 잠금 해제
 - w: 패스워드 만료전 경고날짜 지정
	 - ex) passwd -w 2021.05.06 hseok : 2021년 5월 6일에 만료 경고 출력
 - x: 패스워드 유효기간 설정
	 - ex)passwd -x

### su
su [option] [사용자] :
     -Substitute User의 약어
     -로그인되어 있는 상태에서 다른 사용자 권한으로 shell 실행
     -옵션을 넣지 않고 사용시 로그인된 사용자 환경변수값을 가져 다른 사람의 권한만 갖음.
     -root 계정은 관리자 계정이기에 암호 입력 X
	- -, -l : 실제 로그인 한것 처럼 shell 이용 가능
		ex) su -l hseok2 : hseok 계정이 로그인 된 상태에서 hseok2 계정 권한으로 shell 실행

### usermod
usermod [option] [사용자] : 
     -사용자 계정을 관리하는 명령어.
     -옵션
	-a : (-G와 같이 사용) 기존 2차 그룹외에 추가로 2차 그룹을 지정할 때 사용
		ex) usermod -G -a (그룹 이름) hseok: hseok 계정을 2차 그룹 (그룹 이름)에 새로 지정
	-c : 사용자의 간단한 정보를 입력 또는 변경
		ex) usermod -c (입력, 변경할 정보)
	-d : 홈 디렉터리 변경 (변경된 디렉터리는 미리 생성되어야 함.)
		ex) usermod -d (홈 디렉터리 이름)
	-e : 계정 만기일 변경
		ex) usermod -e (만기일 변경 날짜)
	-f : 패스워드 만기일이 지난 후 패스워드의 유예기간 지정
		ex) usermod -f (유예기간일수)
	-g : 사용자 그룹 변경
		ex) usermod -g (그룹 이름)
	-G : 2차 그룹 지정
		ex) usermod -G (2차 그룹 이름)
	-l : 사용자 아이디
		ex) usermod -l (변경할 아이디 명)
	-L : 패스워드에 lock을 걸어 로그인 통제
		ex) usermod -L
	-m : (-d 와 함께 사용)홈 디렉터리 변경시 기존에 사용하던 파일을 옮겨줌
		ex) usermod -d (디렉터리 이름) -m

계정 권한: 

cat /etc/group: 계정 리스트 출력
cat /etc/passwd: 사용자 ID를 주소로 한 시스템 계정들 전부 출력
	ex) hseok:x:1002:567::/home/hseok:/bin/bash
		1. 사용자 ID(username)(시스템은 ID로 계정을 구분하지 않음!)(hseok)
		2. 암호화 된 패스워드: 리눅스는 일방향 해시함수와 솔팅 기법을 이용해 패스워드를 저장
			-> /etc/passwd 파일은 모든 사용자가 이 파일을 읽을 수 있는 권한을 지님(보안에 취약)
			-> 그래서 /etc/shadow 프로그램에 따로 저장
			-> (x)로 저장
		3. uid: 시스템이 사용자를 식별하기 위한 ID
			-> 일반 사용자는 1000부터 시작하여 할당하고, 0~1000은 root(super user)계정을 의미함
			-> 만약 root 권한을 주지 않았는데도 uid의 필드값이 0으로 지정 되어 있으며 반드시 재설정
			-> 1002(root 권한 주기 전)
		4. gid: 시스템이 그룹을 식별하기 위한 ID
			-> uid와 마찬가지로 0~1000은 root group, 1000부터는 일반 사용자에게 할당한다.
			-> 이 필드값은 메인 그룹만 담고 있기에, 자세한 그룹 내용은 /etc/group 파일을 실행 시켜야함
			-> 567(다만 이전에 user를 만들때 임의의 그룹 567을 설정해 두었기에 그대로 설정됨)
		5. comment: 주석
			-> 일종의 메모. 공백으로 두어도 무관함
			->::
		6. home_directory: 계정이 저장된 홈 디렉토리
			-> /home/hseok:/bin/bash