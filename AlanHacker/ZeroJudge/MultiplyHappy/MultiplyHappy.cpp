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
/*�Q�λ��j���_input / 10�A�b�̫�input <= 10 ���ɭ�
�N�nproduct���W�u�ѭӦ�ƪ�input�åBreturn*/
    if(input <= 10) {
        return product * input;
    } else {
        return multiply(input / 10, product * (input % 10));
    }
}
