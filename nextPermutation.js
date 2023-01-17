var nextPermutation = function (nums) {
   var n = nums.length;

   var pointInd = n - 1;

   while(pointInd >= 1 && nums[pointInd] <= nums[pointInd-1]) {
     pointInd--;
   }

   pointInd = pointInd -1;

   if(pointInd >= 0) {
      var j = n - 1;
      while(j >=0 &&  nums[j] <= nums[pointInd]) {
        j--;
      }

      swap(nums, pointInd, j);
   }

   reverse(nums, pointInd+1);

   return nums;
   
};

function swap(nums, i, j) {
    var temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
};

function  reverse(nums, start) {
   var end = nums.length-1;
   
   while(start < end) {
    swap(nums, start, end);
    start++;
    end--;
   }
}


var nums = [4,3,2,1];

var res = nextPermutation(nums);
console.log(res);
