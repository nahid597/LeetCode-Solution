const obj = {
    name: "Nahid",
    age: 27,
    address: {
        house: 39,
        road: 11,
        sector: 13
    },
    phone: "01867083536"
};


function flatObject(obj={}) {
    let flatObj = {};

    for(let ob in obj) {
        if(typeof obj[ob] !== 'object') {
            flatObj[ob] = obj[ob];
        } else {
            let temp = flatObject(obj[ob]);
            for(let to in temp) {
                flatObj[ob+'.'+to] = temp[to];
            }
        }
        
    }

    return flatObj;

}

let ob = flatObject(obj);

console.log(ob);