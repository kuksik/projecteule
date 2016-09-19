function factorial(number){
  let res = 1;
  for (let i=2; i<=number; i++) {
    res *= i;
  }
  return res;
}

let numbers  = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
let combination = '';
let position =0;

while (numbers.length) {
  for (let i=0; i<numbers.length; i++) {
    if ( position + factorial(numbers.length - 1) >= 1000000) {
      combination = combination + numbers[i];
      numbers.splice(i, 1);
      break;
    }
    else {
      position = position + factorial(numbers.length - 1);
    }
  }
}

// factorials = 2 6 24 120 720 5040 40320 362880
// 0123456789

 
// 0|123456789
// 362880
// 01|23456789
// 362880 + 362880 = 725760

// 2

// 0|13456789
// 725760+ 40320 = 766080
// 01|3456789
// 725760+ 40320 + 40320 = 806400
// 013|456789
// 725760+ 40320 + 40320 + 40320 = 846720
// 0134|56789
// 725760+ 40320 + 40320 + 40320 + 40320 = 887040
// 01345|6789
// 725760+ 40320 + 40320 + 40320 + 40320 + 40320 = 927360
// 013456|789
// 725760+ 40320 + 40320 + 40320 + 40320 + 40320 + 40320 = 967680

// 27

// 0|1345689
// 96768 + 5040 = 972720
// 01|345689
// 96768 + 5040 + 5040= 977760
// 013|45689
// 96768 + 5040 + 5040 + 5040 = 982800
// 0134|5689
// 96768 + 5040 + 5040 + 5040 + 5040 = 987840
// 01345|689
// 96768 + 5040 + 5040 + 5040 + 5040 + 5040 = 992880
// 013456|89
// 96768 + 5040 + 5040 + 5040 + 5040 + 5040 + 5040 = 997920

// 278

// 0|134569
// 997920 + 720 = 998640
// 01|34569
// 997920 + 720 = 999360

// 2783

// 0|14569
// 999360 + 120 = 999480
// 01|4569
// 999360 + 120 + 120 = 999600
// 014|569
// 999360 + 120 + 120 + 120 = 999720
// 0145|69
// 999360 + 120 + 120 + 120 + 120 = 999840
// 01456|9
// 999360 + 120 + 120 + 120 + 120 + 120 = 999960

// 27839

// 0|1456
// 999960 + 24 = 999984

// 278391

// 0|456
// 999984 + 6 = 999990
// 04|56
// 999984 + 6 + 6 = 999996

// 2783915 

// 0|46
// 999996 + 2 = 999998

// 27839154

// 0|6 
// 999998 + 1 = 999999
// 06|
// 999998 + 1 + 1 = 1000000

// 2783915460