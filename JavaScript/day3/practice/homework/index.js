let myLeads = [];
const externBtn = document.getElementById('extern-btn');
const internBtn = document.getElementById('intern-btn');
const steamBtn = document.getElementById('steam-btn');
const resetBtn = document.getElementById('reset-btn');
const ulEl = document.getElementById('ul-el');
const resultEL = document.getElementById('result-el');
let total = 0;

externBtn.addEventListener('click', function() {
    total += 30000;
    myLeads.push('차량 외부 손세차 30000원');
    render();
});

internBtn.addEventListener('click', function() {
    total += 40000;
    myLeads.push('차량 내부 손세차 40000원');
    render();
});

steamBtn.addEventListener('click', function() {
    total += 20000;
    myLeads.push('스팀 세차 20000원');
    render();
});

resetBtn.addEventListener('click', function() {
    total = 0;
    myLeads = [];
    render();
});

function render() {
    let listItems = "";
    for(let i = 0; i<myLeads.length; i++) {
        listItems += `
            <li>${myLeads[i]}</li>
        `
    }
    ulEl.innerHTML = listItems;
    resultEL.textContent = `총원: ${total}원`;
}

