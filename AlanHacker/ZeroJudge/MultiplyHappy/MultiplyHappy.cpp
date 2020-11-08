#include <iostream>

using namespace std;

int multiply(int input, int product);

int main()
{
    int times;
    int input;

    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        cout << multiply(input, 1) << endl;
    }
    return 0;
}

int multiply(int input, int product) {
/*利用遞迴不斷input / 10，在最後input <= 10 的時候
將積product乘上只剩個位數的input並且return*/
    if(input <= 10) {
        return product * input;
    } else {
        return multiply(input / 10, product * (input % 10));
    }
}
