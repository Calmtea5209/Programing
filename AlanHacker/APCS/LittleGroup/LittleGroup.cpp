#include <iostream>

/*
請注意，本程式刻意使用遞迴解，所以不確定在人數變大時的答案及執行效率是否能維持，日後仍需除錯
*/

using namespace std;

int number;
int countLittleGroup(int* group, int amount, int times);

int main()
{
    cin >> number;

    int* group = new int[number]; //宣告內含陣列的指標

    for(int i = 0; i < number; i++) {
        cin >> group[i];
    }

    cout << countLittleGroup(group , 0, 0);

    delete[] group; //釋放該陣列的記憶體
    return 0;
}

int countLittleGroup(int* group, int amount, int times) {
    if(group[number - 1] == -1) {//group陣列內所有元素均變成-1時，回傳當前加總的值
        return amount + 1;
    } else {
        if(group[times] == -1) {//判斷當前索引值所指到的元素是否為-1
            amount = amount + 1;//是則amount + 1
            for(int i = 0; i < number; i++) {
                //並且重頭選擇索引值最小的非-1元素索引
                if(group[i] != -1) {
                    times = group[i];
                    break;
                }
            }
        } else {//如果當前的元素不是-1
            //使times指定到下一個元素索引，並將當前元素設為-1
            int cache = group[times];
            group[times] = -1;
            return countLittleGroup(group, amount, cache);
        }
        return countLittleGroup(group, amount, times);
    }
}
