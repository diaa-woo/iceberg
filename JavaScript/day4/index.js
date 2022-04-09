//Distructuring Objects
const player = {
    name: 'Lebron James',
    club: 'LA Lakers',
    address: {
        city: 'Los Angeles'
    }
};
console.log(player.address.city);

const {name, club, address: {city}} = player;
console.log(`${name} plays for ${club}`);
console.log(`${name} lives in ${city}`);

//Distructuring Objects
//let fullName = ['Seongho', 'Cho'];
//console.log(fullName[1]);
let [firstName, lastName] = ['Seongho', 'Cho'];
lastName = 'Kim';
console.log(lastName);

//Object Literal
function addressMaker(city, state) {
    //const newAddress = {city: city, state: state}
    const newAddress = {city, state}
    console.log(newAddress);
}

addressMaker('Austin', 'Texas');

//For of Loops
let income = [62000, 67000, 75000];
let total = 0;

for(const incomes of income) {
    console.log(incomes);
    total += income;
}

console.log(total);

let truth = "BSSM is oe of the best schools in Busan!";
for(const char of truth) {
    console.log(char);
}

//Spread Operator
let bestFriends = ['Mary', 'Joel', 'Danny'];
//let friends = ['David', 'Mary', 'Joel', 'Danny', 'Luke'];
let friends = ['David',...bestFriends, 'Luke'];
console.log(friends);

bestFriends.push('John');
console.log(bestFriends);
console.log(friends);

let person = {
    name: 'Adam',
    age: 25
}

let employee = {
    ...person,
    salary: 5000,
    job: "Software Programmer"
}
console.log(employee);

//Rest Operator
function add(...num) {
    console.log(num);
}

add(1,2,3,4,5,4,1,2,4,6);

//Arrow Functions
//Function declaration
function breakfastMenu(food) {
    return `I'm going to ${food} for breakfast!`;
}

console.log(breakfastMenu('Salary'));

//anonymous function
const lunchMenu = function(food) {
    return `I'm going to ${food} for breakfast!`;
}
console.log(lunchMenu('pasta'));

/*const dinnerMenu = (food) => {
    return `I'm going to eat ${food} for dinner.`;
}*/
const dinnerMenu = (food) => `I'm going to eat ${food} for dinner`;
console.log(dinnerMenu('Chicken'));

const dinnerMenu2 = (food, drink) => `I'm going to eat ${food} and ${drink} for dinner`;
console.log(dinnerMenu2('Chicken', 'Beer'));

//Include
const array1 = [1,2,3];
console.log(array1.includes(2));
const pets = ['Cat', 'Dog', 'Rat'];
console.log(pets.includes('Rabbit'));

//padStart-padEnd
let example = 'Wah!';

console.log(example.padStart(10, 'W'));
console.log(example.padEnd(10, '!'));

//class
class Animal {
    constructor(type, legs) {
        this._type = type;
        this.legs = legs;
    }

    makeNoise(sound = "Loud Noise") {
        console.log(sound);
    }

    get type() {
        return this._type.toUpperCase();
    }

    set type(newType) {
        if(newType) {
            this._type = newType;
        }
    }
    static return10() {
        return 10;
    }
}

class Cat extends Animal {
    constructor(type, legs, tail) {
        super(type, legs);
        this.tail = tail;
    }
    makeNoise(sound = "Meow") {
        console.log(sound);
    }
}

let cat = new Cat('Sphynx',4, 1);
cat.makeNoise();
let dog = new Animal('shiba inu', 4);
dog.makeNoise('Bark! Bark!');
dog._type = 'Jindo';
console.log(dog._type);
console.log(Animal.return10());

//Promises
const buyFlightTicket = () => {
    return new Promise( (resolve, reject) => {
        setTimeout( () => {
            const error = true;
            if(error) {
                reject("Sorry");
            }
            else {
                resolve("Success");
            }
        }, 3000)
    })
}
buyFlightTicket()
.catch((error) => console.log(error))
.then((success) => console.log(success));

//Fetch
fetch('https://jsonplaceholder.typicode.com/todos/1')
  .then(response => response.json())
  .then(json => console.log(json))

//async await
const photos = [];

async function photoUpload() {
    let uploadStatus = new Promise( (resolve, reject) => {
        setTimeout( () => {
            photos.push('Profile Pic');
            resolve("Photo Uploaded!");
        }, 3000);
    });
    let result = await uploadStatus;
    console.log(result);
    console.log(photos.length);
}
photoUpload();

//sets
const exampleSet = new Set([1,2,3,4,2,1,2,1,3,4]);

exampleSet.add(5);
exampleSet.add(3).add(27);

console.log(exampleSet.delete(5));
console.log(exampleSet.has(27));
console.log(exampleSet);