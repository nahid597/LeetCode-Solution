var permuteUnique = function (nums) {
  if (nums.length === 1) {
    return [nums];
  }

  var result = [];
  var curNumCheck = [];

  for (let i = 0; i < nums.length; i++) {
    const curNum = nums[i];
   

    if(curNumCheck[curNum] == 100)
      continue;

    const remainNums = nums.slice(0, i).concat(nums.slice(i + 1));

    const remainNumsPer = permuteUnique(remainNums);

    for (let j = 0; j < remainNumsPer.length; j++) {
      const perArray = [curNum].concat(remainNumsPer[j]);

      curNumCheck[curNum] = 100;
      result.push(perArray);

    }
  }

  return result;
};



var nums = [1, 1, 5];

var res = permuteUnique(nums);
console.log(res);
