var permute = function(nums) {
   
    if(nums.length === 1) {
        return [nums];
    }

    // 123

    var result = [];

    for(let i = 0; i < nums.length; i++) {
        const curNum = nums[i];
        const remainNums = nums.slice(0,i).concat(nums.slice(i+1));

        const remainNumsPer = permute(remainNums);

        for(let j = 0; j < remainNumsPer.length; j++) {
           const perArray = [curNum].concat(remainNumsPer[j]);

           result.push(perArray);
        }
    }

    return result;
    
};

var nums = [1,2,3,4];

var res = permute(nums);
console.log(res);