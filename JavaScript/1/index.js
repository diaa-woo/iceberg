//document.getElementById("count-el").innerText = 5;  //innerText vs outerText
console.log("hi");

//variable
let a = 3;
console.log(a);

//char variavle
let b = 'c';
console.log(b);

//add between variable
let c = 5;
let d = 7;
console.log(c+d);

//add String variable 
let studentID = '2315';
let studentName = 'name';
console.log(studentID+studentName);

//count
let count = 0;
console.log(++count)
let count2 = 0;
count2++;
console.log(count2)

// Augmented assignment
let count3 = 0;
count3 += 2;  
console.log(count3);

//call function
function raise() {
    count++;
}
raise();
console.log(count);

// add integer and character
let e = 4; // change ingeger -> character
let f = '3';
console.log(e+f); 


// button click event
let cnt = 0;
let history = 'history: ';
function increase() {
    cnt++;
    console.log('clicked!');
    document.getElementById("count-el").innerText = cnt;
}

//button
function reset() {
    cnt = 0;
    document.getElementById("count-el").innerText = cnt;
}


function save() {
    history += cnt + ' - ';
    document.getElementById("count-el").innerText = 0;
    document.getElementById("history").textContent = history;
    cnt = 0;
}