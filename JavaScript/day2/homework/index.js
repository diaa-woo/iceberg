let possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
let text = '';
let count = 0;
let select = 'select';

function randPW() {
    text = '';
    select = 'select';
    count++;
    let randomNumber = Math.floor(Math.random() * 8) + 8;
    for( let i= 1; i < randomNumber; i++ )
    text += possible.charAt(Math.floor(Math.random() * possible.length));
    select += count;
    document.getElementById(select).textContent = text;
}

function clip(id) {
    let buf = document.getElementBy(id);
    navigator.clipboard.writeText(buf);
}


