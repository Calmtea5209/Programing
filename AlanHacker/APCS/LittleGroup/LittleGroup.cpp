#include <iostream>

/*
�Ъ`�N�A���{����N�ϥλ��j�ѡA�ҥH���T�w�b�H���ܤj�ɪ����פΰ���Ĳv�O�_������A��ᤴ�ݰ���
*/

using namespace std;

int number;
int countLittleGroup(int* group, int amount, int times);

int main()
{
    cin >> number;

    int* group = new int[number]; //�ŧi���t�}�C������

    for(int i = 0; i < number; i++) {
        cin >> group[i];
    }

    cout << countLittleGroup(group , 0, 0);

    delete[] group; //����Ӱ}�C���O����
    return 0;
}

int countLittleGroup(int* group, int amount, int times) {
    if(group[number - 1] == -1) {//group�}�C���Ҧ��������ܦ�-1�ɡA�^�Ƿ�e�[�`����
        return amount + 1;
    } else {
        if(group[times] == -1) {//�P�_��e���ޭȩҫ��쪺�����O�_��-1
            amount = amount + 1;//�O�hamount + 1
            for(int i = 0; i < number; i++) {
                //�åB���Y��ܯ��ޭȳ̤p���D-1��������
                if(group[i] != -1) {
                    times = group[i];
                    break;
                }
            }
        } else {//�p�G��e���������O-1
            //��times���w��U�@�Ӥ������ޡA�ñN��e�����]��-1
            int cache = group[times];
            group[times] = -1;
            return countLittleGroup(group, amount, cache);
        }
        return countLittleGroup(group, amount, times);
    }
}
