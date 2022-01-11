# ROS란?
<style>
    p {
        margin: 15px;
    }
    li {
        margin-left: 15px;
    }
    b {
        font-size: 16px;
    }
    #container1 {
        font-size: 16px;
    }
</style>

## ROS 소개
<p>ROS(Robot Operating System)은 로봇 응용 프로그램을 제작하는 메타 운영체제이며, 다음과 같은 기능을 제공한다.</p>
<ol>
    <li>하드웨어 추상화(Hardware abstraction)</li>
    <li>저수준 디바이스 제어(low-level device control)</li>
    <li>일반적으로 사용되는 기능의 구현(implementation of commonly-used functionality)
    <li>프로세스간의 메시지 패싱(message-passing between processes)</li>
    <li>패키지 관리(package management)</li>
</ol>
<p>다른 로봇 프레임워크와는 달리, 이 프레임워크는 <b>오픈 소스</b>이며, 여러 운영체제와 많은 프로그래밍 언어를 지원하고 있다. 다만 이 운영체제는 <b>우분투(Ubuntu)</b> 운영체제를 기반으로 만들어져, 가장 원활하고 문제없이 돌아가는 운영체제는 우분투와 우분투 기반의 리눅스 민트 운영체제이다. 또한 유닉스 계열 외의(Windows 제외) 운영체제들은 지원을 하지 않는 것으로 보인다.</p>
<p>:sparkles: 로봇 프레임워크 종류</p>
<ul>
    <li>Player</li>
    <li>YARP</li>
    <li>Orocos</li>
    <li>CARMEN</li>
    <li>Orca</li>
    <li>MOOS</li>
    <li>Microsoft Robotics Studio</li>
</ul>

## ROS 특징
<p>ROS는 많은 기능과, 강력한 툴을 제공하는 것이 최종 목적이 아니다. 이 프레임워크는 코드 재사용이 가능한 협업 중심의 프레임워크이다. ROS는 분산 프레임워크로써, 프로세스를 쉽게 공유 및 배포하고, 이를 패키지 혹은 스택으로 그룹화시켜 줄 수 있다. ROS는 그외 다음과 같은 특징을 가지고 있다.
<ul>
    <li><b>얇게(Thin):</b> ROS는 최대한 가볍게 설계되었다. 이 프레임워크는 main()으로 매핑하지 않기에, ROS에서 작성한 코드를 다른 로봇 소프트웨어 프레임워크에서도 동작한다. (이미 OpenRAVE, Orocos 및 Player와 통합함)</li>
    <li><b>ROS에 종속되지 않은 라이브러리(ROS-agnostic libraries):</b> 선호되는 개발 모델을 깨끗한 인터페이스로 ROS에 종속되지 않은 라이브러리를 작성함</li>
    <li><b>언어 독립성(Language independence):</b> ROS 프레임워크는 모든 최신 프로그래밍 언어로 구현이 쉽다. Python 및 C++로 Lisp에서 이미 구현했으며, Java 및 Lua로 실험 라이브러리를 제공함</li>
    <li><b>쉬운 테스트(Easy testing):</b> ROS에는 <i>rostest</i>라는 단위/통합 테스트 프레임워크가 내장되어 있어 테스트 픽스터를 쉽게 시작, 해체할 수 있음</li>
    <li><b>확장성(Scaling):</b> ROS는 대규모 런타임 시스템과 대규모 개발 프로세스에 적합하다.
</ul>
<div id="container1">
    <p>:sparkles: 용어 정리</p>
</div>
<ul>
    <li><b>Lisp: </b>MIT에서 개발한 2번째 고급 프로그래밍 언어(맨 처음 고급 언어는 포트란(Fortran)) 오랫 역사와 독특하게 괄호를 쓰는 것이 특징이며, 본래 실용적인 목적 아래 컴퓨터 프로그램을 활용하여 수학 표기법을 나타내기 위한 목적으로 만들어졌다. (인공지능 연구소에서 유명한 언어이기도 함) 이 언어를 활용해서 <b>트리 자료구조, 쓰레기 수집(Garbage collecter), 동적 자료형, 인터프리터</b>같은 개념들을 만들어 내었다.</li>
    <li><b>Lua:</b> 가벼운 명령형/절차적 프로그래밍 언어로 확장 언어로 쓰일 수 있는 스크립팅 언어를 주 목적으로 설계되었다. 인터프리터 형식으로 작동되고, 굉장히 작기 대문에 많은 플랫폼에서 사용될 수 있다.(유명한지는 글쎄...)
</ul>

## 출처

<ul>
    <li><b><a href="http://wiki.ros.org/ROS/Introduction">ROS wiki(공식)</a></b>
    <li><b><a href="https://ko.wikipedia.org/wiki/%EB%A1%9C%EB%B4%87_%EC%9A%B4%EC%98%81_%EC%B2%B4%EC%A0%9C">ROS 위키백과(위랑 다름)</a></b>
    <li><b><a href="https://ko.wikipedia.org/wiki/%EB%A6%AC%EC%8A%A4%ED%94%84">Lisp</a></b>
    <li><b><a href="https://ko.wikipedia.org/wiki/%EB%A3%A8%EC%95%84_(%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D_%EC%96%B8%EC%96%B4)">Lua</a></b>