let cards = [];
let isAlived = true;
let hasBlackjack = false;
let message = '';
let messageEl = document.getElementById('message-el');
let sum = 0;
//let sumEl = document.getElementById('sum-el');
let cardEl = document.getElementById('card-el'); 
let sumEl = document.querySelector('#sum-el');  //getElementById과 기능 같음

let player = {  //Object
    playerName: "황우석",
    playerChip: 145,
}
let playerEl = document.getElementById('player-el');
playerEl.textContent = player.playerName + ": $" + player.playerChip;

function startGame() {
    let firstCard = getRandomCard();
    let secondCard = getRandomCard();
    cards = [firstCard, secondCard];
    sum = firstCard + secondCard;
    isAlived = true;
    renderGame();
}

function renderGame() {
    sumEl.textContent = "Sum: " + sum;

    cardEl.textContent = "Cards: ";
    for(let i = 0; i<cards.length; i++) {
        cardEl.textContent += cards[i] + ' ';
    }

    if(sum < 21) message = 'You want more?';
    else if(sum === 21) {
        hasBlackjack = true;
        message = 'blackjack!';
    }
    else {
        isAlived = false;
        message = 'lose...';
    }

    messageEl.textContent = message;
}

function newCard() {
    if(isAlived === true && hasBlackjack === false) {
        let card = getRandomCard();
        cards.push(card);
        sum += card;
        renderGame();
    }
    else return;
}

function getRandomCard() {
    let randomNumber = Math.floor(Math.random() * 13) + 1;  //소수점 날려줌
    if(randomNumber === 1) return 11;
    if(randomNumber > 10) return 10;
    return randomNumber;
}