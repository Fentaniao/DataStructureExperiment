/*7.3  散列查找算法的实现
【实验目的】
1.掌握如何通过散列函数构建散列表
2.了解散列函数的选择方法及冲突解决的常用方法
3. 能根据关键码，用同样的散列函数和冲突处理方法来进行查找
【实验内容】
已知散列函数为H(key)=key%p（p为自定的常数），冲突处理方法为线性探测再散列或链地址法，构造散列表
【实验要点及说明】
注意散列表时相同元素的处理。
*/

//自有库
#include "PowerTrace.h"

//库
#include <iostream>


using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

const int MAXINT = 32767;

typedef int status;
typedef int keyType;
typedef int infoType;
# define m 20
typedef struct{ keyType key ; infoType otherinfo;
}HashTable[m];