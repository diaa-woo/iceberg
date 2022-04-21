//ReactDOM.render(<div><h1>Hello World! <h1>no god please</h1></h1></div>, document.getElementById('root'));

/*
const item = 
    <div>
        <h1>Hello World!</h1>
        <h1>Everybody</h1>
    </div>

ReactDOM.render(item, document.getElementById('root'));
*/

function Header() {
    return (
        <header>
            <nav>
                <img src='' width='300px' alt='hello'></img>
            </nav>
        </header>
    )
}

function Main() {
    return (
        <div>
            <ul>
                <li>wow</li>
                <li>plaese</li>
            </ul>
        </div>
    )
}   

function Footer() {
    return (
        <footer>

        </footer>
    )
}

function Page() {
    return(
        <div>
            <Header/>
            <Main/>
            <Footer/>
        </div>
    )
}

ReactDOM.render(<Page/>, document.getElementById('root'));