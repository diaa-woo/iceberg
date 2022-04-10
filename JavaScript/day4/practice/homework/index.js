let buttonEl = document.getElementById('button-el');
let colorEl = document.getElementById('color-el');
let color = '#';
let buffer = 0;

buttonEl.addEventListener('click', function() {
    color = '#';
    for(let i = 0; i<6; i++) {
        buffer = Math.floor(Math.random() * 15) + 1;
        if(buffer >= 10) {
            switch(buffer) {
                case 10:
                    buffer = 'A';
                    break;
                case 11:
                    buffer = 'B';
                    break;
                case 12:
                    buffer = 'C';
                    break;
                case 13:
                    buffer = 'D';
                    break;
                case 14:
                    buffer = 'E';
                    break;
                case 15:
                    buffer = 'F';
                    break;
            }
        }
        color += buffer;
    }
    colorEl.textContent = color;
    document.body.style.backgroundColor = color;
})