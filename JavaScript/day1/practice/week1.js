var result = 0;  //var vs let

function go() {
    var value1 = document.getElementById("value").value;
    var first = document.getElementById("first").value;
    var second = document.getElementById("second").value;
    switch(first) {
        case 'm':
            switch(second) {
                case 'cm': 
                    result = value1 * 100;
                    break;
                case 'inch': 
                    result = value1 * 39.37;
                    break;
                case 'yard': 
                    result = value1 * 1.094;
                    break;
            }
            break;
        case 'cm':
            switch(second) {
                case 'm': 
                    result = value1 / 100;
                    break;
                case 'inch': 
                    result = value1 / 2.54;
                    break;
                case 'yard': 
                    result = value1 / 91.44;
                    break;
            }
            break;
        case 'inch':
            switch(second) {
                case 'cm': 
                    result = value1 * 2.54;
                    break;
                case 'm': 
                    result = value1 / 39.34;
                    break;
                case 'yard': 
                    result = value1 / 36;
                    break;
            }
            break;
        case 'yard':
            switch(second) {
                case 'cm': 
                    result = value1 * 91.44;
                    break;
                case 'm': 
                    result = value1 / 1.094;
                    break;
                case 'inch': 
                    result = value1 * 36;
                    break;
            }
            break;
    }
    document.getElementById("result").textContent = "result: " + result + second;
}
