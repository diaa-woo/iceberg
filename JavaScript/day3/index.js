let myLeads = [];
const inputEl = document.getElementById('input-el');
const inputBtn = document.getElementById('input-btn');
const ulEl = document.getElementById('ul-el');
const deleteBtn = document.getElementById('delete-btn');
const tabBtn = document.getElementById('tab-btn');
const testP = document.getElementById('test');
const leadsFromLocalStorage = JSON.parse(localStorage.getItem("myLeads"));

if (leadsFromLocalStorage) {
    myLeads = leadsFromLocalStorage;
    render();
}

inputBtn.addEventListener("click", function() {
    myLeads.push(inputEl.value);
    inputEl.value = '';
    localStorage.setItem("myLeads", JSON.stringify(myLeads))
    render();
})

deleteBtn.addEventListener("dblclick", function() {
    myLeads = [];
    testP.textContent = myLeads;
    localStorage.clear();
    render();
})

tabBtn.addEventListener("click", function() {
    chrome.tabs.query({active: true, lastFocusedWindow: true}, tabs => {
        let url = tabs[0].url;
        myLeads.push(url);
        localStorage.setItem("myLeads", JSON.stringify(myLeads));
        render();
    });
})

function render() {
    let listItems = "";
    for(let i = 0; i<myLeads.length; i++) {
        listItems += `
            <li><a href = '${myLeads[i]}' target="_blank">${myLeads[i]}</li>
        `
    }
    ulEl.innerHTML = listItems;
}
