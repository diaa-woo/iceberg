let pEl = document.getElementById('game');

function game() {
    let rand = Math.floor(Math.random() * 3);
    switch(rand) {
        case 0:
            pEl.textContent = 'rock';
            break;
        case 1:
            pEl.textContent = 'scissor';
            break;
        case 2:
            pEl.textContent = 'paper';
            break;
    }
}

