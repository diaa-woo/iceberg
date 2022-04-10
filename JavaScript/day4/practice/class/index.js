class Player {
    constructor(name, country) {
        this.name = name;
        this.country = country;
    }

    printPlayer() {
        console.log(`${this.name} was born in ${this.country}`);
    }
}

class TennisPlayer extends Player{
    constructor(name, age) {
        super(name);
        this.age = age;
    }

    printPlayer(name, age) {
        console.log(`${this.name} is ${this.age} years old and knows how to play Tennis`);    
    }
}

let player = new Player('Jessy', 'Chicagp');
player.printPlayer();
let tennisPlayer1 = new TennisPlayer('key', 43);
tennisPlayer1.printPlayer();