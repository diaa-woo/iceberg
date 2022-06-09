import logo from "../img/schl/bssm-h/main/logo.png"

export default function Header() {
    return (
        <div class="area_header">
            <header class="Header">
                <a href="http://bssm.hs.kr" target="_self">
                    <img src={logo} alt="부산소프트웨어마이스터고등학교"/>
                </a>
                <div class="top_menu">
                    <ul>
                        <li><a href="http://bssm.hs.kr" target="_self">홈</a></li>
                        <li><a href="https://school.busanedu.net/bssm-h/lo/login/loginPage.do" title="로그인">로그인</a></li>
                        <li><a href="https://school.busanedu.net/bssm-h/sb/sbscrb/insertSbscrbInfo01.do" title="회원가입">회원가입</a></li>
                        <li><a href="/bssm-h/sitemap.do" title="사이트맵">사이트맵</a></li>
                    </ul>
                </div>
                <input type="text" class="header--input"></input>
            </header>
        </div>
    );
}