// Algo No. 6378

var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', (input) => {

    if(input == 0 || input == '0') {
    process.exit();
}

// algo 6738 process
var result = Algo6738(input);

while(result.length > 1){
    result = Algo6738(result);
}
console.log(result);
});

function Algo6738(input){
    var sum = 0;

    for (var value of input) {
        sum += parseInt(value);
    }
    return "" + sum;
}


출처: http://happyleon.tistory.com/ [developer_2nd]
