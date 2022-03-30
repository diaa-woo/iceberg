let possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
let text = '';
let count = 0;
let select = 'select';
let pw = [];

function randPW() {
    text = '';
    select = 'select';
    count++;
    let randomNumber = Math.floor(Math.random() * 8) + 8;
    for( let i= 1; i < randomNumber; i++ )
    text += possible.charAt(Math.floor(Math.random() * possible.length));
    select += count;
    pw[count] = text;
    document.getElementById(select).textContent = text;
}

function clip(idNum) {
    let count1 = idNum;
    navigator.clipboard.writeText(pw[count1]);
}
